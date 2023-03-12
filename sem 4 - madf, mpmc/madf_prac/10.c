#include "stdio.h"
#define n 6
int graph[n][n];
#include "limits.h"

// need to run n check
// not 100% sure if code I wrote is correct...

void BF(int src, int k)
{
    int dist[n];

    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
    }

    dist[src] = 0;
    

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(dist[j] != INT_MAX) // source reachable
            for (int l = 0; l < n; l++) // for its neighbors
            {
                if(graph[j][l] && (dist[j] + graph[j][l] < dist[l])) 
                    dist[l] = dist[j] + graph[j][l];
            }
            
        }        
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", dist[i]);
    }
    
    
}

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
    
}