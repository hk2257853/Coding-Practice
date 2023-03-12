#include <stdio.h>
int maxedge;
int edgemin=0;
int edgecount=0;
int mincost=0;
typedef struct{
  int data;
  int setno;
}vertex;
typedef struct{
  int src;
  int dst;
  int wt;
}edge;

void merge(edge arr[],edge tmp[],int low1,int high1,int low2,int high2)
{
  int i=low1,j=low2,k=low1;
  while(i<=high1 && j<=high2)
  {
    if(arr[i].wt<=arr[j].wt)
      tmp[k++]=arr[i++];
    else
      tmp[k++]=arr[j++];
  }
  while(i<=high1)
    tmp[k++]=arr[i++];
  while(j<=high2)
    tmp[k++]=arr[j++];
}

void copy(edge arr[],edge tmp[],int low,int high)
{
  int i;
  for(i=low;i<=high;i++)
    arr[i]=tmp[i];
}

void merge_sort(edge arr[],int low,int high)
{
  int mid;
  edge tmp[20];
  if(low<high)
  {
    mid=(low+high)/2;
   
    merge_sort(arr,low,mid);
    merge_sort(arr,mid+1,high);
   
    merge(arr,tmp,low,mid,mid+1,high);
    copy(arr,tmp,low,high);
  }
}

void creategraph(vertex ver[],edge edg[],int v)
{
  int src,dst,wt,flag=0;
  while(1)
    {
      printf("\nEnter edge or (-1,-1) to exit :");
      scanf("%d%d",&src,&dst);
      if(src==-1 && dst==-1)
        break;
      if(src<0 || src>=v || dst<0 || dst>=v)
      {
        printf("\nInvalid edge");
        continue;
      }
      else{
        printf("\nEnter weight : ");
        scanf("%d",&wt);
        for(int i=0;i<edgecount;i++)
          {
            if((edg[i].src==src && edg[i].dst==dst)||(edg[i].src==dst && edg[i].dst==src))
            {
              edg[i].wt=wt;
              flag=1;
              break;
            }
          }
        if(flag==1)
          continue;
        else
        {
          edg[edgecount].src=src;
          edg[edgecount].dst=dst;
          edg[edgecount].wt=wt;
          edgecount++;
        }         
      }
    } 
}
void kruskal(vertex ver[],edge edg[],int A[][3],int v)
{
  int set,index=0;
  for(int i=0;i<edgecount;i++)
    {
      if(ver[edg[i].src].setno!=ver[edg[i].dst].setno)
      {
        A[index][0]=edg[i].src;
        A[index][1]=edg[i].dst;
        A[index][2]=edg[i].wt;
        mincost=mincost+edg[i].wt;
        index++;
        set=ver[edg[i].dst].setno;
        for(int j=0;j<v;j++)
          {
            if(ver[j].setno==set)
              ver[j].setno=ver[edg[i].src].setno;
          }
      }
    }
}
int main(void) {
  int v;
  printf("\nEnter number of vertices : ");
  scanf("%d",&v);
  maxedge=v*(v-1)/2;
  vertex ver[v];
  edge edg[maxedge];
  int A[v-1][3];
  for(int i=0;i<v;i++)
    {
      ver[i].data=i;
      ver[i].setno=i;
    }  
  creategraph(ver,edg,v);
  merge_sort(edg,0,edgecount-1);
  kruskal(ver,edg,A,v);

  
  
  for(int i=0;i<v-1;i++)
    {
      for(int j=0;j<2;j++)
        {
          printf("%d",A[i][j]);
          printf(" --> ");
        }
      printf(" (%d)\n",A[i][2]);
    }
  printf("Cost of MST = %d",mincost);
  return 0;
}


Enter number of vertices : 4
Enter edge or (-1,-1) to exit :1 2
Enter weight : 8
Enter edge or (-1,-1) to exit :1 0
Enter weight : 2
Enter edge or (-1,-1) to exit :1 3
Enter weight : 10
Enter edge or (-1,-1) to exit :2 0
Enter weight : 4
Enter edge or (-1,-1) to exit :-1 -1
1 --> 0 -->  (2)
2 --> 0 -->  (4)
1 --> 3 -->  (10)
Cost of MST = 16