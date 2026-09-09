#include <bits/stdc++.h>
using namespace std;

/* This is a cheat sheet for common C++ STL functions and algorithms.
Topics covered:
1. Vector operations
2. Set operations
3. Map operations
4. String operations
5. Stack operations
6. Queue operations
7. Priority Queue operations
8. Prefix Sum and variations (suffix sum, max prefix, difference array, difference array for range updates etc)
9. Maths (GCD, LCM)
10. Modular arithmetic
11. Recursion stack - see some DP and backtracking problems too
12. All Subarrays Brute Force
13. Stack Template (Monotonic Stack)
14. Sliding Window Template (Fixed & Variable Window)
15. Merge Sort
16. Digits & Alphabet Indexing (0 to 25)
*/



int main()
{
    // This is a cheat sheet for common C++ STL functions and algorithms.

    // Vector operations
    vector<int> vec = {1, 2, 3, 4, 5};
    vec.push_back(6);                                 // Add element to the end
    vec.pop_back();                                   // Remove last element
    sort(vec.begin(), vec.end());                     // Sort the vector
    reverse(vec.begin(), vec.end());                  // Reverse the vector
    *min_element(vec.begin(), vec.end());             // Find minimum element
    *max_element(vec.begin(), vec.end());             // Find maximum element
    accumulate(vec.begin(), vec.end(), 0);            // Sum of elements
    vector<vector<int>> matrix(3, vector<int>(4, 0)); // 2D vector initialization - rows = 3, cols = 4, initial value = 0
    // traverse 2D vector
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // vector pairs
    vector<pair<int, int>> vecPair;
    vecPair.push_back({1, 2});
    vecPair.push_back({3, 4});
    for (const auto &p : vecPair)
    {
        cout << p.first << ", " << p.second << endl;
    }
    // sort vector of pairs by first element, then second element
    sort(vecPair.begin(), vecPair.end());
    sort(vecPair.begin(), vecPair.end(), [](const auto &a, const auto &b)
         { return a.second < b.second; });

    // binary search
    bool found = binary_search(vec.begin(), vec.end(), 3); // Check if 3 is in vec

    // lower_bound - first position where element is not less than x (>= x)
    // upper_bound - first position where element is greater than x (> x)
    // [start, end) - v.end() means position after last element
    vector<int> v = {1, 2, 2, 2, 3};
    // case 1: x = 2
    auto lb1 = lower_bound(v.begin(), v.end(), 2);                                          // index = 1, value = 2
    auto ub1 = upper_bound(v.begin(), v.end(), 2);                                          // index = 4, value = 3
    cout << "Value at lower bound: " << *lb1 << ", Value at upper bound: " << *ub1 << endl; // output - 2 3
    // to get the indices
    cout << "Lower bound of 2: " << (lb1 - v.begin()) << ", Upper bound of 2: " << (ub1 - v.begin()) << endl; // output - 1 4

    // case 2: x = 4
    auto lb2 = lower_bound(v.begin(), v.end(), 4); // end()
    auto ub2 = upper_bound(v.begin(), v.end(), 4); // end()

    cout << "Lower bound of 4: " << lb2 - v.begin() << ", Upper bound of 4: " << (ub2 - v.begin()) << endl; // output - 5 5
    // have a condition following to avoid going out of bounds
    if (lb2 != v.end())
    {
        cout << *lb2 << endl;
    }
    else
    {
        cout << "4 not found, position is at the end" << endl;
    }

    // case 4: x = 0
    auto lb4 = lower_bound(v.begin(), v.end(), 0); // index = 0, value = 1
    auto ub4 = upper_bound(v.begin(), v.end(), 0); // index = 0, value = 1

    // what if i want <= x ? -> upper_bound(x) - 1
    auto ub3 = upper_bound(v.begin(), v.end(), 2); // index = 4, value = 3
    cout << *(ub3 - 1) << endl;                    // output - 2 (value)
    // what if i want < x ? -> lower_bound(x) - 1
    auto lb3 = lower_bound(v.begin(), v.end(), 2); // index = 1, value = 2
    cout << (lb3 - 1) - v.begin() << endl;         // output - 0 (index)

    // Set operations
    unordered_set<int> uset;
    uset.insert(10); // Insert element
    if (uset.count(10))
    { /* exists */
    }

    // Map operations
    unordered_map<string, int> umap;
    umap["apple"] = 5;       // Insert key-value pair
    int val = umap["apple"]; // Access value by key
    for (const auto &pair : umap)
    { // Iterate over map
        cout << pair.first << ": " << pair.second << endl;
    }
    umap.count("banana"); // Check if key exists

    // String operations
    string str = "hello";
    reverse(str.begin(), str.end()); // Reverse string

    // stack operations
    stack<int> stk;             // LIFO - last in first out
    stk.push(1);                // Push element
    int top = stk.top();        // Access top element
    stk.pop();                  // Pop element
    bool isEmpty = stk.empty(); // Check if stack is empty

    // queue operations
    queue<int> q;          // FIFO - first in first out
    q.push(1);             // inserted from back
    int front = q.front(); // Access front element
    // access back element - no direct function, need to use a workaround
    // int back = q.back();       // Access back element. time complexity - O(1) in C++ STL implementation
    q.pop();                   // remove front element
    bool isQEmpty = q.empty(); // Check if queue is empty
    // 1 2 3 4 5
    // 1 is at front, 5 is at back

    // deque operations
    deque<int> dq;
    dq.push_back(1);             // Add element to the back
    dq.push_front(2);            // Add element to the front
    int dqFront = dq.front();    // Access front element
    int dqBack = dq.back();      // Access back element
    dq.pop_front();              // Remove front element
    dq.pop_back();               // Remove back element
    bool isDqEmpty = dq.empty(); // Check if deque is empty

    // priority queue operations - max-heap - maximum element at top
    priority_queue<int> pq; // Max-heap
    pq.push(3);             // Insert element
    pq.push(1);
    pq.push(2);
    int maxElem = pq.top(); // Access maximum element - 3
    pq.pop();               // Remove maximum element

    // priority queue operations - min-heap - minimum element at top
    priority_queue<int, vector<int>, greater<int>> minHeap; // Min-heap

    // prefix sum
    int n = vec.size();
    vector<int> prefixSum(n, 0);
    prefixSum[0] = vec[0];
    for (int i = 1; i < n; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + vec[i];
    }
    // NOTE: a lot of variations possible depending on the problem
    // eg: suffix sum, max prefix, difference array
    // array = {5, 3, 8, 2, 7}
    // prefixSum = {5, 8, 16, 18, 25}
    // suffixSum = {25, 20, 17, 9, 7}
    // maxPrefix = {5, 5, 8, 8, 8}
    // diff = {5, -2, 5, -6, 5}

    // difference array - to perform range updates efficiently.
    // array = {1, 2, 3, 4, 5}. from index 1 to 3, add 2
    // diff = {0, 2, 0, 0, -2} -> add 2 at index 1 and subtract 2 at index 3+1=4
    // take prefix sum - {0, 2, 2, 2, 0} -> add this to original array to get updated array {1, 4, 5, 6, 5}
    // last index is edge case (no need of -ve in that case).
    // similar stuff can be done with xor array for range xor updates

    // maths
    int a = 10, b = 15;
    int gcd_val = __gcd(a, b); // GCD of a and b - highest number that divides both: 5
    // gcd of more than 2 numbers
    int gcd_val2 = __gcd(gcd_val, 20); // GCD of a, b, and 20
    int lcm_val = (a * b) / gcd_val;   // LCM of a and b - lowest number divisible by both: 30
    // gcd - greatest common divisor, lcm - least common multiple

    // formulas
    /*
    Sum of first n natural numbers: n(n+1)/2
    Sum of first n odd numbers: n^2
    Sum of first n even numbers: n(n+1)

    |a-b| = k
    -> a + b = +k or a + b = -k

    no of subarrays - n(n+1)/2
    no of sub sequences - 2^n (each element can be included or excluded)

    */


    int mod = 1000000007; // A large prime commonly used in competitive programming to prevent overflow ensure results fit in standard data types
    int result = (a + b) % mod;
    int result2 = (a * b) % mod;
    int result3 = (a - b + mod) % mod; // For negative modulo
    int result4 = (a / b) % mod;       // Division in modular arithmetic
    cout << result << " " << result2 << " " << result3 << " " << result4 << endl;

    if (a % 2 == 0)
    {
        cout << "Even";
    }
    else
    {
        cout << "Odd";
    }

    // 14. Recursion stack - see some DP and backtracking problems too - just see my notes or previous submissions

    // 15. All Subarrays Brute Force
    vector<int> subArrVec = {1, 2, 3, 4};
    n = subArrVec.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            // Subarray spans from index i to j
            // e.g., process or print elements from index i to j
        }
    }

    // 16. Stack Template (Monotonic Stack)
    // 4 Main Variations:
    // 1. Next Greater Element (NGE): Loop right -> left (i = n-1 to 0), pop while top <= arr[i]
    // 2. Next Smaller Element (NSE): Loop right -> left (i = n-1 to 0), pop while top >= arr[i]
    // 3. Previous Greater Element (PGE): Loop left -> right (i = 0 to n-1), pop while top <= arr[i]
    // 4. Previous Smaller Element (PSE): Loop left -> right (i = 0 to n-1), pop while top >= arr[i]
    // TIP: Store indices in stack instead of values to calculate distances/ranges (e.g. Histogram, Stock Span).

    vector<int> stkArr = {4, 5, 2, 10, 8};
    // nge - {5, 10, 10, -1, -1}
    // stack represents valid candidates
    // thus go right to left (as the ans gotta be present already)
    n = stkArr.size();
    vector<int> nge(n, -1);
    stack<int> st; // stores elements (or store indices)
    for (int i = n - 1; i >= 0; i--)
    {
        // remove invalid candidates (stk top is 8 and coming element is 10, thus for future elements 8 can never be answer)
        while (!st.empty() && st.top() <= stkArr[i])
        {
            st.pop();
        }
        // top is the answer
        if (!st.empty())
        {
            nge[i] = st.top();
        }
        st.push(stkArr[i]);
    }

    // if I need to pop for both sides (eg - cases where candidates expire) - use dequeue

    // 17. Sliding Window Template
    // 17.1 Fixed Window Size K
    int winK = 3;
    n = vec.size();
    if (n >= winK)
    {
        int currentWindowSum = 0;
        for (int i = 0; i < winK; i++)
        {
            currentWindowSum += vec[i];
        }
        int maxWindowSum = currentWindowSum;
        for (int i = winK; i < n; i++)
        {
            currentWindowSum += vec[i] - vec[i - winK];
            maxWindowSum = max(maxWindowSum, currentWindowSum);
        }
    }

    // 17.2 Variable Window Size (Two Pointers: expand right, shrink left)
    int left = 0;
    for (int right = 0; right < n; right++)
    {
        // Expand window: include vec[right], e.g. currentSum += vec[right]
        
        while (/* condition_violated e.g. currentSum > target */ left <= right)
        {
            // Shrink window: exclude vec[left], e.g. currentSum -= vec[left]
            left++;
        }
        // Update answer (e.g., max length = right - left + 1)
    }

    // 16. Digits & Alphabet Indexing
    // 1. Digits & Chars
    int x = '4' - '0';       // char to int: '4' - '0' = 4
    char c = 4 + '0';        // int to char: 4 + '0' = '4'

    // 2. Alphabet Indexing (0 to 25)
    string s = "leetcode";
    int idx = s[0] - 'a';    // char to index: 'a'-'a' = 0, 'z'-'a' = 25
    char ch = 'a' + idx;     // index to char: 'a' + 0 = 'a', 'a' + 1 = 'b', etc
    int freq[26] = {0};      // freq array for 'a' to 'z'
    freq[s[0] - 'a']++;
    // (for uppercase, use s[i] - 'A')

    return 0;
}

// 15. Merge Sort
// Imagining both halves as independent, already-sorted units helps a lot.
// Visualize the splitting and merging with a diagram before coding —
// this one is great: https://media.geeksforgeeks.org/wp-content/uploads/20200601174332/Merge-Sort-Tutorial.png
//
// This is recursion — don't try to trace the whole tree.
// Just focus on the root and the very next level; that's enough to derive the logic.

void merge(vector<int>& arr, int l, int r, int mid) {
    // 1 3 4 7
    // 2 3 8
    // 1 2 3 3 4 7 8

    vector<int> temp;
    int lInd = l, rInd = mid + 1;

    while (lInd <= mid && rInd <= r) {
        if (arr[lInd] <= arr[rInd]) {
            temp.push_back(arr[lInd]);
            lInd++;
        } else {
            temp.push_back(arr[rInd]);
            rInd++;
        }
    }

    while (lInd <= mid) {
        temp.push_back(arr[lInd]);
        lInd++;
    }

    while (rInd <= r) {
        temp.push_back(arr[rInd]);
        rInd++;
    }

    // standard way
    // for (int i = l; i <= r; i++) {
    //     arr[i] = temp[i - l];
    // }

    // my way
    int tInd = 0;
    for (int i = l; i <= mid; i++, tInd++) {
        arr[i] = temp[tInd];
    }

    for (int i = mid + 1; i <= r; i++, tInd++) {
        arr[i] = temp[tInd];
    }
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l >= r) return; // size 0 or 1

    int mid = l + (r - l) / 2;

    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, r, mid);
}