// For practice later
// This is how ques will be. Just write my soln now.

#include "iostream"
using namespace std;
#include "algorithm"

struct item
{
    double value, weight;
    
    item(double value, double weight) // We can make contructor in structure in cpp!
    {
        this->value = value;
        this->weight = weight;
    }
};

int main()
{
    int W = 50; // capacity of knapsack
    item arr[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(arr) / sizeof(arr[0]);

}