Viewed CHEATSHEET.md:107-120
Viewed platform_scheduler.cpp:1-185

Here is the simulation of the **Platform Scheduler** (with $N=3$ platforms):

---

### **1. Initialization**
*   **Platforms**: 3 platforms (Indices `0`, `1`, `2`).
*   **Data Structures**:
    *   Each Platform contains a sorted schedule: `map<startTime, Reservation>`.
    *   A global `truckRegistry` mapping: `truckId` $\rightarrow$ `{platformIdx, Reservation}`.

---

### **2. Step-by-Step Simulation**

#### **Step A: `assignPlatform("T1", 0, 5)` (Arrival=0, Duration=5)**
*   **Check availability of all platforms**:
    *   Platform 0: free at $0 \rightarrow$ delay = $\max(0, 0 - 0) = 0$
    *   Platform 1: free at $0 \rightarrow$ delay = $0$
    *   Platform 2: free at $0 \rightarrow$ delay = $0$
*   All delays are `0`. Tie-break picks the lowest index: **Platform 0**.
*   Reservation range: $[0, \; 0 + 5 - 1] = [0, 4]$.
*   **Returns**: `0,0` (Platform 0, delay 0).

**State:**
```text
Platform 0 Schedule : { 0 -> Reservation("T1", 0, 4) }  (free at 5)
Platform 1 Schedule : {}
Platform 2 Schedule : {}
truckRegistry       : {"T1" -> {platform: 0, range: [0, 4]}}
```

---

#### **Step B: `assignPlatform("T2", 2, 3)` (Arrival=2, Duration=3)**
*   **Check availability of all platforms**:
    *   Platform 0: free at $5 \rightarrow$ delay = $\max(0, 5 - 2) = 3$
    *   Platform 1: free at $0 \rightarrow$ delay = $0$
    *   Platform 2: free at $0 \rightarrow$ delay = $0$
*   Min delay is `0` $\rightarrow$ Tie-break picks **Platform 1**.
*   Reservation range: $[2, \; 2 + 3 - 1] = [2, 4]$.
*   **Returns**: `1,0`

**State:**
```text
Platform 0 Schedule : { 0 -> Reservation("T1", 0, 4) }  (free at 5)
Platform 1 Schedule : { 2 -> Reservation("T2", 2, 4) }  (free at 5)
Platform 2 Schedule : {}                                (free at 0)
truckRegistry       : {"T1" -> {0, [0..4]}, "T2" -> {1, [2..4]}}
```

---

#### **Step C: `assignPlatform("T3", 4, 4)` (Arrival=4, Duration=4)**
*   **Check availability**:
    *   Platform 0: free at $5 \rightarrow$ delay = $\max(0, 5 - 4) = 1$
    *   Platform 1: free at $5 \rightarrow$ delay = $\max(0, 5 - 4) = 1$
    *   Platform 2: free at $0 \rightarrow$ delay = $0$
*   Min delay is `0` $\rightarrow$ Pick **Platform 2**.
*   Reservation range: $[4, \; 4 + 4 - 1] = [4, 7]$.
*   **Returns**: `2,0`

**State:**
```text
Platform 0 Schedule : { 0 -> Reservation("T1", 0, 4) }  (free at 5)
Platform 1 Schedule : { 2 -> Reservation("T2", 2, 4) }  (free at 5)
Platform 2 Schedule : { 4 -> Reservation("T3", 4, 7) }  (free at 8)
```

---

#### **Step D: `assignPlatform("T4", 4, 3)` — *Forces a Wait/Delay!*** (Arrival=4, Duration=3)
*   **Check availability at Arrival = 4**:
    *   Platform 0: free at $5 \rightarrow$ delay = $\max(0, 5 - 4) = 1$
    *   Platform 1: free at $5 \rightarrow$ delay = $\max(0, 5 - 4) = 1$
    *   Platform 2: free at $8 \rightarrow$ delay = $\max(0, 8 - 4) = 4$
*   Min delay is `1`. Tie-break between Platform 0 and 1 picks **Platform 0**.
*   Reservation range starts at: $4 + 1 \text{ (delay)} = 5$.
*   Reservation range: $[5, \; 5 + 3 - 1] = [5, 7]$.
*   **Returns**: `0,1` (Platform 0, delay 1).

**State:**
```text
Platform 0 Schedule : { 0 -> Res("T1", 0, 4), 5 -> Res("T4", 5, 7) }  (free at 8)
Platform 1 Schedule : { 2 -> Res("T2", 2, 4) }                        (free at 5)
Platform 2 Schedule : { 4 -> Res("T3", 4, 7) }                        (free at 8)
```

---

### **3. Query Simulation**

#### **Operation: `getTrainAtPlatform(platformIdx=0, time=6)`**
1. Search Platform 0's schedule map using `upper_bound(6)`.
2. This returns the first reservation starting *after* time 6 $\rightarrow$ (None, returns end of map).
3. Step back by one element $\rightarrow$ gets key `5` (Reservation `"T4"`, range `[5, 7]`).
4. Check if $6 \in [5, 7]$ $\rightarrow$ Yes!
5. **Returns**: `"T4"`

---

#### **Operation: `getPlatformOfTrain(truckId="T4", time=3)`**
1. Do $O(1)$ search in `truckRegistry` for `"T4"`.
2. Found: Platform index `0` and Reservation range `[5, 7]`.
3. Check if $3 \in [5, 7]$ $\rightarrow$ No!
4. **Returns**: `-1` (truck is not yet parked at this time).