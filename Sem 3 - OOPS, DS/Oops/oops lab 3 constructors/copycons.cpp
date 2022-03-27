#include <iostream>
using namespace std;

class code
{
    private:
    int x;

    public:
    code(int a)
    {
    x=a;
    }

    code(code &ob)
    {
    x=ob.x;
    }
    void display()
    {
    cout<<x<<endl;
    }
};

int main()
{
    code A(10);
    code B(A);

    A.display();
    B.display();

    return 0;
}
