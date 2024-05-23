#include<iostream>
using namespace std;
int binarysearch(int a[],int low,int high,int x){
	while(low<=high){
		int mid=low+(high-low)/2;
		if(a[mid]==x){
			return mid;
		}
		if(a[mid]<x){
			low=mid+1;
		} 
		else{
			high=mid-1;
		}
	}
	return -1;	
}
int main() {
    int n,x;
    int arr[100];
    cout << "Enter the size of the array: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << "The entered array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout<<"Enter the element to search:";
    cin>>x;
    int c=binarysearch(arr,0,n-1,x);
    (c==-1)?cout<<"The element is not found"
    	   :cout<<"The element is found at index "<<c;
    return 0;
}
