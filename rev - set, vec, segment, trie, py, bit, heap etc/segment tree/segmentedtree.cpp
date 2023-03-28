#include "iostream"
using namespace std;
#include "vector"
#define ll long long

void build(vector<ll> &tree, vector<ll> &a, int v, int tl, int tr)
{
    if (tl == tr)
    {
        tree[v] = a[tl];
    }
    else
    {
        int tm = (tl + tr) / 2;
        build(tree, a, 2 * v, tl, tm);
        build(tree, a, 2 * v + 1, tm + 1, tr);
        tree[v] = tree[2 * v] + tree[2 * v + 1];
    }
}

void update(vector<ll> &tree, int v, int tl, int tr, int l, int r, int add)
{
    if (l > r)
        return;
    if (l == tl && r == tr)
    {
        tree[v] += (tr - tl + 1) * add;
    }
    else
    {
        int tm = (tl + tr) / 2;
        update(tree, 2 * v, tl, tm, l, min(r, tm), add);
        update(tree, 2 * v + 1, tm + 1, tr, max(l, tm + 1), r, add);
        tree[v] = tree[2 * v] + tree[2 * v + 1];
    }
}

ll query(vector<ll> &tree, int v, int tl, int tr, int l, int r)
{
    if (l > r)
        return 0;
    if (l == tl && r == tr)
    {
        return tree[v];
    }
    else
    {
        int tm = (tl + tr) / 2;
        return query(tree, 2 * v, tl, tm, l, min(r, tm)) + query(tree, 2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n), tree(4 * n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    build(tree, a, 1, 0, n - 1);
    int q;
    cin >> q;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int l, r, add;
            cin >> l >> r >> add;
            update(tree, 1, 0, n - 1, l - 1, r - 1, add);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << query(tree, 1, 0, n - 1, l - 1, r - 1) << endl;
        }
    }

    for (int i = 0; i < tree.size(); i++)
    {
        cout << tree[i] << " ";
    }
    cout << endl;

    return 0;
}
