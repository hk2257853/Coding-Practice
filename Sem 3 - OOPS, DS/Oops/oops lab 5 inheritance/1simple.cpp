#include "iostream"
using namespace std;

// I personally feel this is the most useful topic in OOPs

class Area
{
    int l, b;

public:
    Area() {}
    Area(int a, int b)
    {
        cout << "A cons" << endl;
        l = a;
        this->b = b;
    }

protected:
    int area()
    {
        return l * b;
    }
};

class Volume : public Area // by default private
{
private:
    int h;

public:
    Volume() {}
    Volume(int a, int b, int c) : Area(a, b)
    {
        cout << "V cons" << endl;
        h = c;
    }

    int volume()
    {
        return area() * h; // area should be public or protected
    }
};

int main()
{
    Volume v(5, 8, 3);
    cout << v.volume() << endl;
    // cout << v.area(); // public req
}

/*
public: accessible to all
private: accessible to only the class
protected: accessible to the class and its derived classes. If volume was protected, I won't be able to use in main.
*/