#include <bits/stdc++.h>
using namespace std;
void quickSelect(int arr[] ,int start, int end , int k)
{
    if(start>=end)
        return;
    int pivot = end , i = start ;
    for(int j = start ; j < end ; j++)
    {
        if(arr[j]<=arr[pivot])
            swap(arr[i++],arr[j]);
        
    }
    swap(arr[i],arr[pivot]);
    if(i==k-1)
        return;
    else if(i<k-1)
        quickSelect(arr,i+1,end,k);
    else 
        quickSelect(arr,start,i-1,k);
}

int main()
{
    int i,j,n,m,t,k;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int arr[n];
        for(i = 0 ; i < n ; i++)
        {
            cin>>arr[i];
        }
        cin>>k;
        quickSelect(arr,0,n-1,k);
        cout<<arr[k-1]<<endl;
    }
}
