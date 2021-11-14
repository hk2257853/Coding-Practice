#include <stdio.h>
#include <stdlib.h>
//search advantages/usesof circularLL
struct Node
{
    int data;
    struct Node *next;
};

struct Node *last = NULL;

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

void add_end()
{
    struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);

if(last==NULL)
{
    last=newnode;
    newnode->next=newnode;
}
else{
newnode->next=last->next;
last->next=newnode;
last=newnode;

}
}

void displaylist()
{
struct Node *temp=last;
while(temp->next!=last)
{
temp=temp->next;
printf("%d ", temp->data);
}

printf("%d", last->data);
}

void add_beg()
{
    if(last==NULL)
    {
    add_end();
    }
    else
    {
    struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);

	newnode->next=last->next;
	last->next=newnode;
    }

}

void add_after()
{
struct Node *temp;
    struct Node *NewNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data:\n");
    scanf("%d", &NewNode->data);
    int pos;
    printf("Enter position:\n");
    scanf("%d", &pos);

    temp = last;

    while (pos != 0)
    {
        temp = temp->next; // transverse
        pos--;
    }
    NewNode->next = temp->next; //ques: insert after last means have isert to 1st?
    temp->next = NewNode;
}

void add_before()
{
    struct Node *temp;
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data:\n");
    scanf("%d", &newnode->data);
    int pos;
    printf("Enter position:\n");
    scanf("%d", &pos);

    temp = last;

    while (pos > 1)
    {
        temp = temp->next; // transverse
        pos--;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void deletenode()
{
    struct Node *temp=last->next;
    last=temp->next;
    free(temp);

}
