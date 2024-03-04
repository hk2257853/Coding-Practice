#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <numeric>
using ll = long long;

int main()
{
    int t;
    cin >> t;
    while (t)
    {
        t--;
        int n, x;
        string s;
        cin >> n >> x >> s;
        bool flag = true;
        int swap = 0;
        for (int i = 0; i < s.length(); i++)
        {            
            if (s[i] == '0')
                swap--;
            else swap = x;
            if (swap < 0)
            {
                flag = false;
            }
        }

        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
