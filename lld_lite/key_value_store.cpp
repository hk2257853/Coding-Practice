/*
 * Key-Value Store — O(1) put / get / remove / getRandom
 *
 * Dual-Index Structure:
 *   indexMap  : unordered_map<string, int>   key → index in `entries`
 *   entries   : vector<pair<string,string>>  dense list of (key, value)
 *
 * Swap-and-Pop Deletion (O(1)):
 *   1. Look up target index idx via indexMap.
 *   2. Overwrite entries[idx] with entries[back()].
 *   3. Update indexMap for the moved entry.
 *   4. Pop the now-duplicate tail; erase key from indexMap.
 *
 * getRandom O(1):
 *   entries is always dense (no holes), so rand() % size() is uniform.
 *
 * Complexity:
 *   put       O(1) amortised
 *   get       O(1)
 *   remove    O(1)
 *   getRandom O(1)
 *   Space     O(N)
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

using namespace std;

class KeyValueStore {
private:
    // key → position in entries[]
    unordered_map<string, int> indexMap;

    // dense list; entries[i] = {key, value}
    vector<pair<string, string>> entries;

public:
    KeyValueStore() { srand((unsigned)time(nullptr)); }

    /*
     * put(key, value)
     * Insert or overwrite a key.
     * If key exists: update value in-place (O(1), no structural change).
     * If new: append to end, record index (O(1) amortised).
     */
    void put(const string& key, const string& value) {
        if (indexMap.count(key)) {
            entries[indexMap[key]].second = value;  // update in-place
        } else {
            indexMap[key] = (int)entries.size();
            entries.push_back({key, value});
        }
    }

    /*
     * get(key)
     * Return pointer to value, or nullptr if absent.
     * O(1): one hash lookup → one vector access.
     */
    const string* get(const string& key) const {
        // Need find() here — const method, operator[] not available on const map
        auto it = indexMap.find(key);
        if (it == indexMap.end()) return nullptr;
        return &entries[it->second].second;
    }

    /*
     * remove(key)
     * O(1) swap-and-pop:
     *   Move last entry into the deleted slot → pop tail → fix index map.
     */
    bool remove(const string& key) {
        if (!indexMap.count(key)) return false;

        int idx     = indexMap[key];
        int lastIdx = (int)entries.size() - 1;

        if (idx != lastIdx) {
            // Displace last entry into the hole
            entries[idx] = entries[lastIdx];
            indexMap[entries[idx].first] = idx;   // patch moved entry's index
        }

        entries.pop_back();
        indexMap.erase(key);
        return true;
    }

    /*
     * getRandom()
     * Pick a uniformly random live entry.
     * Throws if empty.
     */
    pair<string, string> getRandom() const {
        if (entries.empty())
            throw runtime_error("KeyValueStore is empty");
        int idx = rand() % (int)entries.size();
        return entries[idx];
    }

    int size() const { return (int)entries.size(); }
    bool empty() const { return entries.empty(); }
};

// ─── Driver ───────────────────────────────────────────────────────────────────

int main() {
    KeyValueStore kv;

    cout << "=== put / get ===\n";
    kv.put("ship",  "Maersk");
    kv.put("truck", "Freightliner");
    kv.put("rail",  "BNSF");
    kv.put("air",   "DHL");

    auto print = [&](const string& key) {
        const string* v = kv.get(key);
        cout << key << " -> " << (v ? *v : "NULL") << "\n";
    };

    print("ship");   // Maersk
    print("truck");  // Freightliner
    print("rail");   // BNSF

    cout << "\n=== update in-place ===\n";
    kv.put("ship", "CMA-CGM");
    print("ship");   // CMA-CGM

    cout << "\n=== remove (swap-and-pop) ===\n";
    cout << "size before: " << kv.size() << "\n";  // 4
    kv.remove("truck");
    cout << "size after : " << kv.size() << "\n";  // 3
    print("truck");   // NULL
    print("air");     // DHL (was moved; must still be findable)

    cout << "\n=== getRandom (10 samples) ===\n";
    for (int i = 0; i < 10; i++) {
        auto kv_pair = kv.getRandom();
        cout << "  " << kv_pair.first << " -> " << kv_pair.second << "\n";
    }

    cout << "\n=== remove until empty ===\n";
    kv.remove("ship");
    kv.remove("air");
    kv.remove("rail");
    cout << "size: " << kv.size() << "\n";  // 0
    cout << "get on empty: ";
    print("ship");  // NULL

    return 0;
}
