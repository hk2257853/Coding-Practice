#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"
#include "unordered_map"
#include "map"

int main()
{
    map<int, int> mp;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        mp[i] = 2 * i;
    }
    
    for(auto &x: mp)
    {
        cout << x.first << " " << x.second << endl;
    }

    if(mp.find(2) != mp.end())
    {
        cout << "hoi re" << endl;
    }
    else cout << "na re" << endl;
   
    if(mp.count(3)) cout << "hoi re" << endl;
    else cout << "nope boi" << endl;


}