#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[] , int size , int root)
{
	int maxVal = root ;
	int leftChild = 2*root + 1;
	int rightChild = 2*root + 2;
	
	if(leftChild < size && arr[leftChild] > arr[maxVal])
		maxVal = leftChild;
		
	if(rightChild < size && arr[rightChild] > arr[maxVal])
		maxVal = rightChild;
		
	if(maxVal != root)
	{
		swap(arr[root] , arr[maxVal]);
		heapify(arr , size , maxVal);
	}
}


void printArray(int arr[] , int size){
	
	for(int i = 0 ; i < size ; i++)
		cout<<arr[i]<<" ";
}

void heapSort(int arr[] , int size)
{
	int i;
	for(i = size/2 - 1 ; i>=0 ; i--)
		heapify(arr,size,i);
		
	for(i = size-1 ; i>=0 ; i--)
	{
		swap(arr[0] , arr[i]);
		heapify(arr , i , 0);
	}
	
	printArray(arr,size);
}


int main(){
	int arr[] = {4,5,7,9,2,4,5,7,3,5,7,3,235,5,45,4};
	int size = sizeof(arr)/sizeof(int);
	heapSort(arr,size);
}
