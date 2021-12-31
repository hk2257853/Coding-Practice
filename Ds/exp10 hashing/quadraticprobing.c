#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 11

enum status // Otherwise can't insert 0
{
    EMPTY,
    OCCUPIED
};

struct table1
{
    int key;
};

struct Record
{
    struct table1 info;
    enum status statusinfo; // It takes in EMPTY as the default value so no issue.
};                          // In cpp I could have used a constructor...

struct Record h[TABLE_SIZE];

void insert()
{
    int key, index, i, flag = 0, hkey;
    printf("\nenter a value to insert into hash table\n");
    scanf("%d", &key);
    hkey = key % TABLE_SIZE;
    struct table;
    for (i = 0; i < TABLE_SIZE; i++)
    {
        index = (hkey + i * i) % TABLE_SIZE;

        if (h[index].statusinfo == EMPTY)
        {
            h[index].info.key = key;
            h[index].statusinfo = OCCUPIED;
            break;
        }
    }

    if (i == TABLE_SIZE)

        printf("\nelement cannot be inserted\n");
}

void search()
{ // What if I make exactly like delete funtion?
    int key, index, hkey, flag = 0;
    printf("\nenter search element\n");
    scanf("%d", &key);
    hkey = key % TABLE_SIZE;
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        index = (hkey + i * i) % TABLE_SIZE;
        if (h[index].info.key == key)
        {
            flag = 1;
            printf("value is found at index %d", index);
            break;
        }
    }
    if (flag == 0)
        printf("\n value is not found\n");
}

void display()
{

    int i;

    printf("\nelements in the hash table are \n");

    for (i = 0; i < TABLE_SIZE; i++)

        printf("\nat index %d \t value =  %d", i, h[i].info.key);
}

void delete ()
{
    int key, flag = 0;
    printf("\nenter a value to delete\n");
    scanf("%d", &key);
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (h[i].info.key == key)
        {
            h[i].info.key = 0;
            h[i].statusinfo = EMPTY;
            flag = 1;
        }
    }

    if (flag)
        printf("Element not found");
}

int main()
{
    int opt, i;
    while (1)
    {
        printf("\nPress 1. Insert\t 2. Display \t3. Search \t4.Delete \n");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            insert();
            break;
        case 2:
            display();
            break;
        case 3:
            search();
            break;
        case 4:
            delete ();
            break;
        }
    }
}
