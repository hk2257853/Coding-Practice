#include "stdio.h"
#include "limits.h"
// path compression n union by size - later (easy only). Also see the TC part (luv's video)
// not working


int parent[100000000];

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bsort(int a[], int b[], int w[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if(w[j] > w[j + 1]) 
            {
                swap(&w[j], &w[j + 1]);
                swap(&a[j], &a[j + 1]);
                swap(&b[j], &b[j + 1]);
            }
        }        
    }
}

void make(int v)
{
    parent[v] = v;
}

int find(int v)
{
    if(v == parent[v]) return v;
    return find(parent[v]);
}

void Union(int a, int b)
{
    a = find(a);
    b = find(b);
    if(a != b) 
    {
        parent[b] = a;
    }

}

int main()
{
    int n, m; // num of vertices & edges
    scanf("%d%d", &n, &m);
    int a[n]; // edge a to b with weight wt
    int b[n];
    int wt[n];
    bsort(a, b, wt, m); 

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        a[i] = u;
        b[i] = v;
        wt[i] = w;
    }
    
    // sort

    for (int i = 1; i <= n; i++)
    {
        make(i);
    }
    
    // logic: take min, avoid cycle
    int Tcost = 0;
    for (int i = 0; i < m; i++)
    {
        int w = wt[i];
        int u = a[i];
        int v = b[i];
        if(find(u) == find (v)) continue; // if same parent... cycle will formed
        Union(u, v);
        Tcost += w;
        printf("u %d   v %d\n", u, v);
    }
    
    printf("%d", Tcost);


}


