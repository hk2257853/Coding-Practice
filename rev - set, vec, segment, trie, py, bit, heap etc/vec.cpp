#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"

int main()
{
    vector<int> vec;
    vec.push_back(8);
    vec.push_back(2);
    vec.push_back(3);
    reverse(vec.begin(), vec.end());
    sort(vec.begin(), vec.end());

    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}

// 2d vector. Putting empty vector in reach row
// vector<vector<int>> vec(n, vector<int>()); // I need ()
