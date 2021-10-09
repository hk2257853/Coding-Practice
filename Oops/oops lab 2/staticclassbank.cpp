#include <iostream>
using namespace std;

class user
{
private:
    int id, balance, transaction;
    char name[30];

public: //we can't access in main if private
    void Deposit();
    void Withdraw();
    void CheckBalance();
    void Authticate();
    void CreateAccount(int n);
};

user u[10];
int usrno = 0;

int main()
{
    int n;
    while (1)
    {
        cout << "BankMenu\n\n";
        cout << "1 Create Account\n";
        cout << "2 Deposit\n";
        cout << "3 Withdraw\n";
        cout << "4 Checkbalance\n";
        cout << "5 Exit\n";
        cout << "Enter from options:\n";

        cin >> n;
        int id = 0;
        switch (n)
        {
        case 1: //think of the best way. if possible like the struct one or as was told by sir.
            printf("How many accounts to create(less than 10)");
            int x;
            cin >> x;
            for (int i = 1; i <= x; i++)
            {
                u[i].CreateAccount(i);
            }
            break;
        case 2:                    //take id from usr. authenticate. (id=object index. Other will have to make a new variable to keep track of object index)
            cout << "Enter id:\n"; //should I put this in a function?
            cin >> id;
            u[id].Authticate();
            u[id].Deposit(); //class is different from struct. //in stuct I needed to do u[]. Alsom functions can't be part of struct
            break;           //in class we can do that for functions as well as variable. If I call a class using object I don't need to do u[]. stuff for variables.
        case 3:
            cout << "Enter id:\n";
            cin >> id;
            u[id].Authticate();
            u[id].Withdraw();
            break;
        case 4:
            cout << "Enter id:\n";
            cin >> id;
            u[id].Authticate();
            u[id].CheckBalance();
            break;
        case 5:
            exit(0);
            break;

        default:
            cout << "Invalid Input";
            break;
        }
        cout << "\n\n";
    }

    return 0;
}

void user::CreateAccount(int n)
{
    cout << "Please Enter you first name:\n";
    cin >> name;
    int ok;
    cout << "Input 1 to deposit 1000 rupees:\n";
    cin >> ok;
    if (ok == 1)
    {
        id = n; //assining id autometically
        balance = 1000;
        cout << "Account created! Please remember your id!:\n";
        cout << "Your name, id and balance are: " << name << ", " << id << ", " << balance;
    }
    else
    {
        cout << "Cancelled\n";
    }

    transaction++;
}

void user::Deposit()
{

    int EnteredAmount = 0;

    cout << "Enter amount to deposit\n";
    cin >> EnteredAmount;
    balance += EnteredAmount;
    cout << "\nBalance is\n", balance;

    transaction++;
}

void user::Withdraw()
{
    int EnteredAmount = 0, CheckAmount = 0;
    cout << "Enter amount to Withdraw\n";
    cin >> EnteredAmount;
    CheckAmount = balance - EnteredAmount;
    if (CheckAmount > 500)
    {
        balance -= EnteredAmount;
        cout << "\nBalance is: \n"
             << balance;
    }
    else
    {
        cout << "Transaction failed as balace goes below minimum amount";
    }

    transaction++;
}

void user::CheckBalance()
{
    cout << "Account info:\nID: " << id << "\nName: " << name << "\nBalance: " << balance << "\nTotal transactions performed: " << transaction;
}

void user::Authticate()
{
    string EnteredName;
    if (id == NULL) //or     if (id != EnteredId) as its not null when I use pointer
    {
        cout << "id not found";
        return;
    }

    cout << "Enter name\n";
    cin >> EnteredName;
    string str = name;
    if (str.compare(EnteredName) != 0)
    {
        cout << "Entered name doesn't match";
        return;
    }
}