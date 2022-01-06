// This one was done on my own using the simple explainations
// It's better if I use the textbook one for exam

#include <stdio.h>
#define Size 10

int hashtable[Size];

void insert()
{
    // we use one of the data as key (will make more sense for a struct)
    // to get the hash value
    int key;
    scanf("%d", &key);
    int index = key % Size;

    if (index == 0)
    {
        hashtable[index] = key;
    }
    else
    {
        while (hashtable[index] != 0)
        {
            index++;
            if (index == Size)
            {
                printf("Can't insert");
                return;
            }
        }
        hashtable[index] = key;
    }
}

void search()
{
    int key;
    scanf("%d", &key);
    int index = key % Size; // using key to get the index in table
    printf("%d", hashtable[index]);
}

int main()
{
    insert();
    insert();
    search();
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", hashtable[i]);
    }
}