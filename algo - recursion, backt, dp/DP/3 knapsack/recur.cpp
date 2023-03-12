#include <iostream>
using namespace std;

// this one is exactly like anuj's. From net

// Returns the maximum value that can be put in a knapsack of capacity W 
int knapsackRecursive(int profits[], int profitsLength, int weights[], int capacity, int currentIndex) {
  // Base Case 
  if (capacity <= 0 || currentIndex >= profitsLength || currentIndex < 0)
    return 0;

  // If weight of the nth item is more than Knapsack capacity W, then 
  // this item cannot be included in the optimal solution
  int profit1 = 0;  // I could put 2 if statements n do it separately like the gfg one... But this is small n clean
  if (weights[currentIndex] <= capacity) // taking it
    profit1 = profits[currentIndex] + knapsackRecursive(profits, profitsLength, weights, capacity - weights[currentIndex], currentIndex + 1);
              // I always forget to add this!                                                                          // remaining weight
  int profit2 = knapsackRecursive(profits, profitsLength, weights, capacity, currentIndex + 1);

  // Return the maximum of two cases:  
  // (1) nth item included  
  // (2) not included 
  return max(profit1, profit2);
}

int knapSack(int profits[], int profitsLength, int weights[], int capacity) {
  return knapsackRecursive(profits, profitsLength, weights, capacity, 0);
}

int main() {
  int profits[] = {1, 6, 10, 16}; // The values of the jewelry
  int weights[] = {1, 2, 3, 5}; // The weight of each
  cout << "Total knapsack profit = " << knapSack(profits, 4, weights, 7) << endl;
  cout << "Total knapsack profit = " << knapSack(profits, 4, weights, 6) << endl;
}