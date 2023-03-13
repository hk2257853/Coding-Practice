#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"
#include "climits"

void soln(vector<vector<int>> alloc, vector<vector<int>> currentneed, vector<int>avail, int n, int m)
{
    vector<int> isvisited(n, 0), seq;

    while (seq.size() < n)
    {
        bool isdead = true; // incase not a single process can be exec
        for (int i = 0; i < n; i++)
        {
            if(!isvisited[i])
            {
                int j = 0;        
                for (; j < m; j++)
                {
                    if(currentneed[i][j] > avail[j]) break;
                }

                if(j == 3) // all done. j will be 3 at end not 2! It just won't run for 3!!
                {
                    for (int j = 0; j < m; j++)
                    {
                        avail[j] += alloc[i][j]; // add alloc here!
                    }
                    seq.push_back(i);  
                    isvisited[i] = 1;
                    isdead = false;          
                }
            }
        }

        if(isdead) 
        {
            cout << "deadlock" << endl;
            break;
        }        
    }

    cout << seq.size() << endl;

    for (int i = 0; i < n; i++)
    {
        cout << seq[i] << " ";
    }

}


int main()
{
    int m, n;
    cin >> n >> m; // I took m n (wrong imp)
    vector<vector<int>> alloc(n, vector<int>(m)), maxneed(n, vector<int>(m)), currentneed(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> alloc[i][j];
        }        
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> maxneed[i][j];
        }        
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            currentneed[i][j] = maxneed[i][j] - alloc[i][j];
        }        
    }

    vector<int> avail(m);

    for (int i = 0; i < m; i++)
    {
        cin >> avail[i];
    }
    
    soln(alloc, currentneed, avail, n, m);

}
