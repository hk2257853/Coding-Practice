#include <stdio.h>
#define MAX 100
#define initial 0
#define waiting 1
#define visited 2

// graph related data
int adj[MAX][MAX];
int origin, destin;
int graph_type, maxedges, Tvertices;

// queue
int queue[MAX];
int front = -1, rear = -1;

// dfs
int isvisited[MAX];

void insert_queue(int x);
int delete_queue();
int isempty_queue();

int state[MAX];

void dfs(int v)
{
    isvisited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < Tvertices; i++)
    {
        if (adj[v][i] && !isvisited[i])
            dfs(i);
    }
}

int isempty_queue()
{
    if (front > rear || front == -1)
        return 1;

    return 0;
}

int delete_queue()
{
    if (isempty_queue())
        printf("Queue is empty");
    else
    {
        int temp = queue[front];
        front++;
        return temp;
    }
}

void insert_queue(int x)
{

    if (rear == -1 && front == -1)
    {
        rear = 0, front = 0;
        queue[rear] = x;
    }
    else if (rear < MAX - 1)
    {
        rear++;
        queue[rear] = x;
    }
    else
        printf("Queue is full");
}

int isinputvalid()
{
    if (origin < 0 || destin < 0 || origin > Tvertices || destin > Tvertices)
        return 0;

    return 1;
}

void create_graph()
{ // Note: If I want to recreate a new graph, restart the program. Otherwise will have to initialise all values to 0 n then start...
    printf("Enter 1 for undirected graph or 0 for directed graph: ");
    scanf("%d", &graph_type);
    printf("Enter total vertices: ");
    scanf("%d", &Tvertices);

    if (graph_type == 1)
        maxedges = Tvertices * (Tvertices - 1) / 2;
    else
        maxedges = Tvertices * (Tvertices - 1);

    printf("-1 -1 to quit\n");
    for (int i = 0; i < maxedges; i++)  // in exam just use a while(1) n -1 -1 be the condition to exit
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

void BFS(int v)
{
    for (int i = 0; i < Tvertices; i++)
    {
        state[i] = initial;
    }

    insert_queue(v);
    // change state
    state[v] = waiting;
    while (!isempty_queue())
    {
        v = delete_queue();
        // change state
        state[v] = visited;
        printf("%d", v);
        for (int i = 0; i < Tvertices; i++) // Put all the adjacent vertices that r in initial state
        {
            if (adj[v][i] != 0 && state[i] == initial)
            {
                insert_queue(i);
                // change state
                state[i] = waiting;
            }
        }
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
        printf("7 bfs\n");
        printf("8 dfs\n");

        int v;
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
        case 7:
            scanf("%d", &v);
            BFS(v);
            break;
        case 8:
            scanf("%d", &v);
            dfs(v);
            for (int i = 0; i < 101; i++)
            {
                isvisited[i] = 0;
            }

            break;
        }
        printf("\n\n");
    }
}