#include <iostream>
using namespace std;

class student
{
protected:
    string name;
    int rollno;

public:
    void getdata()
    {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter rollno: ";
        cin >> rollno;
    }

    int calc_precentage(int a, int b, int c, int d)
    {
        return (a + b + c + d) / 4;
    }
};

class test1 : virtual public student
{
protected:
    int maths, eng;

public:
    test1()
    {

        cout << "Enter Maths marks: ";
        cin >> maths;
        cout << "Enter English marks: ";
        cin >> eng;
    }
};

class test2 : virtual public student
{
protected:
    int science, geog;

public:
    test2()
    {
        cout << "Enter science marks: "; // assuming each subject have 100 mks max
        cin >> science;
        cout << "Enter geography marks: ";
        cin >> geog;
    }
};

class result : public test1, public test2
{

public:
    void display_percentage()
    {
        cout << "\nName: " << name << endl;
        cout << "RollNO: " << rollno << endl;
        cout << "Percentage: " << calc_precentage(maths, eng, science, geog) << endl;
    }
};

int main()
{
    result r;
    r.getdata();
    r.display_percentage();

    // main();  // the function keep calling itself.

    return 0;
}
