#include<iostream>
using namespace std;

int binary(int arr[],int low,int high,int key)
{
    if(low<=high)
    {
        int mid=(low+high)/2;

        if(arr[mid]==key)
            return;
        if(arr[mid]<key)
            return binary(arr,mid+1,high,key);
        return binary(arr,low,mid-1,key);
    }
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 10;

    int result = binary(arr, 0, n - 1, target);
    if (result != -1) {
        cout << "Element is present at index " << result << endl;
    } else {
        cout << "Element is not present in array" << endl;
    }

    return 0;
}