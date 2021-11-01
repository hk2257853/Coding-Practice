#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char data;
    struct Node *next;
};

struct Node *Top1;

void push(char c);
void pop();
void display();
int isempty();
char top();
void input();

void input()
{
    printf("Enter string: ");
    char str[100];
    scanf("%s", &str);
    int flag = 1;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == '{' || str[i] == '(' || str[i] == '[')
        {
            push(str[i]);
        }
        else if (str[i] == '}' || str[i] == ')' || str[i] == ']')
        {
            if (str[i] == '}' && top() == '{' || str[i] == ')' && top() == '(' || str[i] == ']' && top() == '[')
            {
                pop();
            }
            else
            {
                flag = 0;
                break;
            }
        }
    }

    if (Top1 != NULL)
    {
        flag = 0;
    }

    if (flag == 1)
    {
        printf("Balanced");
    }
    else
    {
        printf("Unbalanced");
    }
}

char top()
{
    return Top1->data;
}

void display()
{
    struct Node *tmptr;
    tmptr = Top1;
    printf("Data: ");
    while (tmptr != NULL)
    {
        printf("%d ", tmptr->data);
        tmptr = tmptr->next;
    }
}

int isempty()
{
    if (Top1 == NULL)
    {
        return 1;
    }
    return 0;
}

void pop()
{
    if (isempty() != 1)
    {
        int x;
        x = Top1->data;
        struct Node *tmptr;
        tmptr = Top1;
        Top1 = Top1->next;
        free(tmptr);
    }
    else
    {
        printf("Stack underflow");
    }
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

int main()
{
    while (1)
    {
        input();
        Top1 = NULL; // otherwise: If I get unbalanced some elements will remain
        printf("\n\n");
    }

    return 0;
}
