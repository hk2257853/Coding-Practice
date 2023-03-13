#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

class Solution
{
public:
    vector<string> ans;
    string dir = "LRUD";

    void solve(int row, int col, string &path, vector<vector<int>> &m, int n)
    {
        // base
        if (row < 0 || col < 0 || row >= n || col >= n || m[row][col] == 0) // is safe covered
            return;
        if (row == n - 1 && col == n - 1)
        {
            ans.push_back(path);
            return;
        }

        for (int i = 0; i < 4; i++) // for loop and if(dir) can be simplified (see other people's soln on gfg)
        {
            path.push_back(dir[i]);
            m[row][col] = 0; // I didn't write this part! this is the main part acutally, path is just a ans string (passed like in subset prob)
            if (dir[i] == 'D')
                solve(row + 1, col, path, m, n);
            if (dir[i] == 'R')
                solve(row, col + 1, path, m, n);
            if (dir[i] == 'U')
                solve(row - 1, col, path, m, n);
            if (dir[i] == 'L')
                solve(row, col - 1, path, m, n);
            m[row][col] = 1;
            if (path.size())
                path.pop_back();
        }
        // I did based on my knowledge of sudoku and n queens, I am really happy I was able to solve this!
    }

    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        // Your code goes here
        string path = "";
        solve(0, 0, path, m, n);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends