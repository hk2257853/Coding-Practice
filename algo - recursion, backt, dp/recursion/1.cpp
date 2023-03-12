#include <iostream>
using namespace std;
#include <vector>

// Working!!
/*
    TODO:
    Subset sum to a target (see if backtracking can do it... keep eye for greedy)
*/

void sumallsubsets(vector<int> &vec,int size, vector<int> &ans, int index, int sum)
{
    if(index == size)
    {
        ans.push_back(sum);
        return;
    }

    sumallsubsets(vec, size, ans, index + 1, sum + vec[index]);
    sumallsubsets(vec, size, ans, index + 1, sum);
}

int main()
{
    vector<int> vec = {3, 2, 1}, ans;
    sumallsubsets(vec, vec.size(), ans, 0, 0);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    

    return 0;
}