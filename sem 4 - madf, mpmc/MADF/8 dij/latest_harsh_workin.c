// This one is working fine. need to check with edge cases...

#include <stdio.h>
#define n 5
#include <limits.h>
int isvis[n];
int graph[n][n];

void dij(int src)
{
    int dis[n]; // ans array

    // initial
    for(int i = 0; i < n; i++)
    {
        dis[i] = graph[src][i];
    }

    dis[src] = 0; // is this even req?

    for(int i = 0; i < n - 1; i++) // not sure about the n-1 part... there r n-1 rows... maybe correct
    {   // get min & unvisited
        int min = INT_MAX, index;
        for(int j = 0; j < n; j++)
        {
            if(isvis[j] == 0 && min >= dis[j])
            {
                index = j;
                min = dis[j];
            }
        }
        isvis[index] = 1;
        // update the dis array with selected index
        for(int j = 0; j < n; j++)
        {// why isvis check is req? - see later. Its the theory part
        // why need to put N in grpah as well?
            if(isvis[j] == 0 && dis[index] != INT_MAX && graph[index][j] != INT_MAX && (dis[j] > dis[index] + graph[index][j])) dis[j] = dis[index] + graph[index][j]; // formula given by sir
        } // I still don't get why the 1st checks r req...
    }

    for(int i = 0; i < n; i++)
    {
        
        printf("%d ", dis[i]);
    }

}

int main()
{
    int a, b, val;
    while(1)
    {
        scanf("%d", &a);
        if(a == -1) break;
        scanf("%d", &b);
        scanf("%d", &val);
        graph[a][b] = val;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(graph[i][j] == 0 && i != j) graph[i][j] = INT_MAX;   
        }        
    }

    int src = 0;
    dij(src);

}

/*
0 1 100
0 2 4
1 0 5
2 0 2
2 1 6
-1

*/
