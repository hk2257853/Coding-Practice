#include "iostream"
using namespace std;

string concatinate(string s1, string s2)
{
    return s1 + s2;
}

void compare(string s1, string s2) // wrt length or string same or not?
{
    if (s1 == s2)
        cout << "They have same length" << endl;
    else if (s1 < s2)
        cout << "s1 is smaller than s2" << endl;
    else
        cout << "s2 is smaller than s1" << endl;
}

void findsubstr(string s, string subs)
{
    int length = s.length();
    while (length > 0)
    {
        length--;
    }
}

void findchar(string s1, char c)
{
    for (int i = 0; i < s1.length(); i++)
    {
        if (s1[i] == c)
        {
            cout << "Character is present at index " << i << endl;
            return;
        }
    }

    cout << "Character is not present" << endl;
}

void swapstrings(string &s1, string &s2)
{
    string temp = s1;
    s1 = s2;
    s2 = temp;
}

int main()
{
    string s1, s2;
    cout << "Enter 2 strings: ";
    cin >> s1 >> s2;

    cout << "Concatinated string: " << concatinate(s1, s2) << endl;

    cout << "Before swapping, s1: " << s1 << " s2: " << s2 << endl;
    swapstrings(s1, s2);
    cout << "After swapping, s1: " << s1 << " s2: " << s2 << endl;

    cout << "Enter character to find: ";
    char c;
    cin >> c;
    findchar(s1, c);
}