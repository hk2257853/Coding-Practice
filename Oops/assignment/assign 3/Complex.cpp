#include "iostream"
using namespace std;

class Complex
{
private:
    int Real, img;

public:
    Complex() {}
    Complex(int a, int b)
    {
        Real = a;
        img = b;
    }

    friend Complex operator+(int r, Complex &c)
    { // if I write  int &c1, it gives error
        Complex temp;
        temp.Real = r + c.Real;
        temp.img = r + c.img;
        return temp;
    }

    friend Complex operator+(Complex &c2, int c1);

    void Displaimg()
    {
        cout << "Real: " << Real << endl;
        cout << "img: " << img << endl;
    }
};

Complex operator+(Complex &c2, int c1)
{
    Complex temp;
    temp.Real = c1 + c2.Real;
    temp.img = c1 + c2.img;
    return temp;
}

int main()
{
    Complex c1(5, 8), c2(1, 3), c3;

    c3 = 5 + c1;
    c3.Displaimg();

    return 0;
}
