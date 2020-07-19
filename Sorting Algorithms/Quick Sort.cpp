#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[] , int size){
	
	for(int i = 0 ; i < size ; i++)
		cout<<arr[i]<<" ";
}

int partition(int arr[] , int start , int end)
{
	int pivot = end;
	int i = start , j;
	
	for(j = start ; j < end ; j++)
	{
		if( arr[j] < arr[pivot] )
				swap(arr[i++] , arr[j]);
	}
		swap(arr[i],arr[pivot]);
		
	return i;

}

void quickSort(int arr[] , int start , int end)
{
	if(start>=end)
		return ;
	int partitionIndex = partition(arr , start , end);
	
	quickSort(arr , start , partitionIndex-1);
	quickSort(arr , partitionIndex + 1, end);
	
}


int main()
{
	int arr[] = {3,10,5,2,14,24,17,22};
	int size = sizeof(arr) / sizeof(int);
	quickSort(arr , 0 ,size-1);
	printArray(arr , size);
}
