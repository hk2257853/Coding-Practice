/*
 * LRU Cache — O(1) get / put
 *
 * Data Structure: HashMap + Doubly-Linked List (DLL)
 *
 *   hashMap  : unordered_map<int, Node*>
 *                key → pointer to DLL node
 *
 *   dll      : doubly-linked list  [HEAD ↔ ... ↔ TAIL]
 *                HEAD.next = Most Recently Used
 *                TAIL.prev = Least Recently Used
 *
 * Operations:
 *   get(key):
 *     1. Hash lookup → O(1) find node.
 *     2. Move node to front (splice) → O(1).
 *     3. Return value.
 *
 *   put(key, value):
 *     1. If key exists → update value in-place, move to front.
 *     2. If new:
 *        a. If at capacity → evict TAIL.prev (LRU node).
 *        b. Insert new node at HEAD.next (MRU position).
 *
 * Why a doubly-linked list?
 *   Splice (move to front) and evict (remove tail) require
 *   O(1) pointer surgery — only possible with both prev and next pointers.
 *
 * Complexity:
 *   get  O(1)
 *   put  O(1)
 *   Space O(capacity)
 */

#include <iostream>
#include <unordered_map>
#include <stdexcept>

using namespace std;

// ─── Doubly-Linked List Node ──────────────────────────────────────────────────

struct Node {
    int key, value;
    Node* prev = nullptr;
    Node* next = nullptr;

    // Node(int k, int v) : key(k), value(v) {}
    Node(int k, int v) {key = k; value = v;}
};

// ─── LRU Cache ────────────────────────────────────────────────────────────────

class LRUCache {
private:
    int capacity;

    // Sentinel nodes — never store real data.
    // HEAD ↔ [MRU ... LRU] ↔ TAIL
    Node* head;   // dummy head
    Node* tail;   // dummy tail

    // key → Node* for O(1) lookup
    unordered_map<int, Node*> hashMap;

    // ── DLL helpers ──────────────────────────────────────────────────────────

    // Insert `node` immediately after the dummy head (MRU position)
    void insertFront(Node* node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    // Detach `node` from wherever it is (O(1) pointer update)
    void detach(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // Move existing node to MRU position
    void moveToFront(Node* node) {
        detach(node);
        insertFront(node);
    }

    // Remove and return the LRU node (just before the dummy tail)
    Node* evictLRU() {
        Node* lru = tail->prev;
        detach(lru);
        return lru;
    }

public:
    explicit LRUCache(int cap) : capacity(cap) {
        if (cap <= 0) throw invalid_argument("capacity must be > 0");
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    ~LRUCache() {
        Node* cur = head;
        while (cur) {
            Node* nxt = cur->next;
            delete cur;
            cur = nxt;
        }
    }

    /*
     * get(key)
     * Return value if key exists (and mark as recently used), else -1.
     */
    int get(int key) {
        auto it = hashMap.find(key);
        if (it == hashMap.end()) return -1;

        Node* node = it->second;
        moveToFront(node);       // mark as recently used
        return node->value;
    }

    /*
     * put(key, value)
     * Insert or update. Evict LRU entry if over capacity.
     */
    void put(int key, int value) {
        auto it = hashMap.find(key);

        if (it != hashMap.end()) {
            // Key exists: update in-place and move to front
            Node* node = it->second;
            node->value = value;
            moveToFront(node);
            return;
        }

        // New key
        if ((int)hashMap.size() == capacity) {
            // Evict LRU
            Node* lru = evictLRU();
            hashMap.erase(lru->key);
            delete lru;
        }

        Node* newNode = new Node(key, value);
        insertFront(newNode);
        hashMap[key] = newNode;
    }

    int size()  const { return (int)hashMap.size(); }

    // ── Debug: print cache from MRU to LRU ──────────────────────────────────
    void print() const {
        cout << "MRU → ";
        Node* cur = head->next;
        while (cur != tail) {
            cout << "[" << cur->key << ":" << cur->value << "] ";
            cur = cur->next;
        }
        cout << "← LRU\n";
    }
};

// ─── Driver ───────────────────────────────────────────────────────────────────

int main() {
    cout << "=== capacity 3 ===\n";
    LRUCache cache(3);

    cache.put(1, 10);
    cache.put(2, 20);
    cache.put(3, 30);
    cache.print();   // MRU → [3:30] [2:20] [1:10] ← LRU

    cout << "get(1) = " << cache.get(1) << "\n";  // 10, moves 1 to MRU
    cache.print();   // MRU → [1:10] [3:30] [2:20] ← LRU

    cout << "\n=== eviction ===\n";
    cache.put(4, 40);  // evicts LRU = key 2
    cache.print();    // MRU → [4:40] [1:10] [3:30] ← LRU
    cout << "get(2) = " << cache.get(2) << "\n";  // -1 (evicted)

    cout << "\n=== update existing ===\n";
    cache.put(3, 300);   // update key 3, move to MRU
    cache.print();       // MRU → [3:300] [4:40] [1:10] ← LRU

    cout << "\n=== LeetCode 146 classic sequence ===\n";
    LRUCache lc(2);
    lc.put(1, 1);
    lc.put(2, 2);
    cout << lc.get(1)    << "\n";  // 1
    lc.put(3, 3);                  // evict key 2
    cout << lc.get(2)    << "\n";  // -1
    lc.put(4, 4);                  // evict key 1
    cout << lc.get(1)    << "\n";  // -1
    cout << lc.get(3)    << "\n";  // 3
    cout << lc.get(4)    << "\n";  // 4

    return 0;
}
