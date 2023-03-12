#include "iostream"
using namespace std;
#include "vector"

int main()
{
    int m = 10, n = 5, k = -1;
    std::vector<std::vector<int>>vect( n , std::vector<int>(m,k));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << vect[i][j] << " ";
        }
        cout << endl;
    }
    

    return 0;
}