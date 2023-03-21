#include "iostream"
using namespace std;
#include "vector"

// lol can't believe having trouble in printing subarrays!

int main()
{
    int n;
    cin >> n;
    vector<int> vec;

    for (int i = 1; i <= n; i++)
    {
        vec.push_back(i);
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++) // I want to print between i to j, so 1 more loop req... 
            {
                sum += vec[k];                
                cout << vec[k] << " ";
            } // confirm if this is O(n3)
            cout << "sum: " << sum << endl;
        }        
    }
    
}