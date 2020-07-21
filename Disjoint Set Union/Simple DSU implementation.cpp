#include <iostream>
using namespace std;

class DSU{
public:
	int *parent;
	int size;
	
	DSU(int maxSize)
	{
		parent = new int[maxSize+1];
		for(int i = 0 ; i < maxSize ; i++)
			parent[i] = i;
		size = maxSize;
	}
	
	bool find(int A , int B)
	{
		if(parent[A] == parent[B])
			return true;
		else 
			return false;
	}
	
	void Union(int A , int B)
	{
		int temp = parent[A] ; 
		for(int i  = 0 ; i < size ; i++)
		{
			if(parent[i] == temp)
				parent[i] = parent[B];
		}
	}

};
int main()
{
	DSU dsu(10);
	dsu.Union(2,3);
	dsu.Union(4,5);
	dsu.Union(3,5);
	if(dsu.find(2,5))
		cout<<"2 and 5 are connected\n";
	else 
		cout<<"2 and 5 are disconnected\n";
}
