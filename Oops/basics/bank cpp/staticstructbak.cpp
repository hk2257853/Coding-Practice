#include <iostream>
using namespace std;

struct user
{
    int id, balance, transaction;
    char name[30];
} u[3];

void Deposit();
void Withdraw();
void CheckBalance();
int Authticate();
void CreateAccount(int n);

int main()
{
    int n, j = 1;
    while (j)
    {
        cout << "BankMenu\n\n";
        cout << "1 Create Account\n";
        cout << "2 Deposit\n";
        cout << "3 Withdraw\n";
        cout << "4 Checkbalance\n";
        cout << "5 Exit\n";
        cout << "Enter from options:\n";

        cin >> n;

        switch (n)
        {
        case 1:
            CreateAccount(j);
            break;
        case 2:
            Deposit();
            break;
        case 3:
            Withdraw();
            break;
        case 4:
            CheckBalance();
            break;
        case 5:
            exit(0);
            break;

        default:
            cout << "Invalid Input";
            break;
        }
        j++;
        cout << "\n\n";
    }

    return 0;
}

void CreateAccount(int n)
{
    cout << "Please Enter you first name:\n";
    cin >> u[n].name;
    int ok;
    cout << "Input 1 to deposit 1000 rupees:\n";
    cin >> ok;
    if (ok == 1)
    {
        u[n].id = n; //assining id autometically
        u[n].balance = 1000;
        cout << "Account created! Please remember your id!:\n";
        cout << "Your name, id and balance are: " << u[n].name << ", " << u[n].id << ", " << u[n].balance;
    }
    else
    {
        cout << "Cancelled\n";
    }

    u[n].transaction++;
}

void Deposit()
{
    int EnteredId = Authticate();
    if (EnteredId == 0)
    {
        return;
    }

    int EnteredAmount = 0;

    cout << "Enter amount to deposit\n";
    cin >> EnteredAmount;
    u[EnteredId].balance += EnteredAmount;
    cout << "\nBalance is\n", u[EnteredId].balance;

    u[EnteredId].transaction++;
}

void Withdraw()
{

    int EnteredId = Authticate();
    if (EnteredId == 0)
    {
        return;
    }

    int EnteredAmount = 0, CheckAmount = 0;
    cout << "Enter amount to Withdraw\n";
    cin >> EnteredAmount;
    CheckAmount = u[EnteredId].balance - EnteredAmount;
    if (CheckAmount > 500)
    {
        u[EnteredId].balance -= EnteredAmount;
        cout << "\nBalance is: \n"
             << u[EnteredId].balance;
    }
    else
    {
        cout << "Transaction failed as balace goes below minimum amount";
    }

    u[EnteredId].transaction++;
}

void CheckBalance()
{
    int EnteredId = Authticate();
    if (EnteredId == 0)
    {
        return;
    }

    cout << "Account info:\nID: " << u[EnteredId].id << "\nName: " << u[EnteredId].name << "\nBalance: " << u[EnteredId].balance << "\nTotal transactions performed: " << u[EnteredId].transaction;
}

int Authticate()
{
    int EnteredId = 0, EnteredAmount = 0;
    char EnteredName[30];
    cout << "Enter id\n";
    cin >> EnteredId;
    if (u[EnteredId].id == NULL) //or     if (u[EnteredId].id != EnteredId)
                                 //its not null when I use pointer
    {
        cout << "id not found";
        return 0;
    }

    cout << "Enter name\n";
    cin >> EnteredName;
    string str = u[EnteredId].name;
    if (str.compare(EnteredName) != 0)
    {
        cout << "Entered name doesn't match";
        return 0;
    }

    return EnteredId;
}