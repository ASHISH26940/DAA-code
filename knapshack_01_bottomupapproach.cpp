#include <iostream>
using namespace std;

#define max1 20

struct Knapsack01 {
    int profit;
    int weight;
    double ratio;
};

void knapsackbuild(int M, Knapsack01 arr[], int n, int x[max1][max1]) {
    // Initialize the DP table
    for (int i = 0; i <= n; ++i) {
        for (int w = 0; w <= M; ++w) {
            if (i == 0 || w == 0)
                x[i][w] = 0;
            else if (arr[i - 1].weight <= w)
                x[i][w] = max(arr[i - 1].profit + x[i - 1][w - arr[i - 1].weight], x[i - 1][w]);
            else
                x[i][w] = x[i - 1][w];
        }
    }
}
void printTable(int M, Knapsack01 arr[], int n, int x[max1][max1]) {
    cout << "Dynamic Programming Table (x):" << endl;
    for (int i = 0; i <= n; ++i) {
        for (int w = 0; w <= M; ++w) {
            cout << x[i][w] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}
void printknapsack(int M, Knapsack01 arr[], int n) {
    int x[max1][max1]; // Define x array here

    knapsackbuild(M, arr, n, x); // Build the knapsack DP table

    int Totalprofit = x[n][M];
    int w = M;
    printTable(M,arr,n,x);

    cout << "Items selected:" << endl;
    for (int i = n; i > 0 && Totalprofit > 0; --i) {
        if (x[i][w] != x[i - 1][w]) {
            cout << "Item " << char('A' + i - 1) << "\t"; // Use char('A' + i - 1) to represent item names
            Totalprofit -= arr[i - 1].profit;
            w -= arr[i - 1].weight;
        }
    }
    cout << endl;
    
}

int main() {
    int n, M;

    cout << "Enter the number of items: ";
    cin >> n;

    cout << "Enter the knapsack capacity: ";
    cin >> M;

    Knapsack01 arr[n];

    cout << "Enter the profits for each item: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].profit;
    }

    cout << "Enter the weights for each item: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].weight;
        arr[i].ratio = (double)arr[i].profit / arr[i].weight; // Calculate ratio
    }

    printknapsack(M, arr, n); // Solve and display the knapsack solution
    return 0;
}

