#include <stdio.h>

int *TotalUsers;

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
    //personal note: If I used array to make this system it would have been a big issue
    //especially managing part.

    // for (int i = 0; i < 3; i++)
    // {
    //     if (u[i].id == NULL)
    //     {
    //         printf("true");
    //     }
    //     else
    //     {
    //         printf("false");
    //     }
    // since its a global variable the int numbers r null/0. But strings arn't null...
    // }
    system("cls");
    //dma part. Use malloc to get number of users... use free is user selects exit.

    int n, j = 1;
    while (j)
    {
        printf("BankMenu\n\n");
        printf("1 Create Account\n");
        printf("2 Deposit\n");
        printf("3 Withdraw\n");
        printf("4 Checkbalance\n");
        printf("5 Exit\n");
        printf("Enter from options:\n");

        scanf("%d", &n);

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
            free(TotalUsers);
            exit(0);
            break;

        default:
            printf("Invalid Input");
            break;
        }
        j++;
        printf("\n\n");
    }

    return 0;
}

void CreateAccount(int n)
{
    printf("Please Enter you first name:\n");
    scanf("%s", &u[n].name);
    int ok;
    printf("Input 1 to deposit 1000 rupees:\n");
    scanf("%d", &ok);
    if (ok == 1)
    {
        u[n].id = n; //assining id autometically
        u[n].balance = 1000;
        printf("Account created! Please remember your id!:\n");
        printf("Your name, id and balance are:\n%s\n%d\n%d", u[n].name, u[n].id, u[n].balance);
    }
    else
    {
        printf("Cancelled\n");
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

    printf("Enter amount to deposit\n");
    scanf("%d", &EnteredAmount);
    u[EnteredId].balance += EnteredAmount;
    printf("\nBalance is %d\n", u[EnteredId].balance);

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
    printf("Enter amount to Withdraw\n");
    scanf("%d", &EnteredAmount);
    CheckAmount = u[EnteredId].balance - EnteredAmount;
    if (CheckAmount > 500)
    {
        u[EnteredId].balance -= EnteredAmount;
        printf("\nBalance is %d\n", u[EnteredId].balance);
    }
    else
    {
        printf("Transaction failed as balace goes below minimum amount");
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

    printf("Account info:\nID: %d\nName: %s\nBalance: %d\nTotal transactions performed: %d", u[EnteredId].id, u[EnteredId].name, u[EnteredId].balance, u[EnteredId].transaction);
}

int Authticate()
{
    int EnteredId = 0, EnteredAmount = 0;
    char EnteredName[30];
    printf("Enter id\n");
    scanf("%d", &EnteredId);
    if (u[EnteredId].id == NULL) //or     if (u[EnteredId].id != EnteredId)
                                 //its not null when I use pointer
    {
        printf("id not found");
        return 0;
    }

    printf("Enter name\n");
    scanf("%s", &EnteredName);
    if (strcmp(u[EnteredId].name, EnteredName) != 0)
    {
        printf("Entered name doesn't match");
        return 0;
    }

    return EnteredId;
}