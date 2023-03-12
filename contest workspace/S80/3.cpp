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

        vector<int> vec;
        int size, x, size2;
        cin >> size;
        size2 = size;
        while (size)
        {
            size--;
            cin >> x;
            vec.push_back(x);
        }

        vector<int> vec2;
        int x2;
        while (size2)
        {
            size2--;
            cin >> x2;
            vec2.push_back(x2);
        }

        int count = 0;
        for (int i = 0; i < vec.size(); i++)
        {
            if (vec[i] > 2 * vec2[i] || vec2[i] > 2 * vec[i])
                ;
            else
                count++;
        }

        cout << count << endl;
    }
    return 0;
}
