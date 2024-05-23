#include<iostream>
using namespace std;

int maxmin(int arr[],int i,int j,int &max,int &min)
{
    int max,min;
    if(arr[i]==arr[j])
    {
        max=min=arr[i];
    }
    else if(arr[i]==arr[j-1])
    {
        if(arr[i]>arr[j])
        {
            max=arr[i];
            min=arr[j];
        }else{
            max=arr[j];
            min=arr[i];
        }
    }else{
        int max1,min1;
        int mid=(i+j)/2;
        maxmin(arr,i,mid,max,min);
        maxmin(arr,mid+1,j,max,min);
        if(max<max1)
        {
            max=max1;
        }
        if(min>min1){
            min=min1;
        }
    }
}