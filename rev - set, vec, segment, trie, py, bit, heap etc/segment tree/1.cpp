// refered apna college videos and notes
// TODO: prac min max on range etc for practice.

#include <iostream>
using namespace std;

const int N = 1e5 + 2; // 10^5   2e5 - 2x10^5
int a[N], tree[4 * N];

void build(int node, int st, int en) // build takes O(n). node is like index for tree.
{
    // base case
    if (st == en)
    {
        tree[node] = a[st]; // leaf/1 node
        return;
    }

    int mid = (st + en) / 2;
    build(2 * node, st, mid);
    build(2 * node + 1, mid + 1, en);

    // we r building for sum here
    tree[node] = tree[2 * node] + tree[2 * node + 1]; // sum of left n right child

    // had learnt in heap sort (anuj) - left child is 2*node & right is 2*node+1
}

void update(int node, int st, int en, int idx, int val)
{
    if (st == en)
    { // base
        a[idx] = val;
        tree[node] = val;
        return;
    }

    int mid = (st + en) / 2; // traversing to req node. st, en r wrt arrays
    if (idx <= mid)          // ig = not that imp?
    {
        update(2 * node, st, mid, idx, val);
    }
    else
    {
        update(2 * node + 1, mid + 1, en, idx, val);
    }

    tree[node] = tree[2 * node] + tree[2 * node + 1];
    // updating while backtracking/recursion property I learnt
    // during trees. Its just one path (eg to update ind 6 - val = 6, path is 39 -> 25 -> 16 -> 6),
    // while backtracking only this part is updated
}

int rangesum(int node, int st, int en, int l, int r)
{
    if (st > r || en < l)
        return 0; // no overlap se l  r (or es)   fix ls and put se at various places

    if (l <= st && en <= r)
        return tree[node]; // l  st  en  r   complete overlap

    int mid = (st + en) / 2;
    int q1 = rangesum(2 * node, st, mid, l, r);
    int q2 = rangesum(2 * node + 1, mid + 1, en, l, r);
    return q1 + q2;
}
// note: I check if current st and en lies in required range[l,r]

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    build(1, 0, n - 1);
    cout << "Tree: ";
    for (int i = 1; i < 15; i++) // 2N-1 nodes
    {
        cout << tree[i] << " ";
    }
    cout << endl;
    int l, r;
    cin >> l >> r;
    cout << "Sum: " << rangesum(1, 0, n - 1, l, r);

    return 0;
}

/*
In this code, N = 1e5+2 is chosen as a large enough value to accommodate the maximum size of the input array a[].

The size of the segment tree, which is stored in the array tree[], is chosen to be 4 times the size of the input array.
This is because the size of the segment tree is typically 4 times the size of the input array for a range sum query.

The reason for this is that the height of the segment tree is log2(N) for an input array of size N, and the total number
of nodes in the segment tree is 2N - 1. Therefore, the maximum size of the segment tree is 4N.

By choosing the size of the segment tree as 4*N, we ensure that it is large enough to accommodate the maximum size of the input
array, and also that it has enough space to store all the nodes required for the segment tree.
*/