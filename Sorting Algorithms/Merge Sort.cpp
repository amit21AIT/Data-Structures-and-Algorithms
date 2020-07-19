#include <bits/stdc++.h>
using namespace std;

void merge(int arr[] , int start, int mid , int end){
	
	int size1 = mid - start + 1 , size2 = end - mid , i , j , index;
	
	int leftHalf[size1+1] , rightHalf[size2+1];
	
	for(i = 0 ;  i < size1 ; i++)
		leftHalf[i] = arr[start+i];
	
	for(i = 0 ; i < size2 ; i++)
		rightHalf[i] = arr[mid+1+i];
		
	i = 0 , j = 0 , index = start;
	while(i<size1 && j<size2)
	{
		if(leftHalf[i]>rightHalf[j])
			arr[index++] = rightHalf[j++];
		else 
			arr[index++] = leftHalf[i++];
	}
	
	while(i<size1)
		arr[index++] = leftHalf[i++];
		
	while(j<size2)
		arr[index++] = rightHalf[j++];
	
	
}

void mergeSort(int arr[]  , int start , int end){
	
	if(start >= end)
		return ;
	int mid = start + (end-start)/2;
	
	mergeSort(arr , start , mid);
	mergeSort(arr , mid+1 , end);
	merge(arr , start , mid , end);
	
}

void printArray(int arr[] , int size){
	
	for(int i = 0 ; i < size ; i++)
		cout<<arr[i]<<" ";
}

int main()
{
	int arr[] = {5,67,34,4,7,83,2,6,3,6,7};
	int n = sizeof(arr)/sizeof(int);
	mergeSort(arr,0,n-1);
	printArray(arr,n);
}
