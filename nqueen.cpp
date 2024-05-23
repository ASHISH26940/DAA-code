#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool place(int k, int i, int x[]) {
    // Returns true if a queen can be placed in the kth row and ith column
    // of the chessboard represented by the array x
    // x[1:n] is a global array whose first (k - 1) values have been set
    
    for (int j = 1; j < k; ++j) {
        // Check if two queens are in the same column or diagonal
        if (x[j] == i || abs(x[j] - i) == abs(j - k)) {
            return false;
        }
    }
    return true;
}

void n_queens(int k, int n,int x[]) {
    // Using backtracking, this function prints all possible placements of n queens
    // on an n x n chessboard so that they are non-attacking.
    
    if (k >n) {
        // Base case: all queens are placed
        vector<int> solution;
        cout<<"=================================================="<<endl;
        cout<<"Possible combination and corresponding chessboard:"<<endl;
        cout<<"=================================================="<<endl;
        for (int i = 1; i <= n; ++i) {
        	solution.push_back(x[i]);
            cout << x[i] << " ";
        }
        cout << endl;
        cout << endl;
       for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (solution[i] == j + 1) {
                cout << "Q ";
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }
        return;
    }
    
    for (int i = 1; i <= n; ++i) {
        if (place(k, i, x)) {
            x[k] = i;
            n_queens(k + 1, n, x);
        }
    }
    
}


int main() {
    int n;
    cout << "Enter the size of the chessboard (n x n): ";
    cin >> n;
    int x[n]; // x[0] is unused
    //vector<int> solution;
    n_queens(1, n, x);
   // printchessboard( n);
	cout << endl;
    return 0;
}
