#include<iostream>
using namespace std;
void heapify(int arr[],int N,int i){
	int largest=i;
	int l=2*i+1;
	int r=2*i+2;
	if(l<N && arr[l]>arr[largest]){
		largest=l;
	}
	if(r<N && arr[r]>arr[largest]){
		largest=r;
	}
	if(largest!=i){
		swap(arr[i],arr[largest]);
		heapify(arr,N,largest);
	}
}
void heapsort(int arr[],int N){
	for(int i=N/2-1;i>=0;--i){
		heapify(arr,N,i);
	}
	for(int i=N-1;i>0;--i){
		swap(arr[0],arr[i]);
		heapify(arr,i,0);
	}
}
int main(){
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

   heapsort(arr,n);

    cout << "The sorted array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
