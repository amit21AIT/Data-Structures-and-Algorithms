#include <bits/stdc++.h>
using namespace std;

class minHeap{
public:
	int *heap;
	int size , capacity;
	minHeap(int maxSize)
	{
		heap = new int[maxSize + 1];
		size = 0;
		capacity = maxSize;
	}
	
	void minHeapify(int root)
	{
		int minVal = root; 
		int leftChild = 2*root+1;
		int rightChild = 2*root+2;
		if(leftChild<size && heap[leftChild] < heap[minVal])
			minVal = leftChild;
		if(rightChild<size && heap[rightChild] < heap[minVal])
			minVal = rightChild;
		if(minVal!=root)
		{
			swap(heap[root] , heap[minVal]);
			minHeapify(minVal);
		}
	}
	
	void insert(int val)
	{
		if(size == capacity)
		{
			cout<<"Heap is full\n";
			return;
		}
		else 
		{
			heap[size++] = val;
			int current = size-1;
			while(heap[current] < heap[(current-1)/2])  //if inserted value is less than parent
			{
				swap(heap[current] , heap[(current-1)/2]);
				current = (current-1)/2;
			}
		}
	}
	
	int getMin()
	{
		int minval = heap[0];
		swap(heap[0] , heap[size-1]);
		size--;
		minHeapify(0);
		return minval;
	}
};

int main()
{
	minHeap h(10);
	h.insert(10);
	h.insert(234);
	h.insert(11);
	h.insert(54);
	h.insert(34);
	cout<<h.getMin()<<endl;
	cout<<h.getMin()<<endl;
	cout<<h.getMin()<<endl;
}
