#include <iostream>
using namespace std;
#include <iomanip>

int i;
ostream &DollarToRupees(ostream &op)
{
    float rupees;
    op << "$ = ";
    op << setiosflags(ios::showpos);
    rupees = i * 74.52;
    op << rupees;
    op << resetiosflags(ios::showpos);
    op << " Rs";
    return op;
}

int main()
{
    for (i = 1; i < 3; i++)
    {
        cout << i << DollarToRupees << endl;
    }
}
