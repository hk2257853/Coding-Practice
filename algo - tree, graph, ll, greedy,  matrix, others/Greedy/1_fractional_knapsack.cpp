// video: apna college
// article: gfg

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

bool cmp(struct item a, struct item b) // I want it to sort wrt value/weight
{                                   
    double r1 = a.value / a.weight;
    double r2 = b.value / b.weight;
    return r1 > r2;
}

// algo says get value / weight to get the actual value... (like distance / time stuff)
// using greedy... I'll take the higher ratios 1st...

double fractional_knapsack(int W, struct item arr[], int n)
{
    sort(arr, arr + n, cmp);
    // The 3rd argument is a comparision function.
    // Ask this: if I have 2 nos a n b... which one of these 1st appear in the list?
    // see cherno's sorting in c++ video for more info.

    int currentweight = 0;
    double finalvalue = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (currentweight + arr[i].weight <= W)
        {
            currentweight += arr[i].weight;
            finalvalue += arr[i].value;
        }
        else // Once I can't take in full... just take a fraction of it...
        {
            int remain = W - currentweight;
            finalvalue += remain * arr[i].value / arr[i].weight;
            // 2:17 in video... its like unitry method...
            break;
        }
    }

    return finalvalue;
    
}

int main()
{
    //int W = 50; // capacity of knapsack
    int W = 20;
    // item arr[] = {{60, 10}, {100, 20}, {120, 30}};
    item arr[] = {{40, 5}, {24, 4}, {30, 6}, {21, 7}, {12, 6}};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << fractional_knapsack(W, arr, n);
}