#include <iostream>
using namespace std;

int main()
{
    string a = "hel";
    string b = "hello";

    if (!a.compare(b))
        cout << "equal";
}