#include "iostream"
using namespace std;

#include <deque>

void display(deque<int> dq)
{
    deque<int>::iterator it;
    cout << "The elements are: ";
    for (it = dq.begin(); it != dq.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    deque<int> dq1;

    dq1.push_back(1);
    dq1.push_back(2);
    dq1.push_front(3);
    dq1.push_front(4);
    display(dq1);

    dq1.pop_back();
    dq1.pop_front();
    display(dq1);
}