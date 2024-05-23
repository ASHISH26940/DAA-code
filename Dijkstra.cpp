#include<iostream>
#include<climits>
#include<fstream>
#include<bits/stdc++.h>
#include<list>
using namespace std;

int graph[10][10];
int n;

void readGraph() {
    fstream infile;
    infile.open("dijkstra.txt", ios::in);
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

int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;
    for (int i = 0; i < n; ++i) {
        if (sptSet[i] == false && dist[i] < min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}


void printShortestPath(int src, int dest, int pred[]) {
    list<char> path;
    
    if (pred[dest] == -1) {
        cout << "No path exists from source to destination." << endl;
        return;
    }

    // To print the path, we use the predecessor array
    int current = dest;

    // Traverse from destination to source to build the path
    while (current != src) {
        path.push_front(char(current + 'A')); // Push current node to the front of the list
        current = pred[current];
    }
    
    // Finally, push the source node to the path list
    path.push_front(char(src + 'A'));
	bool firstElement = true;
    // Output the path
    for (list<char>::iterator it = path.begin(); it != path.end(); ++it) {
    	if (!firstElement) {
            cout << " --> ";
    }
    cout << *it;
        firstElement = false;
	}
    cout << endl;
}
void dijkstra(int src) {
    int dist[n];
    bool sptSet[n];
    int pred[n]; // Predecessor array to store the shortest path tree

    for (int i = 0; i < n; ++i) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
        pred[i] = -1; // Initialize predecessor array
    }

    dist[src] = 0;

    for (int count = 0; count < n - 1; ++count) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
        for (int v = 0; v < n; ++v) {
            if (graph[u][v] && sptSet[v] == false && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                pred[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    cout << "Shortest paths from source vertex " << char(src + 'A') << " to other vertices:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "To vertex " << char(i + 'A') << ", Distance = " << dist[i] << ", Path: ";
        printShortestPath(src, i, pred);
    }
}

int main() {
    readGraph();
    showGraph();
    int source = 0; // Set the source vertex (e.g., 'A' = 0, 'B' = 1, ...)
    dijkstra(source);
    return 0;
}

