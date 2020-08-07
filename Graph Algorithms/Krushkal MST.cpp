#include <bits/stdc++.h>
using namespace std;
int parent[10000];

void initialize()
{
	for(int i = 0 ; i < 1e4 ; i++)
		parent[i] = i;
	
}

int root(int x)
{
	while(parent[x]!=x)
	{
		parent[x] = parent[parent[x]];
		x = parent[x];
	}
	return x;
}

void Union(int x , int y)
{
	int rootx = root(x);
	int rooty = root(y);
	parent[rootx] = parent[rooty];
}

long long KrushkalMST( pair< int , pair<int,int> > edges[] , int noOfEdges )
{
	long long minCost=0;
	for(int i = 0 ; i < noOfEdges ; i++)
	{
		int vertex1 = edges[i].second.first;
		int vertex2 = edges[i].second.second;
		
		if(root(vertex1) != root(vertex2))
		{
			minCost+=edges[i].first;
			Union(vertex1 , vertex2);
		}
	}
	
	return minCost;
	
}

int main()
{
	initialize();
	int i,j,noOfNodes,noOfEdges;
	cin>>noOfNodes;   
	cin>>noOfEdges;  
	pair < int ,  pair < int , int > > edges[noOfEdges];
	for(i = 0 ; i < noOfEdges ; i++)
	{
		int start , end , weight;
		
		cin>>start>>end>>weight;
		edges[i] = make_pair(weight , make_pair(start , end));
	}
	
	sort( edges , edges + noOfEdges);
	
	long long minCost = KrushkalMST(edges,noOfEdges);
	
	cout<<"Minimum cost is : "minCost<<endl;
	
}



