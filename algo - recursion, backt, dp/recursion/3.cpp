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

void printallsubsets(vector<int> &vec,int size, vector<int> &s_set, int index, int target, int sum)
{
    if(index == size)
    {
        if(target == 0) ans.push_back(s_set);
        return;
    }    
    
    if(vec[index] <= target)
    {
        s_set.push_back(vec[index]);
        printallsubsets(vec, size, s_set, index, target - vec[index], sum);
        // don't increase the index till I can include...
        s_set.pop_back();
    }
    printallsubsets(vec, size, s_set, index + 1, target, sum);

    // s_set.pop_back(); //without this it doesn't work
}

int main()
{
    vector<int> vec = {2, 3, 6, 7}, s_set;
    int target = 6;
    printallsubsets(vec, vec.size(), s_set, 0, target, 0);

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