#include "iostream"
using namespace std;

void display(string sec)
{
    string::iterator it;
    cout << "The string is: ";
    for (it = sec.begin(); it != sec.end(); it++)
    {
        cout << *it;
    }
    cout << endl;
}
int main()
{
    string s1 = "hello";
    display(s1);
}
