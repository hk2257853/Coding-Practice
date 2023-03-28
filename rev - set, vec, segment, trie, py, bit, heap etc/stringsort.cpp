#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"

int main()
{
    vector<string> arr = {"acd", "acb", "zabcdef", "ac", "adbc"};
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    // OP:
    // ac acb acd adbc zabcdef
}
