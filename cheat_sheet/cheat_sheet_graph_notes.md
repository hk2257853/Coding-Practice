# Graph Algorithms Complexity Cheat Sheet

| # | Algorithm / Topic | Time Complexity | Space Complexity | Key Notes |
| :-: | :--- | :--- | :--- | :--- |
| **1** | **Graph Representation (Adjacency List)** | Add edge: $O(1)$<br>Traverse neighbors: $O(\text{deg}(u))$ | $O(V + E)$ | Space-efficient for sparse graphs |
| **2** | **DFS (Depth-First Search)** | $O(V + E)$ | $O(V)$ | Recursion stack / call stack |
| **3** | **BFS (Breadth-First Search)** | $O(V + E)$ | $O(V)$ | Level-order traversal using Queue |
| **4** | **Dijkstra's Algorithm** | $O((V + E) \log V)$ | $O(V + E)$ | Non-negative edge weights; uses Min-PQ |
| **5** | **Cycle Detection (Directed Graph)** | $O(V + E)$ | $O(V)$ | DFS using `visited` and `inStack` arrays |
| **6** | **Cycle Detection (Undirected Graph)** | $O(V + E)$ | $O(V)$ | DFS passing `parent` node |
| **7** | **Topological Sort (DFS)** | $O(V + E)$ | $O(V)$ | DAG only; uses Stack on finish time |
| **8** | **Find All Paths (Source to Target)** | **DAG**: $O(2^V \cdot V)$<br>**General Graph**: $O(V! \cdot V)$ | Aux: $O(V)$<br>Total: $O(N_{\text{paths}} \cdot V)$ | Backtracking with DFS |

---

### Note on "Find All Paths" Time Complexity (`choices ^ depth`):

- **DAG $\rightarrow \mathbf{O(2^V \cdot V)}$**:
  - **Fixed 2 choices** at each step (Include node or Exclude node).
  - $2 \times 2 \times 2 \dots (V \text{ times}) = 2^V$ paths.
- **General Graph $\rightarrow \mathbf{O(V! \cdot V)}$**:
  - **Decreasing choices** at each step (Pick 1 out of remaining unvisited neighbors).
  - $(V-1) \times (V-2) \times (V-3) \dots \times 1 = V!$ paths.

---

### 1. Dijkstra — How It Actually Visits Nodes

- **Multiple Enqueues for Same Node**: A node's `dist[]` can be *updated multiple times* — each time a cheaper path is found via relaxation, `dist[node]` is overwritten and a new `(dist, node)` entry is pushed to the PQ, even if stale entries for that node already exist in the PQ.
- **Single Effective Processing**: A node can sit in the PQ *multiple times*, but only ever gets **effectively processed once** — when popped, we check `if (d > dist[u]) continue;` to skip stale/outdated entries.
- **Why It's Safe**: The Min-PQ always pops the globally smallest distance node next. By the time a node's true minimum is popped, no future relaxation can beat it (requires non-negative edge weights) — so its neighbors are only ever expanded using the final, correct `dist[node]`.
- **Vs DFS/BFS**: DFS and BFS visit each node exactly once because they only care about reachability/hop-count, which cannot be revised. Dijkstra's cost estimates can improve, which is why duplicate queue entries exist — but the stale-check ensures each node is processed once, just possibly pushed several times.

---

### 2. BFS & DFS — How They Actually Visit Nodes

#### BFS (Breadth-First Search)
- **Marked Immediately on Push**: A node is marked `visited[neighbor] = true` *immediately when it is pushed* into the queue (preventing duplicate pushes of the same node).
- **Single Visit Guarantee**: Each node enters and leaves the queue *exactly once*.
- **Shortest Path in Unweighted Graphs**: BFS guarantees the **shortest path** (minimum edge count / hops) in **unweighted graphs** (or graphs with uniform edge weights). Because BFS explores level-by-level ($d=0, 1, 2, \dots$), the first time a node is discovered is guaranteed to be via the shortest possible distance.
- **Why It Works**: Since edge weights are uniform (all 1), hop count equals total path distance. Distances can never improve later, so no node is ever re-pushed or updated.

#### DFS (Depth-First Search)
- **Marked on Function Entry**: A node is marked `visited[node] = true` *immediately upon entering* the recursive function call.
- **Deep Traversal**: Explores as deep as possible along a branch before backtracking.
- **Standard Traversal vs Backtracking**:
  - **Standard DFS (Reachability / Cycle / TopoSort)**: A node stays `visited = true` permanently. Each node is visited *exactly once*.
  - **Backtracking DFS (All Paths)**: `visited[node]` is reset to `false` when backtracking, allowing the node to participate in alternative paths.
