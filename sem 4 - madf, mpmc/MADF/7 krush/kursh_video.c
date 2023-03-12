#include <stdio.h>
#define V 5
#define max 9999
typedef enum{false, true}bool;

void print(int parent[V],int graph[V][V]) {
     printf("edge weight: \n");
    for(int i=1;i<V;i++)
    printf("%d-%d %d \n",parent[i],i,graph[i][parent[i]]); 
}                       //printing parent, the node and the weight of their edge

int min(int key[V],bool myset[V]) {
   int min = max,min_index;    //first min is set to infinity
   
   for(int i=0;i<V;i++)
    if(myset[i] == false && min >key[i])   //if not already selected and key is smaller than current min
        {min = key[i]; min_index = i;}   //make the key the new min and store its index
    //basically what we are doing is we are finding the minimum ofthe key[] array
    return min_index;
}


void primMST(int graph[][V]) {
    
    int key[V];      //store the minimum of the adjacent nodes 
    int parent[V];   //parent of the selected vertex
    bool myset[V];  //this stores the vertices which are already selected
    
    
    for(int i=0;i<V;i++) {
        key[i] = max;     //all the minimum distances from the source to others are infinity
        myset[i] = false;   //no vertex is selected yet. all are false
        
    }
    //0 is the first node
    key[0] = 0;     //the cost of selecting the first node is 0
    parent[0] = -1; //parent of 0 is -1
   
  for(int count = 0; count<V-1;count++) {   //for V-1 vertices 
   int u = min(key,myset);    //minimum of the key array 
   myset[u] = true;          //select that vertex
   
    for(int v = 0;v<V;v++) //for all nodes
    //if it is adjacent and not selected and  cost of edge is smaller than previous value of key[v]
    if(graph[u][v] && myset[v] == false && graph[u][v] < key[v]) {
    key[v] = graph[u][v];   //update the value of key 
        parent[v] = u;  // set parent of v as u (for updated ones it will be the parent...)
     
  }
    
  }
  
    print(parent,graph);
}
int main()
{
   int graph[V][V] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };
  
   primMST(graph);

    return 0;
}