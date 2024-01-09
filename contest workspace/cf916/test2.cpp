#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Custom comparator for sorting pairs based on the first element
bool pairComparator(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first > b.first;
}

int maxSumOfSelectedPairs(const vector<vector<pair<int, int>>>& matrix) {
    int rows = matrix.size();

    // Iterate through each row and sort the pairs in descending order based on the first element
    for (int i = 0; i < rows; i++) {
        sort(matrix[i].begin(), matrix[i].end(), pairComparator);
    }

    // Initialize variables to track selected pairs and the maximum sum
    vector<pair<int, int>> selectedPairs;
    int maxSum = 0;

    // Try to select one pair from each row, ensuring the second elements are not equal
    for (int i = 0; i < rows; i++) {
        for (int j = i + 1; j < rows; j++) {
            for (int k = j + 1; k < rows; k++) {
                // Check if the second elements are not equal
                if (matrix[i][0].second != matrix[j][0].second && matrix[i][0].second != matrix[k][0].second && matrix[j][0].second != matrix[k][0].second) {
                    // Calculate the sum of the first elements and update maxSum if needed
                    int sum = matrix[i][0].first + matrix[j][0].first + matrix[k][0].first;
                    if (sum > maxSum) {
                        maxSum = sum;
                        // Update the selected pairs
                        selectedPairs = {matrix[i][0], matrix[j][0], matrix[k][0]};
                    }
                }
            }
        }
    }

    // Print the selected pairs
    cout << "Selected Pairs:" << endl;
    for (const auto& pair : selectedPairs) {
        cout << "(" << pair.first << ", " << pair.second << ") ";
    }
    cout << endl;

    return maxSum;
}

int main() {
    // Example usage with a 3x3 matrix of pairs
    vector<vector<pair<int, int>>> matrix = {
        {{1, 10}, {2, 20}, {3, 30}},
        {{4, 15}, {5, 25}, {6, 35}},
        {{7, 12}, {8, 22}, {9, 32}}
    };

    // Calculate the maximum sum and print the result
    int result = maxSumOfSelectedPairs(matrix);
    cout << "Maximum Sum: " << result << endl;

    return 0;
}
