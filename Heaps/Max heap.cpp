#include <bits/stdc++.h>
using namespace std;

class maxHeap{
public:
	int *heap; 
	int size , capacity;
	maxHeap(int maxSize){
		size = 0;
		heap = new int[maxSize+1];
		capacity = maxSize;
	}
	bool isLeaf(int pos){
		if(pos>=size/2 && pos <=size)
		return true;
		
		return false;
	}
	
	void maxHeapify(int root){
		
	int maxVal = root ;
	int leftChild = 2*root + 1;
	int rightChild = 2*root + 2;
	
	if(leftChild < size && heap[leftChild] > heap[maxVal])
		maxVal = leftChild;
		
	if(rightChild < size && heap[rightChild] > heap[maxVal])
		maxVal = rightChild;
		
	if(maxVal != root)
	{
		swap(heap[root] , heap[maxVal]);
		maxHeapify(maxVal);
	}
	
    }
    
    void insert(int val){
    	if(size==capacity)	
    	{
    		cout<<"Heap is full\n";
    		return ;
		}
    	heap[size++] = val;
    	int current = size-1;
    	while(heap[current] > heap[(current-1)/2])
    	{
    		swap(heap[current] , heap[(current-1)/2]);
    		current = (current-1)/2;
    	}
    		
	}
	
	int getMax()
	{
		int maxVal = heap[0];
		heap[0] = heap[size-1];
		size--;
		maxHeapify(0);
		return maxVal;
	}
	
	
};

int main()
{
	maxHeap h(10);
	h.insert(10);
	h.insert(234);
	h.insert(11);
	h.insert(54);
	h.insert(34);
	cout<<h.getMax()<<endl;
	cout<<h.getMax()<<endl;
	cout<<h.getMax()<<endl;
}
