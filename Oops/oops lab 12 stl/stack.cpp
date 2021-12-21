#include "iostream"
using namespace std;

#include <stack>

// go through theory breifly
//(on which ones we can use iterator, which ones r random access, linear...)

int main()
{
    stack<int> st1;

    st1.push(1);
    st1.push(2);
    st1.push(3);
    st1.push(4);

    cout << "The elements are: ";
    while (!st1.empty())
    {
        cout << st1.top() << " ";
        st1.pop();
    }
}