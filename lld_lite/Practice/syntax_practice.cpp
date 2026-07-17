/*
 * UBER FREIGHT — Syntax you need but DON'T have in cheat_sheet.cpp
 * Compile: g++ -std=c++14 syntax_practice.cpp -o syntax_practice
 *
 * These are the EXACT patterns used across the 7 problems.
 * Run this file, read the output, modify if you want to practice.
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <sstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

// ═══════════════════════════════════════════════════════════════
// 1. ORDERED MAP (map<K,V>) — used in: platform_scheduler, filesystem
//    Unlike unordered_map, keys are sorted. Gives you upper_bound/lower_bound.
// ═══════════════════════════════════════════════════════════════

    cout << "=== 1. ORDERED MAP ===\n";

    map<int, string> schedule;         // keys auto-sorted (ascending)
    schedule[10] = "TruckA";           // occupies time 10
    schedule[20] = "TruckB";           // occupies time 20
    schedule[30] = "TruckC";           // occupies time 30

    // --- iterate (always sorted by key) ---
    for (auto& p : schedule)
        cout << p.first << " -> " << p.second << "\n";

    // --- rbegin(): last element (largest key) ---
    // Used in platform_scheduler to get nextFreeTime
    cout << "Last entry: " << schedule.rbegin()->first
         << " -> " << schedule.rbegin()->second << "\n";   // 30 -> TruckC

    // --- upper_bound(key): first element with key STRICTLY > given key ---
    // Used in platform_scheduler: "who is at the platform at time T?"
    //   upper_bound(T) gives first entry AFTER T
    //   step back by 1  → entry whose start <= T
    int queryTime = 25;
    auto it = schedule.upper_bound(queryTime);  // points to 30
    if (it != schedule.begin()) {
        --it;  // step back → 20
        cout << "At time " << queryTime << ": " << it->second << "\n";  // TruckB
    }

    // --- difference from unordered_map ---
    // unordered_map:  O(1) get/put,  NO ordering, NO upper_bound
    // map:            O(log N) get/put, YES ordering, YES upper_bound
    // Use map ONLY when you need sorted keys or range queries

cout << "\n";

// ═══════════════════════════════════════════════════════════════
// 2. DOUBLY-LINKED LIST (raw pointers) — used in: lru_cache
//    This is the hardest syntax. No STL shortcut — you build it.
// ═══════════════════════════════════════════════════════════════

    cout << "=== 2. DOUBLY-LINKED LIST ===\n";

    // --- Node definition ---
    struct Node {
        int key, val;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };

    // --- Sentinel (dummy) head and tail ---
    // They hold no data. They just make insert/remove code simpler
    // because you never deal with nullptr edge cases.
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    head->next = tail;
    tail->prev = head;

    // --- insertFront: put a node right after HEAD ---
    auto insertFront = [&](Node* node) {
        node->next       = head->next;
        node->prev       = head;
        head->next->prev = node;
        head->next       = node;
    };

    // --- detach: pull a node out of wherever it is ---
    auto detach = [&](Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    };

    // --- demo: insert 3 nodes ---
    Node* n1 = new Node(1, 10);
    Node* n2 = new Node(2, 20);
    Node* n3 = new Node(3, 30);
    insertFront(n1);  // HEAD <-> 1 <-> TAIL
    insertFront(n2);  // HEAD <-> 2 <-> 1 <-> TAIL
    insertFront(n3);  // HEAD <-> 3 <-> 2 <-> 1 <-> TAIL

    // print: traverse from HEAD.next to TAIL
    cout << "After 3 inserts: ";
    for (Node* cur = head->next; cur != tail; cur = cur->next)
        cout << "[" << cur->key << ":" << cur->val << "] ";
    cout << "\n";   // [3:30] [2:20] [1:10]

    // --- moveToFront: detach + insertFront ---
    // This is what "mark as recently used" does in LRU
    detach(n1);
    insertFront(n1);
    cout << "After moveToFront(1): ";
    for (Node* cur = head->next; cur != tail; cur = cur->next)
        cout << "[" << cur->key << ":" << cur->val << "] ";
    cout << "\n";   // [1:10] [3:30] [2:20]

    // --- evictLRU: remove tail->prev (the least recently used) ---
    Node* lru = tail->prev;   // n2
    detach(lru);
    cout << "Evicted LRU key=" << lru->key << "\n";   // 2
    delete lru;

    cout << "After evict: ";
    for (Node* cur = head->next; cur != tail; cur = cur->next)
        cout << "[" << cur->key << ":" << cur->val << "] ";
    cout << "\n";   // [1:10] [3:30]

    // cleanup
    delete n1; delete n3; delete head; delete tail;

cout << "\n";

// ═══════════════════════════════════════════════════════════════
// 3. STRUCT + CUSTOM COMPARATOR FOR MIN-HEAP — used in: parking_lot
//    Your cheat sheet has min-heap with int. But what about custom struct?
// ═══════════════════════════════════════════════════════════════

    cout << "=== 3. CUSTOM STRUCT MIN-HEAP ===\n";

    // --- step 1: define the struct ---
    struct SpotId {
        int floor, row, col;

        // operator> needed for the comparator
        bool operator>(const SpotId& o) const {
            if (floor != o.floor) return floor > o.floor;
            if (row != o.row)     return row   > o.row;
            return col > o.col;
        }
    };

    // --- step 2: define a comparator functor ---
    // For min-heap: return true when a should be BELOW b
    struct MinSpotCmp {
        bool operator()(const SpotId& a, const SpotId& b) {
            return a > b;  // uses operator> above
        }
    };

    // --- step 3: declare the min-heap ---
    priority_queue<SpotId, vector<SpotId>, MinSpotCmp> spotHeap;

    // --- step 4: push some spots ---
    spotHeap.push({1, 0, 2});
    spotHeap.push({0, 0, 0});
    spotHeap.push({0, 1, 0});
    spotHeap.push({0, 0, 3});

    // --- step 5: pop in order ---
    cout << "Spots in min order:\n";
    while (!spotHeap.empty()) {
        SpotId s = spotHeap.top();
        spotHeap.pop();
        cout << "  floor=" << s.floor << " row=" << s.row << " col=" << s.col << "\n";
    }
    // Output:  (0,0,0) → (0,0,3) → (0,1,0) → (1,0,2)

cout << "\n";

// ═══════════════════════════════════════════════════════════════
// 4. STRINGSTREAM — SPLIT STRING BY DELIMITER — used in: filesystem
//    Split "/foo/bar/baz" into ["foo", "bar", "baz"]
// ═══════════════════════════════════════════════════════════════

    cout << "=== 4. STRINGSTREAM SPLIT ===\n";

    string path = "/foo/bar/baz";
    vector<string> tokens;
    stringstream ss(path);
    string token;
    while (getline(ss, token, '/')) {       // split by '/'
        if (!token.empty())                 // skip empty (leading '/')
            tokens.push_back(token);
    }
    cout << "Path: " << path << "\nTokens: ";
    for (auto& t : tokens) cout << "[" << t << "] ";
    cout << "\n";   // [foo] [bar] [baz]

cout << "\n";

// ═══════════════════════════════════════════════════════════════
// 5. ENUM CLASS — used in: parking_lot
// ═══════════════════════════════════════════════════════════════

    cout << "=== 5. ENUM CLASS ===\n";

    enum class Size { SMALL = 0, MEDIUM = 1, LARGE = 2 };

    Size s = Size::SMALL;

    // Can't do: int x = s;       ← error, enum class is type-safe
    // Must cast: int x = (int)s;
    int x = (int)s;
    cout << "Size::SMALL as int = " << x << "\n";   // 0

    // Use as array index:
    int counts[3] = {10, 5, 2};
    cout << "Small count = " << counts[(int)Size::SMALL] << "\n";   // 10

cout << "\n";

// ═══════════════════════════════════════════════════════════════
// 6. DEQUE FOR SLIDING WINDOW — used in: rate_limiter
//    Already in cheat_sheet but you only have basic ops.
//    Here's the actual pattern for sliding window eviction.
// ═══════════════════════════════════════════════════════════════

    cout << "=== 6. DEQUE SLIDING WINDOW ===\n";

    deque<int> window;    // stores timestamps of accepted requests
    int limit = 3;
    int windowSize = 100;

    // Simulate: timestamps 10, 50, 80, 90, 120
    vector<int> timestamps = {10, 50, 80, 90, 120};

    for (int t : timestamps) {
        // EVICT: pop from front while oldest is outside window
        while (!window.empty() && window.front() <= t - windowSize)
            window.pop_front();

        // CHECK: if under limit, allow
        if ((int)window.size() < limit) {
            window.push_back(t);
            cout << "t=" << t << " ALLOW  (window size=" << window.size() << ")\n";
        } else {
            cout << "t=" << t << " DENY   (window size=" << window.size() << ")\n";
        }
    }
    // t=10  ALLOW  (1)
    // t=50  ALLOW  (2)
    // t=80  ALLOW  (3)
    // t=90  DENY   (3)     — 10 not yet expired (90-10=80 < 100)
    // t=120 ALLOW  (3)     — 10 expired (120-10=110 > 100), so evicted

cout << "\n";

// ═══════════════════════════════════════════════════════════════
// 7. SWAP-AND-POP ON VECTOR — used in: key_value_store
//    Delete from middle of vector in O(1)
// ═══════════════════════════════════════════════════════════════

    cout << "=== 7. SWAP-AND-POP ===\n";

    vector<string> items = {"A", "B", "C", "D"};
    unordered_map<string, int> idx;
    for (int i = 0; i < (int)items.size(); i++) idx[items[i]] = i;

    cout << "Before: ";
    for (auto& i : items) cout << i << " ";
    cout << "\n";   // A B C D

    // Delete "B" (at index 1) in O(1):
    string toDelete = "B";
    int delIdx  = idx[toDelete];
    int lastIdx = (int)items.size() - 1;

    if (delIdx != lastIdx) {
        items[delIdx] = items[lastIdx];       // move "D" into slot 1
        idx[items[delIdx]] = delIdx;           // patch "D"'s index
    }
    items.pop_back();
    idx.erase(toDelete);

    cout << "After deleting B: ";
    for (auto& i : items) cout << i << " ";
    cout << "\n";   // A D C
    cout << "idx[D] = " << idx["D"] << "\n";  // 1 (was 3, now patched)

cout << "\n";

// ═══════════════════════════════════════════════════════════════
// 8. N-ARY TREE NODE (raw pointers + map children) — used in: filesystem
//    Each directory node has a name, parent*, and sorted children.
// ═══════════════════════════════════════════════════════════════

    cout << "=== 8. N-ARY TREE ===\n";

    struct TreeNode {
        string name;
        TreeNode* parent;
        map<string, TreeNode*> children;    // sorted by name (lex order)
        TreeNode(string n, TreeNode* p) : name(n), parent(p) {}
    };

    TreeNode* root = new TreeNode("/", nullptr);

    // mkdir /foo/bar — walk + create if missing
    TreeNode* cur = root;
    vector<string> segs = {"foo", "bar"};
    for (auto& seg : segs) {
        if (cur->children.find(seg) == cur->children.end())
            cur->children[seg] = new TreeNode(seg, cur);
        cur = cur->children[seg];
    }
    cout << "Created: /foo/bar\n";
    cout << "cur->name = " << cur->name << "\n";              // bar
    cout << "cur->parent->name = " << cur->parent->name << "\n";  // foo

    // walk up parent pointers (pwd)
    string pwd;
    TreeNode* walk = cur;
    while (walk != root) {
        pwd = "/" + walk->name + pwd;
        walk = walk->parent;
    }
    cout << "pwd = " << pwd << "\n";   // /foo/bar

    // children are sorted (map) — iterate in lex order
    root->children["foo"]->children["aaa"] = new TreeNode("aaa", root->children["foo"]);
    root->children["foo"]->children["zzz"] = new TreeNode("zzz", root->children["foo"]);
    cout << "Children of /foo (sorted): ";
    for (auto& p : root->children["foo"]->children)
        cout << p.first << " ";
    cout << "\n";   // aaa bar zzz

    // cleanup (skipped for brevity)

    return 0;
}
