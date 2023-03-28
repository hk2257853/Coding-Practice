#include "iostream"
using namespace std;

class Student
{
    int Rollno;
    string Name, Department, address;
    int marks[5];

public:
    void inputdata(int i);
    void getdata(int RollNO, string name, string Dept, string adrs, int marks[5]);
    void printdata()
    {
        cout << "Roll number :" << Rollno << "\n";
        cout << "Name :" << Name << "\n";
        cout << "Department :" << Department << "\n";
        cout << "Address :" << address << "\n";
        cout << "marks:";
        for (int i = 0; i < 5; i++)
        {
            cout << marks[i] << " ";
        }
        cout << "\n";
        float sum = 0;

        for (int i = 0; i < 5; i++)
        {
            sum = sum + marks[i];
        }
        cout << "percentage:\n"
             << sum / 5 << "\n"; // assuming 500 is total marks
    }
};
Student *a;

void Student::getdata(int RollNO, string name, string Dept, string adrs, int data[5])
{
    Rollno = RollNO;

    Name = name;
    Department = Dept;
    address = adrs;
    for (int i = 0; i < 5; i++)
    {
        marks[i] = data[i];
    }
}

void Student::inputdata(int i)
{
    cout << "student " << i + 1 << " info\n";
    int roll;
    string name, Dept, add;
    int data[5];

    cout << "Enter RollNo\n";
    cin >> roll;
    cout << "Enter Name\n";
    cin >> name;
    cout << "Enter Department\n";
    cin >> Dept;
    cout << "Enter address\n";
    cin >> add;

    for (int i = 0; i < 5; i++)
    {
        cout << "Enter Marks "
             << i + 1 << "\n";
        cin >> data[i];
    }

    a[i].getdata(roll, name, Dept, add, data);
}

int main()
{
    int TStudents;
    cout << "Enter total students:\n";
    cin >> TStudents;
    a = new Student[TStudents]; // DMA

    for (int i = 0; i < TStudents; i++)
    {
        a[i].inputdata(i);
    }

    for (int i = 0; i < TStudents; i++)
    {
        a[i].printdata();
    }
    delete a; // deleting a

    // had to make printdata function part of class. Otherwise was priting garbage values.

    return 0;
}
