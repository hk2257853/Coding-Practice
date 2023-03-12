#include <bits/stdc++.h>
using namespace std;

void sol()
{
    int n;
    int x = 0, y = 0;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        if (s == "START38")
        {
            x++;
        }
        else
        {
            y++;
        }
    }
    cout << x << " " << y << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        sol();
    }
    return 0;
}