#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"
#include "unordered_map"
#include "map"
#include "set"

int main()
{
    set<int> mp;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        mp.insert(2 * i);
    }
    
    for(auto &x: mp)
    {
        cout << x << endl;
    }
}