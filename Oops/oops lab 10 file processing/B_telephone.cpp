#include <iostream>
#include <fstream>
using namespace std;

class Telephone
{
public:
    void addtofile()
    {
        ofstream fout;
        string name;
        int number;

        fout.open("telephone.txt", ios::app); // append to end of file
        cout << "Enter name: ";               // otherwise data will get deleted
        cin >> name;
        cout << "Enter phone number: "; // I can use I/O manipulators to make it look clean.
        cin >> number;
        fout << name << " " << number << endl;
        fout.close();
    }

    void displayfile()
    {
        cout << "Phonebook data: " << endl;
        int n = 30;
        char line[n];
        ifstream fin;
        fin.open("telephone.txt");
        while (fin)
        {
            fin.getline(line, n);
            cout << line << endl;
        }
        fin.close();
    }

    void update() // checkout how other did this part
    {
        cout << "Enter name" << endl;
        string name;
        cin >> name;
        int n = 30;
        char line[n];
        ifstream fin;
        fin.open("telephone.txt");
        while (fin)
        {
            fin.getline(line, name.size());
            if (!name.compare(line))
            {
                cout << "Found!!!";
            }
        }
        fin.close();
    }
};

int main()
{
    while (1)
    {
        cout << "1 Add to telephone book" << endl;
        cout << "2 Display telephone book" << endl;
        cout << "3 Update in telephone book" << endl;

        int input;
        cout << "Enter from option: ";
        cin >> input;
        Telephone Tobj;
        switch (input)
        {
        case 1:
            Tobj.addtofile();
            break;
        case 2:
            Tobj.displayfile();
            break;
        case 3:
            Tobj.update();
            break;

        default:
            break;
        }
        cout << "\n";
    }
}