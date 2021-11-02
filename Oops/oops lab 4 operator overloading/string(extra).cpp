#include "iostream"

using namespace std;

int main()
{
    // doen't work for all cases
    string s1 = "a";
    string s2 = "b";

    if (s1 > s2)
    {
        cout << "s1 is greater";
    }
    else if (s1 < s2)
    {
        cout << "s2 is greater";
    }
    else if (s1 == s2)
    {
        cout << "equal";
    }
}