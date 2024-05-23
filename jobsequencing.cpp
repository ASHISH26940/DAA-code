#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Job {
    char id;
    int deadline;
    int profit;
};

bool comparison(Job a, Job b) {
    return (a.profit > b.profit);
}

void printJobScheduling(Job arr[], int n) {
    int result[n];
    bool slot[n];

    for (int i = 0; i < n; i++)
        slot[i] = false;

    sort(arr, arr + n, comparison);

    for (int i = 0; i < n; i++) {
        for (int j = min(n, arr[i].deadline) - 1; j >= 0; j--) {
            if (slot[j] == false) {
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }
    
    int totalProfit = 0;
    for (int i = 0; i < n; i++) {
        if (slot[i]) {
            totalProfit += arr[result[i]].profit;
            cout << arr[result[i]].id << " ";
        }
    }
    cout << "\nTotal Profit: " << totalProfit << endl;
}

int main() {
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;

    Job arr[n];

    cout << "Enter job details (id, deadline, profit):" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].id >> arr[i].deadline >> arr[i].profit;
    }

    cout << "Following is the maximum profit sequence of jobs" << endl;
    printJobScheduling(arr, n);

    return 0;
}

