#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[] , int size)
{
	cout<<"The sorted array is : ";
	for(int i =  0 ; i < size ; i++)
		cout<<arr[i]<<" ";
	
	cout<<endl;
}

void bubbleSort(int arr[] , int size)
{
	for(int i  = 0 ;  i < size ; i++)
	{
		for(int j = i+1 ; j < size ; j++)
		{
			if(arr[j]<arr[i])
				swap(arr[i],arr[j]);
		}
	}
	
	printArray(arr , size);
}

int main()
{
	int arr[]  = {2,4,67,2,5,54,23,65,14};
	int size = sizeof(arr)/sizeof(int);
	bubbleSort(arr , size );
}
