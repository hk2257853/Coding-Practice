#include "iostream"
using namespace std;

int main()
{
    int capacity = 10;
    int weight[] = {5, 4, 6, 3}, value[] =  {10, 40, 30, 50};
    int arrsize = sizeof(weight) / sizeof(weight[0]);
    int table[capacity + 1];

    // base case
    for (int i = 0; i <= capacity; i++)
    {
        table[i] = 0;
    }
    
    // core algo remainded same. On diff is how 1D matrix is used to get it done.
    for (int i = 1; i <= arrsize; i++) // for each weight I'll be filling the table...
    {
        for (int j = capacity; j > 0; j--) // need to fill right to left... 
        {                                 // as I wanna reuse this array b4 modifying
            // I dont take it
            int donot_takevalue = table[j];
            // I take it
            int takevalue = 0;
            if (j >= weight[i - 1]) 
            {
                takevalue = value[i - 1];
                int remainingcap = j - weight[i - 1];
                takevalue += table[remainingcap];
            }
            
            table[j] = max(takevalue, donot_takevalue);
        }
    }

    cout << table[capacity] << endl << endl;

    // print
    for (int i = 0; i <= capacity; i++)
    {
        cout << table[i] << " ";            
    }
    return 0;
}

// coding part is very easy.
// Need to comfortable with 2D matrix
// Just see what I want in words n then its very easy to access that.