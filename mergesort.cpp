#include<iostream>
#include<fstream>
using namespace std;

void merge(int a[], int low, int mid, int high) {
    int i = low;
    int j = mid + 1;
    int k = low;
    int b[100];  // Temporary array

    while (i <= mid && j <= high) {
        if (a[i] < a[j]) {
            b[k++] = a[i++];
        } else {
            b[k++] = a[j++];
        }
    }

    while (i <= mid) {
        b[k++] = a[i++];
    }

    while (j <= high) {
        b[k++] = a[j++];
    }

    for (int i = low; i <= high; ++i) {
        a[i] = b[i];
    }
}

void mergesort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);
        merge(arr, low, mid, high);
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

    mergesort(arr, 0, n - 1);

    cout << "The sorted array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

