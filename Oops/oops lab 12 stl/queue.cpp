#include "iostream"
using namespace std;

#include <queue>

int main()
{
    queue<int> qu1;

    qu1.push(1);
    qu1.push(2);
    qu1.push(3);
    qu1.push(4);

    cout << "The elements are: ";
    while (!qu1.empty())
    {
        cout << qu1.front() << " ";
        qu1.pop();
    }
}