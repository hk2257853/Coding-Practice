#include <stdio.h>
#include <stdlib.h>

FILE *fp;
char location[1000] = "/home/sslab15/Desktop/data.txt";

//currently will work for 1 linked list only
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
void deletebeg();
void deleteend();
void reverse();
void search();
void deleteat();

void search()
{
    int num, flag = 0;
    printf("Enter the number:\n");
    scanf("%d", &num);
    int count = 0;
    struct Node *ptr;
    ptr = Start;

    while (ptr != NULL) //ptr->next doesn't print last one. O I see. last one is pointing to null. so ptr becomes null!
    {
        count++;
        if (ptr->data == num)
        {
            flag = 1;
            printf("Element %d is at %d", num, count);
            break;
        }
        ptr = ptr->next;
    }
    if (flag == 0)
        printf("Element not found");
}
void deletebeg()
{ //need to check if already empty.
    struct Node *ptr;
    ptr = Start;
    Start = Start->next;
    free(ptr);
}

void deleteat()
{
    //check if its not 1st.
    int pos;
    printf("Enter the position\n");
    scanf("%d", &pos);
    struct Node *ptr, *nxt;
    ptr = Start;
    while (ptr != NULL && pos != 2) //fine tuned just for now...
    {
        ptr = ptr->next;
        pos--;
    }
    nxt = ptr->next;
    ptr->next = nxt->next;
    free(nxt);
}

void reverse()
{
    struct Node *ptr, *prev, *nxt;
    prev = NULL;
    ptr = Start;
    while (ptr != NULL)
    {
        nxt = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = nxt;
    }

    Start = prev;
}

void deleteend()
{ //need to check if already empty or 1st element...
    struct Node *ptr, *prev;
    ptr = Start;
    while (ptr->next != NULL)
    {
        prev = ptr;
        ptr = ptr->next;
    }
    free(ptr);
    prev->next = NULL;
}

void linkedListTraversal()
{
    int count = 0;
    struct Node *ptr;
    ptr = Start;
    printf("The elements are:\n");
    while (ptr != NULL) //ptr->next doesn't print last one. O I see. last one is pointing to null. so ptr becomes null!
    {
        printf("%d ", ptr->data);
        //write(ptr->data);
        ptr = ptr->next;
        count++;
    }
    printf("\nThe size of list is:%d", count); //size of list
}

void createlist()
{
    int n;
    printf("Enter total elements:\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        append();
    }
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
        struct Node *temp = Start;
        Start = NewNode;
        NewNode->next = temp;
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
        printf("4 Search for an element\n");
        printf("5 Add at begining\n");
        printf("6 Add at end\n");
        printf("7 Add after position\n");
        printf("8 Add before position\n");
        printf("9 Add at position\n");
        printf("10 Delete 1st element\n");
        printf("11 Delete last element\n");
        printf("12 Reverse\n");
        printf("13 Delete at position\n");
        printf("14 Exit\n");
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
            search();
            break;
        case 5:
            prepend();
            break;
        case 6:
            append();
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
            deletebeg();
            break;
        case 11:
            deleteend();
            break;
        case 12:
            reverse();
            break;
        case 13:
            deleteat();
            break;
        case 14:
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

//Remaining: make more than 1 linked list(for that I will use struct array) and take input from user.
