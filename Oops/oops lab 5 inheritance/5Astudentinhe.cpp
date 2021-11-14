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

public:
};

class arts : public student
{
private:
    int sketch, colortheory;

public:
    arts()
    {
        cout << "Enter sketch marks: ";
        cin >> sketch;
        cout << "Enter colortheory marks: ";
        cin >> colortheory;
    }

    void displayinfo()
    {
        cout << "\nName: " << name << endl;
        cout << "RollNO: " << rollno << endl;
        cout << "sketch marks: " << sketch << endl;
        cout << "color theory marks: " << colortheory << endl;
    }
};

class engineering : public student
{
protected:
    int math, workshop;
};

class medical : public student
{
public:
    int biology, pyschology;
};

class mech : public engineering
{
public:
    int thermodynamics, mechanics;
};

class comp : public engineering
{
public:
    int OOPs, DS;
};

class etc : public engineering
{
public:
    int digital_electronics, wavetheroy;
};

class it : public engineering
{
public:
    int software_design_principles, DS;
};

int main()
{
    arts a; // use array of objects later
    a.getdata();
    a.displayinfo();
}
