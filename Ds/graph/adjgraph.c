#include <stdio.h>
#define MAX 100

// graph related data
int adj[MAX][MAX];
int origin, destin;
int graph_type, maxedges, Tvertices;

int isinputvalid()
{
    if (origin < 0 || destin < 0 || origin > Tvertices || destin > Tvertices)
        return 0;

    return 1;
}

void create_graph()
{ // Note: If I want to recreate a new graph, restart the program. Otherwise will have to initialise all values to 0 n then start...
    printf("Enter 1 for undirected graph or 2 for directed graph: ");
    scanf("%d", &graph_type);
    printf("Enter total vertices: ");
    scanf("%d", &Tvertices);

    if (graph_type == 1)
        maxedges = Tvertices * (Tvertices - 1) / 2;
    else
        maxedges = Tvertices * (Tvertices - 1);

    printf("-1 -1 to quit\n");
    for (int i = 0; i < maxedges; i++)
    {
        printf("Enter edge: ");
        scanf("%d%d", &origin, &destin);

        if (origin == -1 && destin == -1)
            break;

        // Check if its a valid input
        if (isinputvalid())
        {
            adj[origin][destin] = 1;
            if (graph_type == 1)
                adj[destin][origin] = 1;
        }
        else
        {
            printf("Invalid input");
            i--; // so that user can re enter for this one...
        }
    }
}

void addedge()
{
    printf("Enter edge: ");
    scanf("%d%d", &origin, &destin);

    if (isinputvalid())
    {
        adj[origin][destin] = 1;
        if (graph_type == 1)
            adj[destin][origin] = 1;
    }
    else
        printf("Invalid input");
}

void deletedge()
{
    printf("Enter edge: ");
    scanf("%d%d", &origin, &destin);

    if (isinputvalid())
    {
        adj[origin][destin] = 0;
        if (graph_type == 1)
            adj[destin][origin] = 0;
    }
    else
        printf("Invalid input");
}

void addvertex()
{
    Tvertices++;
}

void deletevertex(int ver)
{
    while (ver < Tvertices)
    {
        // shift row upward
        for (int i = 0; i < Tvertices; i++)
        {
            adj[ver][i] = adj[ver + 1][i];
        }

        // shift colum to left
        for (int i = 0; i < Tvertices; i++)
        {
            adj[i][ver] = adj[i][ver + 1];
        }
        // During last iteration last row and column becomes zero.
        ver++;
    }
    Tvertices--;
}

void displaygraph()
{
    printf("The adjacency matrix is : \n");
    for (int i = 0; i < Tvertices; i++)
    {
        for (int j = 0; j < Tvertices; j++)
        {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    // vertex start from 0 till Tvertices-1
    int input, ver;
    while (1)
    {
        printf("1 create graph\n"); // if total user/vertices can change, I'll have to use DMA
        printf("2 add edge\n");
        printf("3 delete edge\n");
        printf("4 display graph\n");
        printf("5 add vertex\n");
        printf("6 delete vertex\n");

        scanf("%d", &input);
        switch (input)
        {
        case 1:
            create_graph();
            break;
        case 2:
            addedge();
            break;
        case 3:
            deletedge();
            break;
        case 4:
            displaygraph();
            break;
        case 5:
            addvertex();
            break;
        case 6:
            scanf("%d", &ver);
            deletevertex(ver);
            break;
        }
    }
}