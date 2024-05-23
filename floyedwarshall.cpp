#include <iostream>
#include <fstream>

#define MAX_VERTICES 10 // Maximum number of vertices
#define INF 999999     // Infinity (a large value)

int graph[MAX_VERTICES][MAX_VERTICES];
int n;

void readGraph() {
    std::fstream infile;
    infile.open("floyed_warshal.txt", std::ios::in);
    if (!infile) {
        std::cout << "Error opening the file." << std::endl;
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
    std::cout << "Graph Adjacency Matrix:" << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%3d", graph[i][j]);
        }
        printf("\n");
    }
}

void floydWarshall() {
    int dist[MAX_VERTICES][MAX_VERTICES];

    // Initialize the distance matrix with the graph's adjacency matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dist[i][j] = graph[i][j];
        }
    }

    // Applying Floyd-Warshall algorithm
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest distances
    std::cout << "\nShortest distances between every pair of vertices:" << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] == INF) {
                std::cout << "INF\t";
            } else {
                std::cout << dist[i][j] << "\t";
            }
        }
        std::cout << std::endl;
    }
}

int main() {
    readGraph();
    showGraph();
    floydWarshall();
    return 0;
}

