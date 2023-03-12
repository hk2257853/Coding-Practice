#include<iostream>
#include<climits>
using namespace std;
int ctr;
#define V 10
#define N INT_MAX
static int cost[V][V];
void dijkstras(int cost[V][V] , int src, int n)
{
	ctr++;
	int dist[n], index;	ctr++;
	bool S[n];	ctr++;
	ctr++;
	for(int i=0; i<n; i++){
		ctr++;
		dist[i] = cost[src][i]; ctr++;
		S[i]= false; ctr++;
	}
	dist[src]=0;	ctr++;
	
	ctr++;
	for(int i= 0; i<n-1; i++){
		ctr++;
		int min =N;	ctr++;
		ctr++;
		for(int j=0; j<n; j++){
			ctr++;
			if((S[j]==false) && (dist[j] <= min)){
				min = dist[j];	ctr++; // min & unvisited
				index=j;	ctr++;
			}
		}
		S[index] = true;	ctr++; 
		ctr++;
		for(int j = 0; j<n; j++){
			ctr++;
			ctr++; // Why N in graph as well?
			if(!S[j] && cost[index][j] !=N && dist[index] != N && (dist[index] + cost[index][j] < dist[j])){ // formula
				dist[j] = dist[index] + cost[index][j];	ctr++;
			}
		}
	}
	cout<<"\nVertex \t\t Distance from Source\n"; ctr++;
	ctr++;
	for (int i = 0; i < n; i++)
	{
		ctr++;
		ctr++;
		if(dist[i] == N){
			cout<<i<<" \t\t No Path"<<endl;	ctr++;
		}
		else{
			cout<<i<<" \t\t "<<dist[i]<<endl;	ctr++;
		}		
	} 
}
int main()
{
	int n, src;
	cout<<"\nENTER NUMBER OF VERTICES(n): ";	ctr++;
	cin>>n;	ctr++;
	cout<<"\nENTER SOURCE VETREX: ";	ctr++;
	cin>>src;	ctr++;
	
	cout<<"\nENTER COST OF EDGES: "<<"\n";	ctr++;
	for (int i=0;i<n;i++){
		ctr++; 
		for(int j=0;j<n;j++){
			ctr++;
			cin>>cost[i][j]; ctr++; 
			ctr++;
			if(cost[i][j]==0 && i!=j){
				cost[i][j]=N;	ctr++;  
			}
			ctr++;
			if(i==j){
				cost[i][j]=0;	ctr++;  
			}
		}
		ctr++; 
	}
	ctr++;
	dijkstras(cost, src, n);	ctr++;
	cout<<"\n\nSTEP COUNT: "<<ctr<<endl;
	return 0;
}
