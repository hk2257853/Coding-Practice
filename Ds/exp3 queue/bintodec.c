#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct Node
{
    char data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void insert(char);
char delete ();

void binaryToDec()
{
    char str[100];
    printf("Enter binary number\n");
    scanf("%s", &str);
    int length = strlen(str);
    for (int i = 0; i < length; i++)
    {
        insert(str[i]);
    }

    length--;
    int sum = 0;
    while (front != NULL)
    {
        int num = (int)delete () - 48;
        sum = sum + (num * pow(2, length));
        length--;
    }
    printf("Decimal: %d\n", sum);
}

char delete ()
{
    char top = front->data;
    struct Node *temp;
    temp = front;
    front = front->next;
    free(temp);

    return top;
}

void insert(char s)
{

    struct Node *NewNode = (struct Node *)malloc(sizeof(struct Node));
    NewNode->next = NULL;
    NewNode->data = s;
    if (rear == NULL)
    {
        rear = NewNode;
        front = NewNode;
    }
    else
    {
        rear->next = NewNode;
        rear = NewNode;
    }
}

int main()
{
    binaryToDec();
}
