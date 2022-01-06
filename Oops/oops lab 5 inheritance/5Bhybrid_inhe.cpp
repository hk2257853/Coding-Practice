#include <iostream>
using namespace std;

class student
{
protected:
    string name;
    int rollno;

public:
    student()
    {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter rollno: ";
        cin >> rollno;
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

    void displaytest1()
    {
        cout << "maths marks";
        cout << maths << endl;
        cout << "eng marks";
        cout << eng << endl;
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

    void displaytest2()
    {
        cout << "science marks";
        cout << science << endl;
        cout << "geog marks";
        cout << geog << endl;
    }
};

class result : public test1, public test2
{

public:
    void display_percentage()
    {
        cout << "\nName: " << name << endl;
        cout << "RollNO: " << rollno << endl;
        displaytest1();
        displaytest2();
        cout << "Percentage: " << (maths + eng + science + geog) / 4 << endl;
    }
};

int main()
{
    result r;
    // r.getdata();
    r.display_percentage();

    // main();  // the function keep calling itself.

    return 0;
}

// Changes: display marks. take name roll no 1st
