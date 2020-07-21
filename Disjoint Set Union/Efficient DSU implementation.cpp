#include <iostream> 
using namespace std;

class DSU{
public :
	int *parent , *size , maxSize ;
	
	DSU(int N)
	{
		maxSize = N;
		parent = new int[maxSize+1];
		for(int i = 0 ; i <= maxSize ; i++)
		{
			size[i] = 1;
			parent[i] = i;
		}
	}
	
	int root(int A)
	{
		// path compression , Time Complexity = log*n
		while(parent[A] != A)
		{
			parent[A] = parent[parent[A]];
			A = parent[A];
		}
		return A;
	}
	bool find(int A , int B)
	{
		int rootA = root(A);
		int rootB = root(B);
		if(rootA == rootB)
			return true;
		else 
			return false;
	}
	
	bool weightedUnion(int A , int B)
	{
		int rootA = root(A);
		int rootB = root(B);
		if(size[rootA]>=size[rootB])
		{
			parent[rootB] = parent[rootA];
			size[rootA]+=size[rootB];
		}
		else 
		{
			parent[rootA] = parent[rootB];
			size[rootB]+=size[rootA];
		}
	}
};

int main()
{
	DSU dsu(10);
	dsu.weightedUnion(1,3);
	dsu.weightedUnion(2,5);
	dsu.weightedUnion(4,6);
	dsu.weightedUnion(1,4);
	if(dsu.find(3,6))
		cout<<"3 and 6 are connected\n";
	else 
		cout<<"3 and 6 are disconnected\n";
				
	
}
