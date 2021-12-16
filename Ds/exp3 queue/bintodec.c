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

void display() // front to rear
{
    printf("Binary number: ");
    struct Node *temp;
    temp = front;
    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
}

void DecToBin()
{
    int inputnum;
    printf("Enter number\n");
    scanf("%d", &inputnum);
    while (inputnum != 0) // till quotient isn't 0
    {
        insert(inputnum % 2);
        inputnum = inputnum / 2;
    }
    display();
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
