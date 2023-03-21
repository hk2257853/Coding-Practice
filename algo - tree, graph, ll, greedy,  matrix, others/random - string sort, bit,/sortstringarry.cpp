#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"

int main()
{
    vector<string> v = {"adb", "acd", "abc", "abd", "z", "az", "ab"}; // ab comes before abc, az is 2nd last
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
}