#include<iostream>
#include<fstream>
using namespace std;
int partition(int arr[],int low,int high){
	int pivot=arr[high];
	int i=low-1;
	for(int j=low;j<=high;++j){
		if(arr[j]<pivot){
			i=i+1;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i+1],arr[high]);
	return i+1;
}
void quicksort(int arr[],int low,int high){
	if(low<high){
	int p=partition(arr,low,high);
	quicksort(arr,low,p-1);
	quicksort(arr,p+1,high);
	}
}
int main() {
    int n;
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

    quicksort(arr, 0, n - 1);

    cout << "The sorted array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

