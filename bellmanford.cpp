#include <iostream>
#include <fstream>
#include <limits.h>
using namespace std;

#define MAX_VERTICES 10 // Maximum number of vertices

int graph[MAX_VERTICES][MAX_VERTICES];
int n;

void readGraph() {
    fstream infile;
    infile.open("bellmanford.txt", ios::in);
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

void bellmanFord(int source) {
    int dist[MAX_VERTICES];
    int prev[MAX_VERTICES];

    // Step 1: Initialize distances and predecessors
    for (int i = 0; i < n; ++i) {
        dist[i] = INT_MAX;
        prev[i] = -1;
    }
    dist[source] = 0;

    // Step 2: Relax edges repeatedly
    for (int i = 0; i < n - 1; ++i) {
        for (int u = 0; u < n; ++u) {
            for (int v = 0; v < n; ++v) {
                if (graph[u][v] != 0 && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                    prev[v] = u;
                }
            }
        }
    }

    // Step 3: Check for negative cycles
    bool hasNegativeCycle = false;
    for (int u = 0; u < n; ++u) {
        for (int v = 0; v < n; ++v) {
            if (graph[u][v] != 0 && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                cout << "Graph contains negative cycle reachable from source " << source << endl;
                hasNegativeCycle = true;
                return;
            }
        }
    }

    // Display shortest distances from source
    if (!hasNegativeCycle) {
        cout << "Shortest distances from source " << source << ":" << endl;
        for (int i = 0; i < n; ++i) {
            cout << "Vertex " << char(i+'A')<< ": Distance = " << dist[i];
            if (prev[i] != -1) {
                cout << ", Previous vertex = " << char(prev[i]+'A');
            }
            cout << endl;
        }

        // Check if all vertices are reachable
        bool allReachable = true;
        for (int i = 0; i < n; ++i) {
            if (dist[i] == INT_MAX) {
                allReachable = false;
                break;
            }
        }

        if (allReachable) {
            cout << "No negative cycle reachable from source " << source << endl;
        } else {
            cout << "Some vertices are unreachable from source " << source << endl;
        }
    }
}

int main() {
    readGraph(); // Provide the correct filename
    showGraph();

    int source;
    cout << "Enter source vertex (0 to " << n - 1 << "): ";
    cin >> source;

    bellmanFord(source);

    return 0;
}

