#include "iostream"
using namespace std;

#include <list>
#include <iterator>

void display(list<int> lst)
{
    list<int>::iterator it;
    cout << "The elements are: ";
    for (it = lst.begin(); it != lst.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    list<int> list1;
    list1.push_back(1);
    list1.push_back(2);
    list1.push_front(3);

    display(list1);

    list1.sort();
    display(list1);
}