#include <stdio.h>
#include <stdlib.h>

FILE *fp;
char location[1000] = "/home/sslab15/Desktop/data.txt"; // 1st create the file

struct Node
{
    int rollno;
    char name[30];
    int marksub1, marksub2, marksub3;
    int total, avrg;
    struct Node *next;
};

struct Node *Start[10]; // should I dynamically allocate? or 10 will be enough
// how about creating a new start only when req?(ie, DMA)

void Display();
void createlist();
void prepend();
void append();
void fillist(int x);
void InsertAt();
void Insertbefore();
void InsertAfter();
void write(int x);
void deletebeg();
void deleteend();
void reverse();
void search();
void deleteAt();

// new functions
void maxmin();
void listid();
void swapadj();
void merge();
void split();
struct Node *inputdata(); // to reduce code size.
void SortLinkedList();

void SortLinkedList()
{
    struct Node *node = NULL, *temp = NULL;
    int tempvar; // temp variable to store node data
    int x = GetListid();
    node = Start[x];
    // temp = node;//temp node to hold node data and next link
    while (node != NULL)
    {
        temp = node;
        while (temp->next != NULL) // travel till the second last element
        {
            if (temp->rollno > temp->next->rollno) // compare the data of the nodes
            {
                tempvar = temp->rollno;
                temp->rollno = temp->next->rollno; // swap the data
                temp->next->rollno = tempvar;
            }
            temp = temp->next; // move to the next element
        }
        node = node->next; // move to the next node
    }
}

void split()
{
    int count = 0;
    int x = GetListid();

    // get size of list
    struct Node *ptr, *prev;
    ptr = Start[x];
    while (ptr != NULL)
    {
        ptr = ptr->next;
        count++;
    }

    // sort the list
    SortLinkedList();
    // split in half
    count = count / 2;
    ptr = Start[x];
    while (count != 0)
    {
        prev = ptr;
        ptr = ptr->next;
        count--;
    }
    prev->next = NULL;
    Start[x + 1] = ptr;
    printf("Id of the 2 lists: %d, %d\n", x, x + 1);
    // Display list
    Display();
    Display();
}

void merge()
{
    int x = GetListid(), y = GetListid();
    SortLinkedList();
    SortLinkedList();
    struct Node *ptr;
    ptr = Start[x];
    while (ptr->next != NULL) // ptr->next doesn't print last one. O I see. last one is pointing to null. so ptr becomes null!
    {
        ptr = ptr->next;
    }
    ptr->next = Start[y]; // just make last element of list 1 to point to 1st element of list 2
}

struct Node *inputdata(struct Node *NewNode)
{
    printf("Enter rollno:\n");
    scanf("%d", &NewNode->rollno);
    printf("Enter name:\n");
    scanf("%s", &NewNode->name);
    printf("Enter sub 1 marks:\n");
    scanf("%d", &NewNode->marksub1);
    printf("Enter sub 2 marks:\n");
    scanf("%d", &NewNode->marksub2);
    printf("Enter sub 3 marks:\n");
    scanf("%d", &NewNode->marksub3);

    NewNode->total = NewNode->marksub1 + NewNode->marksub2 + NewNode->marksub3;
    NewNode->avrg = NewNode->total / 3;

    return NewNode; // if I dont return will it get update as NewNode is local?
}

void swapadj() // not very clear need to understand this further.
{
    int x = GetListid();
    if (Start[x] == NULL || Start[x]->next == NULL)
        return;

    // Fix the head and its next explicitly to
    // avoid many if else in while loop
    struct Node *curr = Start[x]->next->next; // wow we can do this?
    struct Node *prev = Start[x];
    Start[x] = Start[x]->next;
    Start[x]->next = prev;

    // Fix remaining nodes
    while (curr != NULL && curr->next != NULL)
    {
        prev->next = curr->next;
        prev = curr;
        struct Node *next = curr->next->next;
        curr->next->next = curr;
        curr = next;
    }

    prev->next = curr;
}

int GetListid()
{
    int x;
    printf("Enter link id:\n");
    scanf("%d", &x);
    return x;
}

void maxmin()
{
    int max = 0, min = 0;
    struct Node *ptr, *minptr, *prevptr, *prevminptr = NULL;
    int x = GetListid();
    ptr = Start[x];
    int minpos = 1, count = 0;
    while (ptr != NULL)
    {
        if (ptr->avrg > max)
        {
            max = ptr->avrg;
        }
        ptr = ptr->next;
    }

    min = Start[x]->avrg;
    minptr = Start[x];
    ptr = Start[x]; // I need to bring back ptr to Start[x]!!
    while (ptr != NULL)
    {
        count++;
        if (min > ptr->avrg)
        {
            prevminptr = prevptr;
            minptr = ptr;
            min = ptr->avrg;
            minpos = count;
        }
        prevptr = ptr;
        ptr = ptr->next;
    }

    // making minptr node to point to last
    if (minpos != 1 && minpos != count) // if max elemnt is first or last the program stops so did this
    {
        prevminptr->next = minptr->next;
        prevptr->next = minptr;
        minptr->next = NULL;
    }
    else if (minpos == 1)
    {
        Start[x] = minptr->next;
        prevptr->next = minptr;
        minptr->next = NULL;
    }

    printf("Max: %d, Min:%d", max, min);
}

void search()
{
    int num, flag = 0;
    printf("Enter the number:\n");
    scanf("%d", &num);
    int count = 0;
    struct Node *ptr;
    int x = GetListid();
    ptr = Start[x];

    while (ptr != NULL) // ptr->next doesn't print last one. O I see. last one is pointing to null. so ptr becomes null!
    {
        count++;
        if (ptr->rollno == num)
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
{ // need to check if already empty.
    struct Node *ptr;
    int x = GetListid();
    ptr = Start[x];
    Start[x] = Start[x]->next;
    free(ptr);
}

void deleteAt()
{
    // check if its not 1st.
    int pos;
    printf("Enter the position\n");
    scanf("%d", &pos);
    struct Node *ptr, *nxt;
    int x = GetListid();
    ptr = Start[x];
    while (ptr != NULL && pos != 2) // fine tuned just for now...
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
    int x = GetListid();
    ptr = Start[x];
    while (ptr != NULL)
    {
        nxt = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = nxt;
    }

    Start[x] = prev;
}

void deleteend()
{ // need to check if already empty or 1st element...
    struct Node *ptr, *prev;
    int x = GetListid();
    ptr = Start[x];
    while (ptr->next != NULL)
    {
        prev = ptr;
        ptr = ptr->next;
    }
    free(ptr);
    prev->next = NULL;
}

void Display()
{
    int count = 0;
    struct Node *ptr;
    int x = GetListid();
    ptr = Start[x];
    printf("Student info:\n\n");
    while (ptr != NULL) // ptr->next doesn't print last one. O I see. last one is pointing to null. so ptr becomes null!
    {
        printf("\nRollno: %d\n", ptr->rollno);
        printf("Name: %s\n", ptr->name);
        printf("Sub 1 marks: %d\n", ptr->marksub1);
        printf("Sub 1 marks:%d\n", ptr->marksub2);
        printf("Sub 1 marks:%d\n", ptr->marksub3);
        printf("Total: %d\n", ptr->total);
        printf("Average: %d\n\n", ptr->avrg);
        // write(ptr->rollno);
        ptr = ptr->next;
        count++;
    }
    printf("\nTotal students: %d", count); // size of list
}

void createlist()
{
    int n;
    printf("Enter total elements:\n");
    scanf("%d", &n);
    static int x = 1; // still asking id again n again. just check once.
    printf("Assigned id to list: %d\n", x);
    for (int i = 0; i < n; i++)
    {
        fillist(x);
    }
    x++;
}

void prepend()
{
    struct Node *NewNode = (struct Node *)malloc(sizeof(struct Node));
    inputdata(NewNode); // if list is empty
    int x = GetListid();
    if (Start[x] == NULL)
    {
        Start[x] = NewNode;
        NewNode->next = NULL;
    }
    else
    {
        struct Node *temp = Start[x];
        Start[x] = NewNode;
        NewNode->next = temp;
    }
}

void append()
{
    int x = GetListid();
    // if Start[x]==null(ie list is empty just call prepend as 1st=last when only 1 element)
    if (Start[x] == NULL)
    {
        prepend();
    }
    else
    {
        struct Node *temp;
        struct Node *NewNode = (struct Node *)malloc(sizeof(struct Node));
        inputdata(NewNode);

        temp = Start[x];
        while (temp->next != NULL)
        {
            temp = temp->next; // transverse to last node
        }
        // make current last node to point to newnode. Don't delete temp. I need it for next time I call this func.
        temp->next = NewNode;
        temp = NewNode;
        NewNode->next = NULL;
    }
}

void fillist(int x) // this is just append function
{
    struct Node *NewNode = (struct Node *)malloc(sizeof(struct Node));

    // if Start[x]==null(ie list is empty just call prepend as 1st=last when only 1 element)
    if (Start[x] == NULL)
    {
        inputdata(NewNode);
        Start[x] = NewNode; // prepend part (when null)
        NewNode->next = NULL;
    }
    else
    {
        struct Node *temp;
        inputdata(NewNode);

        temp = Start[x];
        while (temp->next != NULL)
        {
            temp = temp->next; // transverse to last node
        }
        // make current last node to point to newnode. Don't delete temp. I need it for next time I call this func.
        temp->next = NewNode;
        temp = NewNode;
        NewNode->next = NULL;
    }
}

void InsertAt()
{
    // check for valid pos

    // if valid
    struct Node *temp;
    struct Node *NewNode = (struct Node *)malloc(sizeof(struct Node));
    inputdata(NewNode);
    int pos;
    printf("Enter position:\n");
    scanf("%d", &pos);
    int x = GetListid();
    temp = Start[x];

    pos--;
    while (pos > 1)
    {
        temp = temp->next; // transverse pos
        pos--;
    }
    NewNode->next = temp->next;
    temp->next = NewNode;
}

void Insertbefore()
{
    // check for valid pos

    // if valid
    struct Node *temp;
    struct Node *NewNode = (struct Node *)malloc(sizeof(struct Node));
    inputdata(NewNode);
    int pos;
    printf("Enter position:\n");
    scanf("%d", &pos);
    int x = GetListid();
    temp = Start[x];

    while (pos - 1 > 2)
    {
        temp = temp->next; // transverse
        pos--;
    }
    NewNode->next = temp->next;
    temp->next = NewNode;
}

void InsertAfter()
{
    // check for valid pos

    // if valid
    struct Node *temp;
    struct Node *NewNode = (struct Node *)malloc(sizeof(struct Node));
    inputdata(NewNode);
    int pos;
    printf("Enter position:\n");
    scanf("%d", &pos);
    int x = GetListid();
    temp = Start[x];

    while (pos > 1)
    {
        temp = temp->next; // transverse
        pos--;
    }
    NewNode->next = temp->next;
    temp->next = NewNode;
}

void write(int x)
{
    // open the file. If doesn't exist it will create one.
    fp = fopen(location, "a"); // r for read mode. w for write mode. a to append, else it gets overwritten.

    // writing in file
    fprintf(fp, "%d ", x);

    // closes the file
    fclose(fp);
}

int main()
{
    int n, j = 1; // I can use j to give id to linkedlist.

    while (j)
    {
        printf("Menu\n\n"); // Menu
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
        printf("14 min max\n");
        printf("15 swap\n");
        printf("16 merge\n");
        printf("17 split\n");
        printf("18 exit\n");

        printf("Enter from options:\n");

        scanf("%d", &n); // What user want?

        switch (n)
        {
        case 1:
            createlist(); // use j for list id
            break;
        case 2:
            Display();
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
            deleteAt();
            break;
        case 14:
            maxmin();
            break;

        case 15:
            swapadj();
            break;

        case 16:
            merge();
            break;
        case 17:
            split();
            break;
        case 18:
            exit(0);
            break;
        case 19:
            SortLinkedList();
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

// side note: there's still some confusion with node->next and node.
// Also when and when not to dynamically allocate
