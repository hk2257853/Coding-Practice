#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <numeric>
using ll = long long;

bool isvovel(char c)
{
    if (c == 'c' || c == 'b' || c == 'd')
        return false;
    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t)
    {
        t--;
        int size;
        string s;
        cin >> size >> s;

        if (size <= 3)
        {
            cout << s << endl;
            continue;
        }

        vector<int> ind;

        for (int i = 0; i < s.size(); i++)
        {
            if ((i < s.size() - 1) &&  !isvovel(s[i]) && !isvovel(s[i + 1]))
            {
                ind.push_back(i + 1);
            }
            else if ((i < s.size() - 3) && !isvovel(s[i]) && isvovel(s[i + 1]) && !isvovel(s[i + 2]) && isvovel(s[i + 3]))
                ind.push_back(i + 2);
        }

        int x = 0;
        string ans = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (i == ind[x])
            {
                ans += '.';
                x++;
            }
            ans += s[i];
        }
        cout << ans << endl;

        // cout << finalans << endl;
    }
    return 0;
}
