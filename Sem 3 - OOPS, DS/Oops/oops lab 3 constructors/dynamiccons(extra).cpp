#include <iostream>
using namespace std;
// dynamic object, cons, des
int check;

class code
{
    int value;

public:
    int *a;
    int x = 10;
    code()
    {
        a = new int;
        a = &x;
        cout << "Object value " << *a << endl;
    }

    ~code()
    {
        cout << "deleting object with value " << *a << endl;
        delete a;
        //  cout << *a << endl;
    }
};

int main()
{
    code *a = new code;
}
