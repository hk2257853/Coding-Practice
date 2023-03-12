#include "stdio.h"
#define n 6
int graph[n][n];
#include "limits.h"

int main()
{
    int u, v, val;
    while (1)
    {
        scanf("%d", &u);
        scanf("%d", &v);
        scanf("%d", &val);
        if(u == -1 || v == -1) break;
        graph[u][v] = val;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(graph[i][j] == 0 && i != j) graph[i][j] == INT_MAX;
        }
    }

    // NOTE: thought process like the comment will be great!
    for (int i = 0; i < n; i++) // Pick all vertices as source one by one
    {
        for (int j = 0; j < n; j++) // Pick all vertices as destination for the
            // above picked source
        {
            for (int k = 0; k < n; k++) // check if using k as intermediate reduces the dist...
            {
                if(graph[i][j] < graph[i][k] + graph[k][j]) graph[i][j] = graph[i][k] + graph[k][j];
            }
            
        }
        
    }    

    return 0;
}