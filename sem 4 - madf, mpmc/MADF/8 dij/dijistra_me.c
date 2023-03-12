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
    } // didn't do the infinity part here

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
        {// why isvis check is req? If its true will make calculating table easier
            if(isvis[j] == 0 && (dis[j] > dis[index] + graph[index][j])) dis[j] = dis[index] + graph[index][j]; // formula given by sir
        }
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
    int src = 0;
    dij(src);

}

/*
3 vertices:
0 1 5
0 2 4
1 0 1
1 2 6
2 0 2
-1

5 vertices:
0 1 5
0 2 3
1 3 3
2 1 2
2 3 4
2 4 6
4 3 1
-1
*/
