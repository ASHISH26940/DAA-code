#include<iostream>
using namespace std;

void merge(int arr[],int low,int mid,int high)
{
    int i=low;
    int j=high;
    int k=low;
    int b[100];
    while(i<=mid && j<=high)
    {
        if(arr[i]<arr[j])
        {
            b[++k]=arr[i++];
        }else{
            b[++k]=arr[j++];
        }
    }

    while(i<mid)
    {
        arr[k++]=b[i++];
    }

    while(j<high)
    {
        arr[++k]=b[j++];
    }

}

void mergeSort(int arr[],int low,int high)
{
    if(low<high)
    {
        int mid=low+(high-low)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);

    }
}