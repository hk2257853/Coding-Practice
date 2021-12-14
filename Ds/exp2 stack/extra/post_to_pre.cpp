#include "iostream"
#define MAX 100
using namespace std;

// Done on my own

int ind = -1;
string stack[MAX];

void push(string c)
{
    ind++;
    stack[ind] = c;
}

string pop()
{
    string temp = stack[ind];
    ind--;
    return temp;
}

void input()
{
    string str = "abc/-ad/e-*";
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            string a = pop();
            string b = pop();
            push(str[i] + b + a);
        }
        else
        {
            string s(1, str[i]);
            push(s);
        }
    }
}

int main()
{
    input();
    cout << stack[ind];
    return 0;
}