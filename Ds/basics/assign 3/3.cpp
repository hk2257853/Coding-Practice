#include "iostream"
using namespace std;

class DB;

class DM
{
private:
    float meter, centmeter;

public:
    DM() {}
    DM(float a, float b)
    {
        meter = a;
        centmeter = b;
    }

    friend DB operator+(DM &c2, DM &c1);
    friend DM operator+(DB &c2, DB &c1);

    void DisplayDM()
    {
        cout << "meter: " << meter << endl;
        cout << "centmeter: " << centmeter << endl;
    }
};

class DB
{
private:
    float feet, inches;

public:
    friend DB operator+(DM &c2, DM &c1);
    friend DM operator+(DB &c2, DB &c1);

    DB() {}
    DB(float a, float b)
    {
        feet = a;
        inches = b;
    }
    void DisplayDB()
    {
        cout << "feet: " << feet << endl;
        cout << "inches: " << inches << endl;
    }
};

DM operator+(DB &c2, DB &c1)
{
    DM temp;
    temp.meter = (c1.feet + c2.feet) * 0.3048;
    temp.centmeter = temp.meter * 100;
    return temp;
}

DB operator+(DM &c2, DM &c1)
{
    DB temp;
    temp.feet = (c1.meter + c2.meter) / 0.3048;
    temp.inches = temp.feet * 12;
    return temp;
}

int main()
{
    DM m1(5, 8), m2(1, 3), m3;
    DB b1(5, 8), b2(1, 3), b3;

    m3 = b1 + b2;
    b3 = m1 + m2;
    m3.DisplayDM();
    b3.DisplayDB();

    return 0;
}
