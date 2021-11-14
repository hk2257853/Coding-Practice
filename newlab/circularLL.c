#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *start = NULL;

void createnode();
void createlist();
void displaylist();
void add_beg();
void add_end();
void add_after();
void add_before();
void deletenode();

int main()
{
    while (1)
    {
        int n;
        printf("1 Create linked list\n");
        printf("2 Display linked list\n");
        printf("3 Add at beginning\n");
        printf("4 Add at end\n");
        printf("5 Add after\n");
        printf("6 Add before\n");
        printf("7 delete\n");
        printf("Enter from options\n");

        scanf("%d", &n);

        switch (n)
        {
        case 1:
            createlist();
            break;
        case 2:
            displaylist();
            break;
        case 3:
            add_beg();
            break;
        case 4:
            add_end();
            break;
        case 5:
            add_after();
            break;
        case 6:
            add_before();
            break;
        case 7:
            deletenode();
            break;
        }

        printf("\n\n");
    }
}

void createlist()
{
    int n;
    printf("Enter Total elements: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        add_end();
    }
}