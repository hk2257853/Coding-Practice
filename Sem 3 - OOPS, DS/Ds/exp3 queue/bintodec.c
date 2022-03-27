#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct Node
{
    int data;
    struct Node *next;
};

// Question: what methods can be used:
// reverse queue
// or just put in a new char array n print

struct Node *front = NULL;
struct Node *rear = NULL;

void insert(int);
int delete ();

void DecToBin()
{
    int inputnum, size = 0;
    printf("Enter number\n");
    scanf("%d", &inputnum);
    while (inputnum != 0) // till quotient isn't 0
    {
        insert(inputnum % 2);
        inputnum = inputnum / 2;
        size++;
    }

    char bino[100];
    struct Node *temp;
    temp = front;
    int i = 0;
    while (temp != NULL)
    {
        bino[i] = temp->data;
        temp = temp->next;
        i++;
    }

    i = size - 1;
    while (i >= 0)
    {
        printf("%d", bino[i]);
        i--;
    }

    // display();
}

int delete ()
{
    int top = front->data;
    struct Node *temp;
    temp = front;
    front = front->next;
    free(temp);

    return top;
}

void insert(int s)
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
    DecToBin();
}
