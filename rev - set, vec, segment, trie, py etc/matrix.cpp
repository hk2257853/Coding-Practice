#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> vec(m, vector<int>(n, 1));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
    cout << "back: " << vec.back()[0] << endl;

    pair<int, int> p;
    p = {1, 2};
    cout << p.first << " " << p.second << endl;

    vector<pair<int, int>> pvec;
    pvec.push_back({2, 3});
    pvec.push_back(p);

    for (int i = 0; i < pvec.size(); i++)
    {
        cout << pvec[i].first << endl;
    }
    
    cout << "back in pair: " << pvec.back().first << endl; 
    
    // sorting will sort it wrt 1st element of pair. Can use custom comparator to sort wrt 2nd element
    

}
