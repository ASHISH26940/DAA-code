#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct Knapsack {
    int profit;
    int weight;
    double ratio;
};

bool compare(Knapsack a, Knapsack b) {
    return a.ratio > b.ratio; // Sort items by ratio in descending order
}

void display(Knapsack arr[], int n) {
    for(int i = 0; i < n; ++i) {
        cout <<"item "<<char(i+'A')<< "(" << arr[i].profit << ", " << arr[i].weight << ", " << arr[i].ratio << ")" << "\t";
    }
    cout << endl;
}

void knapsack(int W, Knapsack arr[], int n) {
    double totalProfit = 0.0;
    double remainingCapacity = W;
    vector<double> fraction(n, 0.0); // Initialize fraction vector with 0.0 for all items

    for(int i = 0; i < n; ++i) {
        if(arr[i].weight <= remainingCapacity) {
            // Take the whole item
            totalProfit += arr[i].profit;
            remainingCapacity -= arr[i].weight;
            fraction[i] = 1.0; // Set fraction to 1.0 indicating the whole item is taken
            cout << "Take " << arr[i].profit << " profit of item " << char(i+'A') << endl;
        } else if (remainingCapacity > 0) {
            // Take a fraction of the item
            fraction[i] = remainingCapacity / arr[i].weight;
            totalProfit += (fraction[i] * arr[i].profit);
            cout << "Take " << (fraction[i] * arr[i].profit) << " profit of item " << char(i+'A') << endl;
            remainingCapacity = 0; // Knapsack is full after taking a fraction
        }
    }

    cout << "Total profit: " << totalProfit << endl;
    cout << "The fractions of items taken are: { ";
    for(int i = 0; i < n; ++i) {
        cout << fraction[i];
        if (i != n - 1) {
            cout << ", ";
        }
    }
    cout << " }" << endl;
}

int main() {
    int n, W;

    cout << "Enter the number of items: ";
    cin >> n;

    cout << "Enter the knapsack capacity: ";
    cin >> W;

    Knapsack arr[n];

    cout << "Enter the profits for each item: ";
    for(int i = 0; i < n; ++i) {
        cin >> arr[i].profit;
    }

    cout << "Enter the weights for each item: ";
    for(int i = 0; i < n; ++i) {
        cin >> arr[i].weight;
        arr[i].ratio = (double)arr[i].profit / arr[i].weight; // Calculate ratio
    }

    // Sort items based on the profit-to-weight ratio
    sort(arr, arr + n, compare);

    cout << "Items after sorting based on profit-to-weight ratio:" << endl;
    display(arr, n);

    cout << "Items selected and profit obtained:" << endl;
    knapsack(W, arr, n);

    return 0;
}

