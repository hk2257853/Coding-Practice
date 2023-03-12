#include <iostream>
using namespace std;
#include <vector>

/*
    there r 2 more ways to do this (striver's). I am doing luv's
    1 more: in that they generated all binary combinations:
    https://www.techiedelight.com/print-distinct-subsets-given-set/
    if input is like 1, 2, 2 - duplicates r produced... just put in a set n get it done.
*/

vector<vector<int>> ans;

void printallsubsets(vector<int> &vec,int size, vector<int> &s_set, int index)
{
    if(index == size)
    {
        ans.push_back(s_set);
        return;
    }

    printallsubsets(vec, size, s_set, index + 1);
    s_set.push_back(vec[index]);
    printallsubsets(vec, size, s_set, index + 1);
    s_set.pop_back(); //without this it doesn't work
    // see 8:43 in luv's video. it feels like preorder.

    // If I don't pass by reference, I get the correct ans without pop... but it will be tle as each time its copies...
}

int main()
{
    vector<int> vec = {1, 2, 3}, s_set;
    printallsubsets(vec, vec.size(), s_set, 0);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    

    return 0;
}