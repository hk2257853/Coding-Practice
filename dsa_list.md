# Data Structures & Algorithms List

## Data Structures
- Array
- String
- Matrix
- Linked List
- Stack
- Queue
- Tree
- Graph

## Common Algorithms
- Searching
- Sorting
- Hashing
- Prefix sum
- Suffix Sum (c for more applications of these 2)
- Greedy (just orally try n study)
- Recursion
- Backtracking
- Dynamic Programming
- Trie, segment tree basics rev *
- Bit manipulation * - bookmarked 4 ques
- Heaps(stl)

## Others
- Few recursion yet todo, todos in coding, re go through my notes and do skipped stuff.

## Time Complexity vs. Input Constraints Guide
*(Based on standard ~10^8 operations per second limit)*

| Constraint ($N$) | Target Time Complexity | Typical Algorithms / Approaches |
| :--- | :--- | :--- |
| **$N \le 10 \sim 12$** | $O(N!)$ or $O(N^2 \cdot 2^N)$ | Recursion / Backtracking, Permutations |
| **$N \le 15 \sim 20$** | $O(2^N)$ or $O(N \cdot 2^N)$ | Subsets, Bitmask Dynamic Programming |
| **$N \le 400 \sim 500$** | $O(N^3)$ | Floyd-Warshall, 3D DP, Triple Nested Loops |
| **$N \le 10^3$ ($1,000$)** | $O(N^2)$ | 2D DP, Matrix Operations, All Pairs ($O(N^2)$) |
| **$N \le 10^5$ ($100,000$)** | $O(N \log N)$ or $O(N)$ | Sorting, Binary Search, Heaps, Segment Trees, 1D DP, Sliding Window |
| **$N \le 10^6 \sim 10^7$** | $O(N)$ or $O(N \log \log N)$ | Two Pointers, HashMap, Sieve of Eratosthenes, Linear Scan |
| **$N \ge 10^8 \sim 10^9+$** | $O(\log N)$ or $O(1)$ | Binary Search on Range/Answer, Bitwise Math, Matrix Exponentiation |

