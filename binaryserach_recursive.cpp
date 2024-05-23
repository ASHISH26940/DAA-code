#include <iostream>
using namespace std;

// Recursive function to perform binary search
int binarysearch(int a[], int low, int high, int x) {
    if (high < low) {
        return -1;
    }

    int mid = low + (high - low) / 2; // Calculate mid-point to avoid potential overflow

    if (a[mid] == x) {
        return mid; // Element found
    } else if (a[mid]> x) {
        return binarysearch(a, low, mid - 1, x); // Search in the right half
    } else {
        return binarysearch(a, mid + 1, high, x); // Search in the left half
    }
}

int main() {
    int n, x;

    // Input the size of the array
    cout << "Enter the size of the array: ";
    cin >> n;

    // Ensure the array size is within the limit
    if (n > 100) {
        cout << "Array size should be 100 or less." << endl;
        return 1;
    }

    int arr[100];

    // Input the elements of the array
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Display the entered array
    cout << "The entered array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Input the element to search
    cout << "Enter the element to search: ";
    cin >> x;

    // Perform binary search
    int c = binarysearch(arr, 0, n - 1, x);

    // Output the result
    if (c == -1) {
        cout << "The element is not found" << endl;
    } else {
        cout << "The element is found at index " << c << endl;
    }

    return 0;
}

