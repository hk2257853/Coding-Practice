#include "iostream"
using namespace std;

class Complex
{
private:
    int Real, img;

public:
    Complex()
    {
    }
    Complex(int a, int b)
    {
        cout << "Enter Real value: " << endl;
        cin >> Real;
        cout << "Enter imaginary value: " << endl;
        cin >> img;
    }

    friend Complex operator+(Complex &c1, Complex &c2);

    void Displaimg()
    {
        cout << "Real: " << Real << endl;
        cout << "img: " << img << endl;
    }
};

Complex operator+(Complex &c1, Complex &c2)
{
    Complex temp;
    temp.Real = c1.Real + c2.Real;
    temp.img = c1.img + c2.img;
    return temp;
}

int main()
{
    Complex c1(5, 8), c2(1, 3), c3;

    c3 = c2 + c1;
    c3.Displaimg();

    return 0;
}
