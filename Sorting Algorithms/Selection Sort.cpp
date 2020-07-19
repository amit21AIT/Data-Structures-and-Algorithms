#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[] , int size){
	
	for(int i = 0 ; i < size ; i++)
		cout<<arr[i]<<" ";
}

void selectionSort(int arr[] , int size){
	
	int i,j,minIndex;
	for( i = 0 ; i < size ; i++)
	{
		minIndex = i;
		for(j = i+1 ; j < size ; j++)
		{
			if(arr[j] < arr[minIndex])
				minIndex = j;
		}
		swap(arr[i] , arr[minIndex]);
	}
	printArray(arr , size);
	
}

int main()
{
	int arr[] = {3,5,7,3,7,8,98,2,5,54,35};
	int size = sizeof(arr)/sizeof(int);
	selectionSort(arr,size);
}
