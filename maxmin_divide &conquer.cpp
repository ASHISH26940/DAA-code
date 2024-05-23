#include<iostream>
using namespace std;

void maxmin(int a[], int i, int j, int &max, int &min) {
    if (i == j) {
        max = min = a[i];
    } else if (i == j - 1) {
        if (a[i] < a[j]) {
            max = a[j];
            min = a[i];
        } else {
            max = a[i];
            min = a[j];
        }
    } else {
        int mid = (i + j) / 2;
        int max1, min1;
        maxmin(a, i, mid, max, min);
        maxmin(a, mid + 1, j, max1, min1);
        if (max < max1) {
            max = max1;
        }
        if (min > min1) {
            min = min1;
        }
    }
}

int main() {
    int n, max, min;
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
    
    maxmin(arr, 0, n - 1, max, min);
    cout << "Maximum element: " << max << endl;
    cout << "Minimum element: " << min << endl;
    
    return 0;
}
