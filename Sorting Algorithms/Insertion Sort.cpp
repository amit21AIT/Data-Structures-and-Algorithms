#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[] , int size){
	
	for(int i = 0 ; i < size ; i++)
		cout<<arr[i]<<" ";
}


void insertionSort(int arr[] , int size)
{
	int i , j ;
	
	for( i = 1 ; i < size ; i++)
	{
		j = i-1;
		int val = arr[i];
		while(j>0 && arr[j]>val)
		{
			swap(arr[j] , arr[j+1]);
			j--;
		}
		arr[j] = val; 
	}
	printArray(arr , size);
}

int main()
{
	int arr[] = {1,5,3,2,5,8,4,0};
	int size = sizeof(arr)/sizeof(int);
	insertionSort(arr,size);
}
