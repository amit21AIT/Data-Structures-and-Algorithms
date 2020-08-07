
#include <bits/stdc++.h>
using namespace std;
#define MAX 10005
vector < pair <int,int> > graph[10005];

bool visited[MAX];
int Distance[MAX];

void initialize()
{
	for(int i = 0 ; i < MAX ; i++)
		Distance[i] = INT_MAX;
}

void dijkstras()
{
	
	multiset < pair<int,int> > set;

	set.insert({0,1});

	while(!set.empty())
	{
		pair <int,int> temp = *set.begin();
		set.erase(set.begin());
		int node = temp.second , weight = temp.first;

 		if(visited[node])
 			continue;
 		visited[node] = true;

 		for(int i = 0 ; i < graph[node].size() ; i++)
 		{
 			int adjNode = graph[node][i].second , adjWeight = graph[node][i].first;

 			if(Distance[node] + adjWeight < Distance[adjNode])
 			{
 				Distance[adjNode] = Distance[node] + adjWeight;
 				set.insert({Distance[adjNode] , adjNode});
 			}
 		}

	}


}

int main()
{
	initialize();
	
	int noOfNodes , noOfEdges;
	cin >> noOfNodes >> noOfEdges;

	for(int i = 0 ; i < noOfEdges ; i++)
	{
		int startNode , endNode , weight;

		cin >> startNode >> endNode >> weight;

		graph[startNode].push_back({weight , endNode});
		graph[endNode].push_back({weight , startNode});
	}
	
	Distance[1] = 0;
	dijkstras();
	
	for(int i = 1 ; i <= noOfNodes ; i++)
			cout<<"Shortest Distance from 1 to "<<i<<" "<<Distance[i]<<endl;

}
