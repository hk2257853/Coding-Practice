#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char data;
    struct Node *next;
};

struct Node *Top1;
struct Node *Top2;

int isempty()
{
    if (Top1 == NULL)
    {
        return 1;
    }
    return 0;
}

int pop()
{
    if (isempty() != 1)
    {
        int x;
        x = Top1->data;
        struct Node *tmptr;
        tmptr = Top1;
        Top1 = Top1->next;
        free(tmptr);
        return x;
    }
    else
    {
        printf("Stack underflow");
        return 0;
    }
    return 0;
}

void push(char c)
{
    struct Node *NewNode = (struct Node *)malloc(sizeof(struct Node));
    NewNode->data = c;

    if (Top1 == NULL)
    {
        Top1 = NewNode;
        NewNode->next = NULL;
    }
    else
    {
        NewNode->next = Top1;
        Top1 = NewNode;
    }
}

void display()
{
    struct Node *tmptr;
    tmptr = Top1;
    printf("Data: ");
    while (tmptr != NULL)
    {
        printf("%c", tmptr->data);
        tmptr = tmptr->next;
    }
}

void reversestring()
{
    char str[30] = "hi";
    scanf("%s", &str);
    int x = strlen(str);
    int i = 0;
    while (i < x)
    {
        push(str[i]);
        i++;
    }
    display();
}

int main()
{
    printf("Enter a string: ");
    reversestring();
    return 0;
}
