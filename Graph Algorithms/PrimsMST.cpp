#include <bits/stdc++.h>
using namespace std;


bool visited[10005];
vector < pair<int,int>  > graph[10005];

long long PrimsMST(int source)
{
	multiset < pair<int,int> > set;
	long long minCost = 0;

	set.insert({0,source});

	while(!set.empty())
	{
		pair<int,int> temp = *set.begin();
		set.erase(set.begin());
		int node = temp.second;
		if(visited[node])
				continue;
		visited[node] = true;
        minCost += temp.first;
		for(int  i = 0 ; i < graph[node].size() ; i++ )
		{
			int adjNode = graph[node][i].second , weight = graph[node][i].first;

			if(visited[adjNode] == false)
				set.insert({weight , adjNode});

		}


	}
	return minCost;

	

}

int main()
{
	int noOfNodes , noOfEdges , i , j;
	
	cin>>noOfNodes>>noOfEdges;
	
	for(i = 0 ; i < noOfEdges ; i++)
	{
		int startNode , endNode , weight;

		cin>>startNode>>endNode>>weight;
		graph[startNode].push_back({weight , endNode});
		graph[endNode].push_back({weight , startNode});
	}

	long long minCost = PrimsMST(1);
	cout<<"The minimum cost is : "<<minCost;
}

