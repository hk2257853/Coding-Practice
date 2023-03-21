#include "iostream"
using namespace std;
#include "vector"

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> vec(n, vector<int>()); // I need ()

    for (int i = 0; i < n; i++)
    {
        if(i == 0)
        {
            vec[i].push_back(1);
            continue;
        }
        int j = 1;
        
        vec[i].push_back(1);
        while (j < vec[i-1].size())
        {
            vec[i].push_back(vec[i-1][j]+vec[i-1][j-1]);
            j++;
        }
        vec[i].push_back(1);        
    }
    
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }

    // this is normal BF
    // ig a better method can exist if there's a formula to predict... still it will be same TC.
}
