#include "iostream"
using namespace std;

#include <vector>

void display(vector<int> vec)
{
    cout << "The elements are: ";
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> vec1;
    vec1.push_back(1);
    vec1.push_back(2);
    vec1.push_back(3);

    display(vec1);

    vec1.pop_back();

    display(vec1);
}