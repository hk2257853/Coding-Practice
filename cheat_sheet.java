import java.util.*;

/* This is a cheat sheet for common Java Collections and algorithms.
Topics covered:
1. ArrayList (Vector) operations
2. HashSet (Set) operations
3. HashMap (Map) operations
4. String operations
5. Stack operations
6. Queue operations
7. Priority Queue operations
8. Prefix Sum and variations
9. Maths (GCD, LCM)
10. Graph representation using adjacency list
11. DFS and BFS
12. Modular arithmetic
13. Recursion stack
*/

public class CheatSheet {

    // Custom Pair class (Java lacks std::pair)
    static class Pair<U, V> {
        public U first;
        public V second;
        public Pair(U first, V second) {
            this.first = first;
            this.second = second;
        }
    }

    // lower_bound implementation: first position where element is not less than key (>= key)
    static int lowerBound(List<Integer> list, int key) {
        int low = 0, high = list.size();
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (key <= list.get(mid)) high = mid;
            else low = mid + 1;
        }
        return low; // returns list.size() if not found
    }

    // upper_bound implementation: first position where element is greater than key (> key)
    static int upperBound(List<Integer> list, int key) {
        int low = 0, high = list.size();
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (key < list.get(mid)) high = mid;
            else low = mid + 1;
        }
        return low; // returns list.size() if not found
    }

    // GCD helper
    static int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    // DFS
    static void dfs(int node, boolean[] visited, List<List<Integer>> adjList) {
        visited[node] = true;
        System.out.print(node + " ");
        for (int neighbor : adjList.get(node)) {
            if (!visited[neighbor]) {
                dfs(neighbor, visited, adjList);
            }
        }
    }

    // BFS
    static void bfs(int startNode, List<List<Integer>> adjList) {
        boolean[] visited = new boolean[adjList.size()];
        Queue<Integer> q = new LinkedList<>();
        
        visited[startNode] = true;
        q.add(startNode);

        while (!q.isEmpty()) {
            int node = q.poll();
            System.out.print(node + " ");

            for (int neighbor : adjList.get(node)) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.add(neighbor);
                }
            }
        }
    }

    public static void main(String[] args) {

        // 1. ArrayList (Vector) operations
        List<Integer> vec = new ArrayList<>(Arrays.asList(1, 2, 3, 4, 5));
        vec.add(6);                                     // Add element to the end
        vec.remove(vec.size() - 1);                     // Remove last element
        Collections.sort(vec);                          // Sort the list
        Collections.reverse(vec);                       // Reverse the list
        int minElem = Collections.min(vec);             // Find minimum element
        int maxElem = Collections.max(vec);             // Find maximum element
        
        // Sum of elements (using Streams)
        int sum = vec.stream().mapToInt(Integer::intValue).sum(); 

        // 2D ArrayList initialization (3 rows, 4 columns filled with 0)
        List<List<Integer>> matrix = new ArrayList<>();
        for (int i = 0; i < 3; i++) {
            matrix.add(new ArrayList<>(Collections.nCopies(4, 0)));
        }

        // traverse 2D list
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix.get(i).size(); j++) {
                System.out.print(matrix.get(i).get(j) + " ");
            }
            System.out.println();
        }

        // ArrayList of Pairs
        List<Pair<Integer, Integer>> vecPair = new ArrayList<>();
        vecPair.add(new Pair<>(1, 2));
        vecPair.add(new Pair<>(3, 4));
        for (Pair<Integer, Integer> p : vecPair) {
            System.out.println(p.first + ", " + p.second);
        }
        
        // Sort pairs by first element, then second
        vecPair.sort((a, b) -> {
            if (!a.first.equals(b.first)) return a.first - b.first;
            return a.second - b.second;
        });
        
        // Sort strictly by second element
        vecPair.sort(Comparator.comparingInt(a -> a.second));

        // Binary search (returns >= 0 if found, -(insertion point) - 1 if not)
        Collections.sort(vec); // Must be sorted first
        boolean found = Collections.binarySearch(vec, 3) >= 0;

        // lower_bound and upper_bound
        List<Integer> v = new ArrayList<>(Arrays.asList(1, 2, 2, 2, 3));
        
        // case 1: x = 2
        int lb1 = lowerBound(v, 2); // index = 1
        int ub1 = upperBound(v, 2); // index = 4
        System.out.println("Value at lower bound: " + v.get(lb1) + ", Value at upper bound: " + v.get(ub1));
        System.out.println("Lower bound of 2: " + lb1 + ", Upper bound of 2: " + ub1);

        // case 2: x = 4
        int lb2 = lowerBound(v, 4); // size() -> 5
        int ub2 = upperBound(v, 4); // size() -> 5
        
        // Condition to avoid out of bounds
        if (lb2 != v.size()) {
            System.out.println(v.get(lb2));
        } else {
            System.out.println("4 not found, position is at the end");
        }

        // <= x ? -> upper_bound(x) - 1
        int ub3 = upperBound(v, 2);
        System.out.println(v.get(ub3 - 1)); // output - 2 (value)
        
        // < x ? -> lower_bound(x) - 1
        int lb3 = lowerBound(v, 2);
        System.out.println(lb3 - 1); // output - 0 (index)


        // 2. HashSet (Set) operations
        HashSet<Integer> uset = new HashSet<>();
        uset.add(10); // Insert element
        if (uset.contains(10)) { /* exists */ }


        // 3. HashMap (Map) operations
        HashMap<String, Integer> umap = new HashMap<>();
        umap.put("apple", 5); // Insert key-value pair
        int val = umap.get("apple"); // Access value by key
        
        // Iterate over map
        for (Map.Entry<String, Integer> pair : umap.entrySet()) {
            System.out.println(pair.getKey() + ": " + pair.getValue());
        }
        boolean hasBanana = umap.containsKey("banana"); // Check if key exists


        // 4. String operations
        String str = "hello";
        String reversedStr = new StringBuilder(str).reverse().toString(); // Reverse string


        // 5. Stack operations (Using ArrayDeque is generally preferred over java.util.Stack)
        Deque<Integer> stk = new ArrayDeque<>(); 
        stk.push(1);                // Push element
        int top = stk.peek();       // Access top element
        stk.pop();                  // Pop element
        boolean isEmpty = stk.isEmpty();


        // 6. Queue operations
        Queue<Integer> q = new LinkedList<>(); 
        q.add(1);                   // Inserted at rear
        int front = q.peek();       // Access front element
        q.poll();                   // Remove front element
        boolean isQEmpty = q.isEmpty();


        // 7. Deque operations
        Deque<Integer> dq = new ArrayDeque<>();
        dq.addLast(1);              // Add element to the back
        dq.addFirst(2);             // Add element to the front
        int dqFront = dq.peekFirst(); // Access front
        int dqBack = dq.peekLast();   // Access back
        dq.pollFirst();             // Remove front
        dq.pollLast();              // Remove back


        // 8. Priority Queue operations
        // Max-heap - maximum element at top (Requires Collections.reverseOrder())
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        pq.add(3);
        pq.add(1);
        pq.add(2);
        int maxHeapElem = pq.peek(); // Access maximum element: 3
        pq.poll();                   // Remove maximum element

        // Min-heap - minimum element at top (Default in Java)
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();


        // 9. Prefix Sum
        int[] prefixSum = new int[vec.size()];
        prefixSum[0] = vec.get(0);
        for (int i = 1; i < vec.size(); i++) {
            prefixSum[i] = prefixSum[i - 1] + vec.get(i);
        }

        // 10. Maths
        int a = 10, b = 15;
        int gcd_val = gcd(a, b); // GCD: 5
        int gcd_val2 = gcd(gcd_val, 20); // GCD of 3 numbers
        int lcm_val = (a * b) / gcd_val; // LCM: 30

        // 11. Graph Representation
        int n = 5;
        List<List<Integer>> adjList = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adjList.add(new ArrayList<>());
        }
        
        // adding edges
        adjList.get(0).add(1);
        adjList.get(0).add(2);
        adjList.get(1).add(2);
        adjList.get(2).add(0);
        adjList.get(2).add(3);
        adjList.get(3).add(3);
        
        // traversing
        for (int i = 0; i < n; i++) {
            System.out.print("Node " + i + ": ");
            for (int neighbor : adjList.get(i)) {
                System.out.print(neighbor + " ");
            }
            System.out.println();
        }

        boolean[] visited = new boolean[n];
        dfs(2, visited, adjList); // DFS starting from node 2
        System.out.println();
        bfs(2, adjList); // BFS starting from node 2
        System.out.println();

        // 12. Modulo Arithmetic
        int mod = 1000000007;
        int result = (a + b) % mod;
        int result2 = (a * b) % mod;
        // For negative modulo in Java, we need a slightly different formula to ensure a positive result:
        int result3 = (((a - b) % mod) + mod) % mod; 
        int result4 = (a / b) % mod; // Note: proper modular division requires finding the modular multiplicative inverse!
        
        System.out.println(result + " " + result2 + " " + result3 + " " + result4);

        if (a % 2 == 0) {
            System.out.println("Even");
        } else {
            System.out.println("Odd");
        }
    }
}