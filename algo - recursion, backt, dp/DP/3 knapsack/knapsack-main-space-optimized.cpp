#include "iostream"
using namespace std;

int main()
{
        int w = 10;
        int n = 4;
        int val[] = {10, 40, 30, 50};
        int wt[]= {5, 4, 6, 3};

        // Populate base cases
        int mat[w + 1];
        for (int r = 0; r < w + 1; r++) 
        {
            mat[r] = 0;
        }
        // Main logic
        for (int item = 1; item <= n; item++) {
            for (int capacity = w; capacity >= 1; capacity--) {
                int maxValWithoutCurr = mat[capacity]; // We have not written anything to the array,
                                                       // so it represents the values from the "previous row"
                int maxValWithCurr = 0; // We initialize this value to 0
                
                int weightOfCurr = wt[item - 1]; // We use item -1 to account for the extra row at the top
                if (capacity >= weightOfCurr) { // We check if the knapsack can fit the current item
                    maxValWithCurr = val[item - 1]; // If so, maxValWithCurr is at least the value of the current item
                    
                    int remainingCapacity = capacity - weightOfCurr; // remainingCapacity must be at least 0
                    maxValWithCurr += mat[remainingCapacity]; // Add the maximum value obtainable with the remaining capacity
                                                              // Again, recall that the array is still an intact representation of the "previous row"
                }
                
                mat[capacity] = max(maxValWithoutCurr, maxValWithCurr); // Pick the larger of the two
                        for (int r = 0; r < w + 1; r++) {
            cout << mat[r] << " ";
        }
        cout << endl;

            }
        }
        
        cout << mat[w];
    
}