#include <stdio.h>
#include <stdlib.h>

struct vertex
{
    int data;
    struct vertex *nextvertex;
    struct edge *nextedge;
};

struct edge
{
    struct vertex *vertexptr;
    struct edge *nextedge;
};

struct vertex *start = NULL;
int graphtype;

// this is for learning purpose so not checking for invalid inputs...
void insertvertex(int num) // its almost like a doubly LL
{
    struct vertex *newvertex = (struct vertex *)malloc(sizeof(struct vertex));
    newvertex->data = num;
    newvertex->nextedge = NULL;
    newvertex->nextvertex = NULL;

    if (start == NULL)
    {
        start = newvertex;
        return;
    }

    struct vertex *temp = start;
    while (temp->nextvertex != NULL)
    {
        temp = temp->nextvertex;
    }

    temp->nextvertex = newvertex;
}

struct vertex *findvertex(int num)
{
    struct vertex *temp = start;
    while (temp->data != num)
    {
        temp = temp->nextvertex;
    }

    return temp;
}

void insertedge(int origin, int end)
{
    struct vertex *originvertex = findvertex(origin);
    struct vertex *endvertex = findvertex(end);

    struct edge *newedge = (struct edge *)malloc(sizeof(struct edge));
    newedge->nextedge = NULL;

    struct edge *temp = originvertex->nextedge;
    newedge->vertexptr = endvertex;

    if (temp == NULL)
    {
        originvertex->nextedge = newedge;
        return;
    }

    while (temp->nextedge != NULL)
    {
        temp = temp->nextedge;
    }

    temp->nextedge = newedge;
}

void deletedge(int origin, int end)
{
    struct vertex *tempver = findvertex(origin);
    struct edge *tempedge = tempver->nextedge;
    struct edge *prevedge;

    while (tempedge->vertexptr->data != end)
    {
        prevedge = tempedge;
        tempedge = tempedge->nextedge;
    }

    if (tempver->nextedge == tempedge) // 1st edge is to be deleted
    {
        tempver->nextedge = tempedge->nextedge;
        free(tempedge);
        return;
    }

    prevedge->nextedge = tempedge->nextedge;
    free(tempedge);
}

void deletevertex_undigraph(int ver) // need to test after making menu
{
    struct vertex *tempver = findvertex(ver);
    struct edge *tempedge = tempver->nextedge;

    while (tempedge)
    {
        deletedge(tempedge->vertexptr->data, ver); // In list origin will be vertex n des will be edge...
        tempedge->nextedge;                        // here edge's vertex pointer is orgin n vertex to be deleted the des
    }
    free(tempver);
}

void deletevertex_digraph(int ver)
{ // TODO: if its 1st or last vertex
    struct edge *tempedge;
    struct vertex *tempver = start;

    // deleting edges pointing to vertodel
    while (tempver)
    {
        tempedge = tempver->nextedge;
        while (tempedge)
        {
            if (tempedge->vertexptr->data == ver)
            {
                tempedge = tempedge->nextedge; // this line wan't there so went under continuous loop...
                deletedge(tempver->data, ver); // I won't have debugger in exam...need to work on this!
            }                                  // In list origin will be vertex n des will be edge...
            else
                tempedge = tempedge->nextedge;
        }
        tempver = tempver->nextvertex;
    }

    tempver = start;
    struct vertex *prever;
    while (tempver->data != ver)
    {
        prever = tempver;
        tempver = tempver->nextvertex;
    }
    if (tempver == start)
        start = start->nextvertex;
    else
        prever->nextvertex = tempver->nextvertex;

    free(tempver);
}

void display()
{
    struct vertex *tempver = start;
    struct edge *tempedge;

    while (tempver != NULL)
    {
        printf("%d: ", tempver->data);
        tempedge = tempver->nextedge;
        while (tempedge != NULL)
        {
            printf("%d ", tempedge->vertexptr->data);
            tempedge = tempedge->nextedge;
        }

        tempver = tempver->nextvertex;
        printf("\n");
    }
}

int main()
{
    // Does edge/vertex insertion order matter?
    // Do I need to check for invalid inputs?

    // if its un directed, call insertedge/deletedge 2 times with values swapped
    //     if (graphtype == 0)
    // {
    //     checked = 1;
    //     insertedge(end, origin);
    // }

    insertvertex(1);
    insertvertex(2);
    insertvertex(3);
    insertvertex(4);

    insertedge(1, 2);
    insertedge(3, 2);
    insertedge(1, 3);

    display();

    deletevertex_digraph(3);

    // deletedge(1, 2);
    // deletedge(3, 2);
    // deletedge(1, 3);
    printf("\n");
    display();
}