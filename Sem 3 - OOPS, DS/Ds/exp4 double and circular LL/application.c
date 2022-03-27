#include <stdio.h>
#include <stdlib.h>

struct Circular_Node
{
    int circular_data;
    struct Circular_Node *circular_next;
};

struct Doubly_Node
{
    int data;
    struct Doubly_Node *Doubly_next, *Doubly_prev;
};

struct Doubly_Node *start = NULL;
struct Circular_Node *last = NULL;

void add_end(int num);
void displaylist();
void circular_add_end(int num);
void circular_displaylist();

int main()
{
    printf("Enter Value: ");
    int input;
    scanf("%d", &input);
    while (input > 0)
    {
        circular_add_end(input % 10);
        input = input / 10;
    }
    circular_displaylist();

    struct Circular_Node *ptr = last->circular_next, *prevptr;
    while (ptr != last)
    {
        prevptr = ptr;
        ptr = ptr->circular_next;
        add_end(ptr->circular_data + prevptr->circular_data);
    }
    displaylist();
    return 0;
}

void circular_add_end(int num)
{
    struct Circular_Node *newnode = (struct Circular_Node *)malloc(sizeof(struct Circular_Node));
    newnode->circular_data = num;

    if (last == NULL)
    {
        last = newnode;
        newnode->circular_next = newnode;
    }
    else
    {
        newnode->circular_next = last->circular_next;
        last->circular_next = newnode;
        last = newnode;
    }
}

void circular_displaylist()
{
    printf("CircularLL elements are: ");
    struct Circular_Node *temp = last;
    while (temp->circular_next != last)
    {
        temp = temp->circular_next;
        printf("%d ", temp->circular_data);
    }

    printf("%d", last->circular_data);
}

void add_end(int num)
{
    struct Doubly_Node *NewNode = (struct Doubly_Node *)malloc(sizeof(struct Doubly_Node));
    NewNode->data = num;

    if (start == NULL)
    {
        start = NewNode;
        NewNode->Doubly_prev = NULL;
        NewNode->Doubly_next = NULL;
    }
    else
    {

        struct Doubly_Node *temp = start;
        while (temp->Doubly_next != NULL)
        {
            temp = temp->Doubly_next;
        }

        temp->Doubly_next = NewNode;
        NewNode->Doubly_prev = temp;
        NewNode->Doubly_next = NULL;
    }
}

void displaylist()
{
    printf("\nDoublyLL elements are: ");
    struct Doubly_Node *temp = start;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->Doubly_next;
    }
}
