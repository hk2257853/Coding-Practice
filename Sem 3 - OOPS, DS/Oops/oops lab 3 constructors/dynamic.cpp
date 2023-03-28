#include "iostream"
using namespace std;

class Dynamic
{
    int *p;
    int size;

public:
    Dynamic(int n) // dynamic constructor
    {
        size = n;
        p = new int[size]; // dynamically allocated in cons
    }
    ~Dynamic()
    {
        cout << "Destructor called" << endl;
        cout << p[0] << endl;
        delete[] p;
        cout << p[0] << endl;
    }
    void getdata()
    {
        for (int i = 0; i < size; i++)
        {
            p[i] = i + 11;
        }
    }
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << p[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Dynamic d(5);
    d.getdata();
    d.display();
    return 0;
}
