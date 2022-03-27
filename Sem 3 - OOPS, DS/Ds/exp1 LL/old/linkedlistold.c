#include <stdio.h>
#include <stdlib.h>

FILE *fp;
char location[1000] = "/home/sslab15/Desktop/data.txt";

//currently will work for 1 linked list only. ExB for multiple linked list
struct Node
{
    int data;
    struct Node *next;
};

struct Node *Start = NULL; //should I dynamically allocate?

void linkedListTraversal();
void createlist();
void prepend();
void append();
void InsertAt();
void Insertbefore();
void InsertAfter();
void write(int x);

void linkedListTraversal()
{
    struct Node *ptr;
    ptr = Start;
    printf("The elements are:\n");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        //write(ptr->data);
        ptr = ptr->next;
    }
}

void createlist()
{
}

void prepend()
{
    struct Node *NewNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data:\n");
    scanf("%d", &NewNode->data);

    //if list is empty
    if (Start == NULL)
    {
        Start = NewNode;
        NewNode->next = NULL;
    }
    else
    {
        NewNode->next = Start->next; //newnode points to whatever start is pointing to.
        Start->next = NewNode;       //making start to point to newnode
    }
}

void append()
{

    //if start==null(ie list is empty just call prepend as 1st=last when only 1 element)
    if (Start == NULL)
    {
        prepend();
    }
    else
    {
        struct Node *temp;
        struct Node *NewNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter data:\n");
        scanf("%d", &NewNode->data);

        temp = Start;
        while (temp->next != NULL)
        {
            temp = temp->next; //transverse to last node
        }
        //make current last node to point to newnode. Don't delete temp. I need it for next time I call this func.
        temp->next = NewNode;
        temp = NewNode;
        NewNode->next = NULL;
    }
}

void InsertAt()
{
    //check for valid pos

    //if valid
    struct Node *temp;
    struct Node *NewNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data:\n");
    scanf("%d", &NewNode->data);
    int pos;
    printf("Enter position:\n");
    scanf("%d", &pos);

    temp = Start;

    pos--;
    while (pos > 1)
    {
        temp = temp->next; //transverse pos
        pos--;
    }
    NewNode->next = temp->next;
    temp->next = NewNode;
}

void Insertbefore()
{
    //check for valid pos

    //if valid
    struct Node *temp;
    struct Node *NewNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data:\n");
    scanf("%d", &NewNode->data);
    int pos;
    printf("Enter position:\n");
    scanf("%d", &pos);

    temp = Start;

    while (pos - 1 > 2)
    {
        temp = temp->next; //transverse
        pos--;
    }
    NewNode->next = temp->next;
    temp->next = NewNode;
}

void InsertAfter()
{
    //check for valid pos

    //if valid
    struct Node *temp;
    struct Node *NewNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data:\n");
    scanf("%d", &NewNode->data);
    int pos;
    printf("Enter position:\n");
    scanf("%d", &pos);

    temp = Start;

    while (pos > 1)
    {
        temp = temp->next; //transverse
        pos--;
    }
    NewNode->next = temp->next;
    temp->next = NewNode;
}

void write(int x)
{
    //open the file. If doesn't exist it will create one.
    fp = fopen(location, "a"); //r for read mode. w for write mode. a to append, else it gets overwritten.

    //writing in file
    fprintf(fp, "%d ", x);

    //closes the file
    fclose(fp);
}

int main()
{
    int n, j = 1; //I can use j to give id to linkedlist.

    while (j)
    {
        printf("Menu\n\n"); //Menu
        printf("1 Create new linkedlist\n");
        printf("2 Display linkedlist\n");
        printf("3 Size of linkedlist\n");
        printf("4 Search for an element\n");
        printf("5 Add at begining\n");
        printf("6 Add at end\n");
        printf("7 Add after position\n");
        printf("8 Add before position\n");
        printf("9 Add at position\n");
        printf("10 Exit\n");
        printf("Enter from options:\n");

        scanf("%d", &n); //What user want?

        switch (n)
        {
        case 1:
            createlist(); //use j for list id
            break;
        case 2:
            linkedListTraversal();
            break;
        case 3:

            break;
        case 4:

            break;
        case 5:
            append();
            break;
        case 6:
            prepend();
            break;
        case 7:
            InsertAfter();
            break;
        case 8:
            Insertbefore();
            break;
        case 9:
            InsertAt();
            break;
        case 10:
            //free(user); //1st do static
            exit(0);
            break;

        default:
            printf("Invalid Input");
            break;
        }
        j++;
        printf("\n\n");
    }

    return 0;
}

//side note: there's still some confusion with node->next and node.
//Also when and when not to dynamically allocate

//Remaining: delete, reverse, make more than 1 linked list(for that I will use struct) and take input from user.
