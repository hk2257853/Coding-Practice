╔══════════════════════════════════════════════════════════════════════════════╗
║              UBER FREIGHT — 1-DAY INTERVIEW CHEAT SHEET                     ║
║              7 Problems · Core Idea · API · Data Structure                  ║
╚══════════════════════════════════════════════════════════════════════════════╝

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
 1. LRU CACHE  (lru_cache.cpp)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

PROBLEM
  Fixed-capacity cache. On overflow, evict the Least Recently Used key.
  Both get and put must be O(1).

API
  get(key)        — return value (-1 if absent); mark key as recently used
  put(key, val)   — insert/update; if over capacity, evict LRU first

CORE IDEA  ► HashMap + Doubly-Linked List (DLL)
my own what's app msg to cayman is best.
for coding note: [ HEAD ] <======> [ TAIL ] (but head->prev and tail->next are null)
ie initialise with this way so that i don't need to many if else or nullptr check.
need to internalise head is not pointing to the nodes now... head.next will be my first node

┌──────────────────────────────────────────────────────────────┐
  │  hashMap : key → Node*  (for O(1) find)                     │
  │  DLL     : HEAD ↔ [MRU ··· LRU] ↔ TAIL  (sentinel nodes)   │
  └──────────────────────────────────────────────────────────────┘

  "Recently used" = front of DLL (after HEAD).
  "Least recently used" = back of DLL (before TAIL).

  get:  hashMap find → splice node to front → return value
  put:  if key exists → update + move to front
        if new:
          if full → remove TAIL.prev (LRU) from DLL + hashMap
          insert new node after HEAD + add to hashMap

  Why DLL and not vector?
    Splice (move to front) and evict (remove tail) need O(1) pointer
    surgery — only possible with both prev AND next pointers.

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
 2. RATE LIMITER — Sliding Window TTL  (rate_limiter_ttl.cpp)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

PROBLEM
  Allow at most `limit` requests per `windowMs` milliseconds per key.
  Not a fixed bucket — a true sliding window (no burst at boundary).

API
  allow(key, now_ms)       — true if allowed; false if throttled
  remaining(key, now_ms)   — how many more requests allowed right now
  reset(key)               — wipe history for a key

CORE IDEA  ► Per-key Deque of timestamps (sliding window)
  ┌──────────────────────────────────────────────────────────────┐
  │  windows : HashMap<key → deque<timestamp>>                   │
  └──────────────────────────────────────────────────────────────┘

  On every allow(key, now):
    1. Pop front of deque while front <= (now - windowMs)  [evict expired]
    2. If deque.size() < limit  → push_back(now), return true
    3. Else                     → return false

  Each timestamp is pushed once and popped once → O(1) amortised.
  Space: O(limit) per key at most (deque never grows past limit).



NOTE: 
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
 3. PLATFORM SCHEDULER  (platform_scheduler.cpp)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

PROBLEM
  N loading docks (platforms). Trucks arrive at time A with duration W.
  Assign truck to the platform that becomes free earliest.
  Tie: pick lower index. Truck may wait; it occupies [A+delay, A+delay+W-1].

API
  assignPlatform(truckId, arrivalTime, waitTime) → "platformIdx,delay"
  getTrainAtPlatform(platformIdx, time)          → truckId or ""
  getPlatformOfTrain(truckId, time)              → platformIdx or -1

CORE IDEA
  ┌──────────────────────────────────────────────────────────────┐
  │  Per platform: map<startTime, Reservation>  (sorted by time) │
  │  truckRegistry: HashMap<truckId → (platformIdx, Reservation)>│
  └──────────────────────────────────────────────────────────────┘

  assignPlatform:
    - Standard: Scan N platforms to find min delay. Tie-break: lower index.  O(N)
    - PQ Version: Min-heap of `(nextFreeTime, platformIdx)`. Pop, update, push. O(log N)
      (Implemented in platform_scheduler_pq.cpp)

  getTrainAtPlatform:
    upper_bound(t) on platform's map → step back one → check interval O(log K)

  getPlatformOfTrain:
    truckRegistry lookup → check if reservation.containsTime(t)       O(1)

  Key insight: map<startTime, Reservation> lets you do "who is here at t?"
  with a single floor (upper_bound - 1) lookup.

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
 4. PARKING LOT LITE  (parking_lot_lite.cpp)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

PROBLEM
  Multi-floor parking lot with SMALL / MEDIUM / LARGE spots.
  A vehicle can only park in its exact size.
  Always assign the "best" (lowest floor → lowest row → lowest col) free spot.

API
  park(vehicleId, size)    — assign best free spot → "floor,row,col" or ""
  leave(vehicleId)         — free the spot, push it back
  query(vehicleId)         — where is this vehicle? → "floor,row,col" or ""
  available(size)          — count of free spots for that size

CORE IDEA  ► One Min-Heap per size + vehicle HashMap
  ┌──────────────────────────────────────────────────────────────┐
  │  freeSpots[3] : min-heap<SpotId>  (one per SMALL/MED/LARGE) │
  │  occupied     : unordered_map<vehicleId → (SpotId, size)>    │
  └──────────────────────────────────────────────────────────────┘
  The Min-Heap (freeSpots) has zero knowledge of vehicles. It is purely a pool of available physical spot coordinates (SpotId structs). Its only job is to serve the nearest free spot (heap.top()).
  The HashMap (occupied) has zero search logic. It is just a directory linking a vehicle's ID to where it is currently parked.

  SpotId compared lex: (floor, row, col) ascending.
  Min-heap top() is always the "best" available spot.

  park:   heap.top() → pop → store in occupied              → O(log S)
  leave:  occupied[id] → push SpotId back to heap           → O(log S)
  query:  occupied[id].SpotId                               → O(1)
  avail:  heap.size()                                       → O(1)

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
 5. KEY-VALUE STORE  (key_value_store.cpp)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

PROBLEM
  A cache/store that supports get, put, delete, AND getRandom — all O(1).
  The getRandom is the twist: you can't do O(1) random on a plain HashMap.

API
  put(key, val)   — insert or overwrite
  get(key)        — return value or null
  remove(key)     — delete the key
  getRandom()     — return any random [key, value] pair with equal probability

CORE IDEA  ► You need TWO structures because no single one gives you everything

  PROBLEM WITH JUST unordered_map:
    get/put/remove are O(1) ✓  but getRandom is O(N) ✗
    unordered_map has no index access — you can't jump to "element at position i"

  PROBLEM WITH JUST vector:
    getRandom is O(1) ✓  but get/put/remove by key are O(N) ✗ (have to scan)

  SOLUTION — keep both, always in sync:

  ┌──────────────────────────────────────────────────────────────────────┐
  │  indexMap : unordered_map<string, int>                               │
  │             key  →  position of that key inside `entries` vector     │
  │             WHY: gives you O(1) "where is this key in the vector?"   │
  │                                                                      │
  │  entries  : vector<pair<string,string>>                              │
  │             a dense, hole-free array of (key, value) pairs           │
  │             WHY: gives you O(1) random access by integer index,      │
  │                  which unordered_map cannot do                       │
  └──────────────────────────────────────────────────────────────────────┘

  get(key):
    indexMap[key]  →  int idx  →  entries[idx].second               O(1)

  put(key, val):
    if key in indexMap → entries[ indexMap[key] ].second = val       O(1)
    else → entries.push_back({key,val}), indexMap[key] = size-1      O(1) amort.

  getRandom():
    int i = rand() % entries.size()  →  return entries[i]           O(1)
    (works because vector is always dense — no gaps, no nulls)

  remove(key)  ►  SWAP-AND-POP  (the only non-obvious part):
    Normal erase from middle of vector = O(N) shifting. Avoid it.
    Instead, since ORDER DOES NOT MATTER, move last element into the gap:
      idx      = indexMap[key]           // where is it in the vector?
      entries[idx] = entries[last]       // overwrite gap with last element
      indexMap[entries[idx].first] = idx // patch last element's map entry
      entries.pop_back()                 // remove now-duplicate tail  O(1)
      indexMap.erase(key)                // clean up deleted key

  Java thread-safety: ReentrantReadWriteLock (just a side note)
    readLock  → get, getRandom  (concurrent reads OK)
    writeLock → put, remove     (exclusive)

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
 6. INVENTORY SYSTEM  (inventory_system.cpp)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

PROBLEM
  Warehouse stock management. Two layers: "available" (free) and "reserved"
  (soft-locked, not yet shipped). Reservations can be confirmed or cancelled.

API
  addStock(sku, qty)           — increase available stock
  removeStock(sku, qty)        — hard-remove from available; false if short
  getStock(sku)                — available (not reserved) qty
  getTotalStock(sku)           — available + reserved
  reserve(sku, qty)            — soft-lock → returns reservationId or ""
  confirmReservation(id)       — finalize: reserved -= qty (goods shipped)
  cancelReservation(id)        — release:  reserved -= qty, available += qty

CORE IDEA  ► Two-counter model + Reservation map, all O(1)
  ┌──────────────────────────────────────────────────────────────┐
  │  Per SKU:  { available: int,  reserved: int }               │
  │  reservations : HashMap<reservId → {sku, qty}>              │
  └──────────────────────────────────────────────────────────────┘

  reserve:  available -= qty,  reserved += qty
  confirm:  reserved  -= qty   (total shrinks — goods left warehouse)
  cancel:   reserved  -= qty,  available += qty  (back to shelf)

  Key insight: total = available + reserved never changes on reserve/cancel,
  only on addStock / removeStock / confirmReservation.

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
 7. IN-MEMORY FILE SYSTEM  (filesystem.cpp)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

PROBLEM
  In-memory FS with directories only. Support absolute and relative paths,
  plus special segments: ".." (parent), "." (stay), "*" (wildcard = lex-first child).

API
  mkdir(path)   — create directories along path (like mkdir -p)
  cd(path)      — change current directory; return false if path invalid
  pwd()         — return absolute path of cwd

CORE IDEA  ► N-ary Tree of nodes + recursive DFS resolver
  ┌──────────────────────────────────────────────────────────────┐
  │  Node: { name, parent*, children: map<name, Node*> }        │
  │  cwd: Node*   (current working directory pointer)           │
  └──────────────────────────────────────────────────────────────┘

  mkdir:  Walk segments from root/cwd; create Node if missing.
  pwd:    Walk parent* pointers up to root; collect names; reverse.
  cd:     resolveSegments(startNode, segments, 0) — recursive DFS:
            "."  → recurse from same node
            ".." → recurse from node.parent (clamp at root)
            "*"  → try each child in map order (sorted = lex); return first hit
            else → exact child lookup

  Why map (not unordered_map) for children?
    map is sorted lexicographically → wildcard "*" naturally picks
    the lex-smallest child without any extra sorting step.

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
 QUICK REFERENCE TABLE
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

  Problem            | Key DS                          | Tricky Part
  ───────────────────┼─────────────────────────────────┼──────────────────────
  LRU Cache          | HashMap + Doubly-Linked List    | sentinel head/tail
  Rate Limiter       | HashMap + Deque<timestamp>      | sliding window evict
  Platform Scheduler | map<time,Res> per platform      | upper_bound floor
  Parking Lot        | Min-Heap per size + HashMap     | SpotId lex compare
  Key-Value Store    | unordered_map + vector          | swap-and-pop delete
  Inventory System   | HashMap (two counters per SKU)  | reserve vs confirm
  File System        | N-ary Tree (map children)       | wildcard DFS

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
 PATTERN YOU'LL SEE EVERYWHERE
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

  "I need O(1) on something a plain HashMap/array can't do alone"
  → Add a second index (array for getRandom, DLL for LRU order, etc.)
  → The two structures mirror each other; keep them in sync on every write.

  "I need to find who owns a time slot at time T"
  → Store start-times as keys in a sorted map → upper_bound(T) - 1 = answer.

  "I need the minimum of a dynamic set"
  → Priority queue (min-heap); push freed items back on release.
