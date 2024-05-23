#include<iostream>
using namespace std;

void quickSort(int arr[],int low,int high)
{
    if(low<high)
    {
        int p=quick(arr,low,high);
        quickSort(arr,low,p-1);
        quickSort(arr,p+1,high);
    }
}

int quick(int arr[],int low,int high)
{
    int pivot=arr[low];
    int i=low-1;
    for(int j=low;j<high;j++)
    {
        if(arr[j]<pivot)
        {
            i=i+1;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],high);
    return i+1;
}