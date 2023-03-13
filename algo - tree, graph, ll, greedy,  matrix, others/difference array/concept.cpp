// Video: Range addition by prep code

#include "iostream"
using namespace std;
#include "vector"

int main()
{
    int size;
    cin >> size;
    vector<int> vec, diff(size + 1, 0); // last index is useless. I can use an if and eliminate the need of taking size+1 
    int x;
    while (size--)
    {
        cin >> x;
        vec.push_back(x);
    }

    int k;
    cin >> k;

    while (k--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        diff[a] += c; // Algo Step1: add at a and sub at b+1.
        diff[b + 1] -= c; 
        // so O(1)
    }

    // Step2: prefix sum of diff array
    for (int i = 1; i < diff.size(); i++)
    {
        diff[i] += diff[i - 1];
    }
    
    // Step3: add with vec
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] + diff[i] << " ";
    } 
}

/*
TC:
O(1) for ranged addition
there r k querries and I need to take prefix sum at end, so O(n+k)
brute force would have been O(n*k)

issue: here we took sum at the end. If we want sum in between - O(n) each time

I am skipping segment n fedwick tree. Diff array will be usefull for interviews (something better than nothing)
Can use templates from net for CP: https://leetcode.com/problems/range-sum-query-mutable/description/  (Diff array won't work. This is completely diff)
there's ranged sum querry immutable - can be done using prefix sum.
*/

