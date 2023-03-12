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
        int n;
        cin >> n;
        if (n % 2)
        {
            cout << "-1" << endl;
            continue;
        }

        vector<int> vec;
        for (int i = 1; i <= n; i++)
        {
            vec.push_back(i);
        }

        for (int i = 0; i < vec.size(); i += 2)
        {
            swap(vec[i], vec[i + 1]);
        }

        for (int i = 0; i < vec.size(); i++)
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
