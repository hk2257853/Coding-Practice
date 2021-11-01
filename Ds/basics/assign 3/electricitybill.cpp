#include "iostream"
using namespace std;

class bill
{
    string name;
    int charge_rupees = 0, powerconsumed = 0;

public:
    bill()
    {
        cout << "Enter name" << endl;
        cin >> name;
        cout << "Enter power consumed" << endl;
        cin >> powerconsumed;
        calculatecharge_rupees();
    }

    void calculatecharge_rupees()
    {
        if (powerconsumed <= 100)
        {
            charge_rupees = 60 * powerconsumed / 100;
            if (charge_rupees < 50)
            {
                charge_rupees = 50;
            }
        }
        else if (powerconsumed > 100 && powerconsumed <= 300)
        {
            powerconsumed = powerconsumed - 100;
            charge_rupees = 60 + (powerconsumed * 80 / 100);
        }
        else
        {
            powerconsumed = powerconsumed - 300;
            charge_rupees = 220 + (powerconsumed * 90 / 100);
            if (charge_rupees > 300)
            {
                int fifperc = charge_rupees * 15 / 100;
                charge_rupees = charge_rupees + fifperc;
            }
        }
    }

    void display()
    {
        cout << "Name " << name << endl;
        cout << "Power consumed " << powerconsumed << endl;
        cout << "Bill " << charge_rupees << endl;
    }
};

int main()
{
    bill a;
    a.display();
    return 0;
}