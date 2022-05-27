/*Program 3.7 : Program for constructing a minimum cost spanning tree of a graph using Prim's algorithm.*/

#define infinity 9999
#define MAX 20
#include<conio.h>
#include<iostream.h>
#include<stdlib.h>
class graph
{ int G[MAX][MAX];
  int n;
  public:
		graph()
	{ n=0; }
		void readgraph();
		int  prims(graph &);
};
void graph:: readgraph()
{ int i,j;
  cout <<"\nEnter No. of vertices : ";
  cin>>n;
  cout<<"\nEnter the adjacency matrix : ";
	for(i=0;i<n;i++)
	  for(j=0;j<n;j++)
		 cin>>G[i][j];
}



int  graph::prims(graph &spanning)
{
	int cost[MAX][MAX];
	int u,v,min_distance,distance[MAX],from[MAX];
	int visited[MAX],no_of_edges,i,min_cost,j;
//	create cost[][] matrix ,spanning[][]
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			if(G[i][j]==0)
				cost[i][j]=infinity;
			else
				cost[i][j]=G[i][j];
				 spanning.G[i][j]=0;
		}
//	initialise visited[],distance[] and from[]
	distance[0]=0;
	visited[0]=1;
	for(i=1;i<n;i++)
	{
		distance[i]=cost[0][i];
		from[i]=0;
		visited[i]=0;
	}
	min_cost=0;            //cost of spanning tree
	no_of_edges=n-1;       //no.of edges to be added
	while(no_of_edges>0)
	{
		//find the vertex at minimum distance from the tree
		min_distance=infinity;
		for(i=1;i<n;i++)
			if(visited[i]==0 && distance[i] < min_distance)
			{
				v=i;
				min_distance=distance[i];
			}
		u=from[v];
		// insert the edge in spanning tree
		spanning.G[u][v]=distance[v];
		spanning.G[v][u]=distance[v];
		no_of_edges--;
		visited[v]=1;
		// update the distance[] array
		for(i=1;i<n;i++)
			if(visited[i]==0 && cost[i][v] < distance[i])
			{
				distance[i]=cost[i][v];
				from[i]=v;
			}
		min_cost=min_cost+cost[u][v];
	}
	spanning.n=n;
	return(min_cost);
}


//  ,spanning[MAX][MAX],n;
//int prims();
void main()
{
	graph g1,spanning;
	g1.readgraph();
	int total_cost=g1.prims(spanning);
	cout <<"\nTotal cost of spanning tree= "<<total_cost;
	getch();
}


