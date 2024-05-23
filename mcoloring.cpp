#include <iostream>
#include <fstream>
#define MAX_N 100
using namespace std;

int x[MAX_N]; // Array to store colors of vertices
int graph[MAX_N][MAX_N]; // adjacency matrix
int n; // Number of vertices
int m; // Number of colors

void readGraph() {
    ifstream infile("mcoloring.txt");
    //infile.open("mcoloring.txt", ios::in);
    if (!infile) {
        cout << "Error opening the file." << endl;
        exit(1);
    }
    infile >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            infile >> graph[i][j];
        }
    }
    infile.close();
}

void showGraph() {
    cout << "Graph Adjacency Matrix:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%3d", graph[i][j]);
        }
        printf("\n");
    }
}

void NextValue(int k) {
    do {
        x[k] = (x[k] + 1) % (m + 1); // Next highest color
        if (x[k] == 0) return; // All colors have been exhausted
        int j;
        for (j = 0; j < k; j++) {
            if (graph[k][j] && x[j] == x[k]) break; // Check if adjacent vertices have identical colors
        }
        if (j == k) return; // New color found
    } while (true);
}

void mColoring(int k) {
    do {
        NextValue(k); // Assign to x[k] a legal color
        if (x[k] == 0)	 return; // No new color possible
        if (k == n - 1) { // If at most m colors are assigned to n vertices
            for (int i = 0; i < n; i++) {
                cout << x[i] << " ";
            }
            cout << endl;
        } else {
            mColoring(k + 1);
        }
    } while (true);
}

int main() {
    readGraph();
    showGraph();

    cout << "Enter the maximum number of colors that can be used: ";
    cin >> m;

    // Start coloring from vertex 0
    cout<<"The coloring:\n";
    mColoring(0);

    return 0;
}

