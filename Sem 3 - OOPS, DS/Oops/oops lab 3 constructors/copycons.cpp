#include <iostream>
using namespace std;

class code
{
private:
    int x;

public:
    code(int a)
    {
        x = a;
    }

    code(code &ob) // copy constructor: takes object as argument and copies it.
    {
        x = ob.x;
    }
    void display()
    {
        cout << x << endl;
    }
};

int main()
{
    code A(10);
    code B(A); // B is a copy of A

    A.display();
    B.display();

    return 0;
}
