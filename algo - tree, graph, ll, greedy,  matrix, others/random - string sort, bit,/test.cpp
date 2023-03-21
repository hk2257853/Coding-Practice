#include "iostream"
#include "string"
using namespace std;

string simplifyPath(string A)
{
    int s = A.size();
    int j = s - 2;
    string temp = "";
    while (A[j] != '/')
    {
        string s(1, A[j]);
        temp.insert(0, s);
        j--;
    }
    temp.insert(0, "/");

    return temp;
}

int main()
{
}