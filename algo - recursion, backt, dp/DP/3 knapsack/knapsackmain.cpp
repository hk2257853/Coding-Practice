#include "iostream"
using namespace std;

int main()
{
        int w = 10;
        int n = 4;
        int val[] = {10, 40, 30, 50};
        int wt[] = {5, 4, 6, 3};

        // Populate base cases
        int mat[n + 1][w + 1];
        for (int r = 0; r < w + 1; r++) {
            mat[0][r] = 0;
        }
        for (int c = 0; c < n + 1; c++) {
            mat[c][0] = 0;
        }


        // Main logic
        for (int item = 1; item <= n; item++) {
            for (int capacity = 1; capacity <= w; capacity++) {
                int maxValWithoutCurr = mat[item - 1][capacity]; // This is guaranteed to exist
                int maxValWithCurr = 0; // We initialize this value to 0
                
                int weightOfCurr = wt[item - 1]; // We use item -1 to account for the extra row at the top
                if (capacity >= weightOfCurr) { // We check if the knapsack can fit the current item
                    maxValWithCurr = val[item - 1]; // If so, maxValWithCurr is at least the value of the current item
                    
                    int remainingCapacity = capacity - weightOfCurr; // remainingCapacity must be at least 0
                    maxValWithCurr += mat[item - 1][remainingCapacity]; // Add the maximum value obtainable with the remaining capacity
                }
                
                mat[item][capacity] = max(maxValWithoutCurr, maxValWithCurr); // Pick the larger of the two
            }
        }
        
        cout << mat[n][w] << endl << endl; // Final answer
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= w; j++)
            {
                cout << mat[i][j] << " ";
            }
            cout << endl;            
        }

        // System.out.println(Arrays.deepToString(mat)); // Visualization of the table
    
}
