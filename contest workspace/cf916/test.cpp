#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void findThreeLargestElements(const vector<int> &vec, pair<int, int> &a, pair<int, int> &b, pair<int, int> &c)
{
    int n = vec.size();

    // Create a vector of pairs (value, index)
    vector<pair<int, int>> indexedVec;
    for (int i = 0; i < n; i++)
    {
        indexedVec.push_back({vec[i], i});
    }

    // Sort the vector of pairs in ascending order based on values
    sort(indexedVec.begin(), indexedVec.end(), greater<pair<int, int>>());

    // Extract the three largest elements along with their indices
    a = indexedVec[0];
    b = indexedVec[1];
    c = indexedVec[2];
}

int main()
{
    // Example usage with a vector
    vector<int> vec = {1, 3, 3, 4};

    // Variables to store the three largest elements as pairs (value, index)
    pair<int, int> max1, max2, max3;

    // Call the function to find three largest elements
    findThreeLargestElements(vec, max1, max2, max3);

    // Print the three largest elements
    cout << "The three largest elements are (" << max1.first << ", " << max1.second << "), "
         << "(" << max2.first << ", " << max2.second << "), and "
         << "(" << max3.first << ", " << max3.second << ")" << endl;

    return 0;
}
