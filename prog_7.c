//Implementation of Dijkstra's algorithm
#include <stdio.h>
#include <limits.h>

#define TOTAL_VERTICES 6 // Total number of vertices in graph

// Function to locate vertex with minimum distance that's unvisited
// Examine all vertices to find the one with smallest tentative distance
int findClosestVertex(int distances[], int processed[]) {
    int minimumValue = INT_MAX;
    int selectedIndex = -1;
    for (int vertex = 0; vertex < TOTAL_VERTICES; vertex++) {
        if (!processed[vertex] && distances[vertex] <= minimumValue) {
            minimumValue = distances[vertex];
            selectedIndex = vertex;
        }
    }
    return selectedIndex;
}

// Function to compute shortest paths from source vertex
// Calculate minimum distances from starting point to all other vertices
void computeShortestPaths(int graphData[TOTAL_VERTICES][TOTAL_VERTICES], int source) {
    int shortestDistances[TOTAL_VERTICES];     // Distances from source to each vertex
    int finalizedVertices[TOTAL_VERTICES] = {0}; // Track processed vertices

    // Initialize all distances to infinity
    for (int vertex = 0; vertex < TOTAL_VERTICES; vertex++) {
        shortestDistances[vertex] = INT_MAX;
    }
    shortestDistances[source] = 0; // Distance to source itself is zero

    // Process all vertices
    for (int iteration = 0; iteration < TOTAL_VERTICES - 1; iteration++) {
        int currentVertex = findClosestVertex(shortestDistances, finalizedVertices);
        finalizedVertices[currentVertex] = 1; // Mark vertex as processed

        // Update distances to adjacent vertices
        for (int neighbor = 0; neighbor < TOTAL_VERTICES; neighbor++) {
            if (!finalizedVertices[neighbor] && graphData[currentVertex][neighbor] && 
                shortestDistances[currentVertex] != INT_MAX &&
                shortestDistances[currentVertex] + graphData[currentVertex][neighbor] < shortestDistances[neighbor]) {
                shortestDistances[neighbor] = shortestDistances[currentVertex] + graphData[currentVertex][neighbor];
            }
        }
    }
    
    // Output shortest distances
    printf("\nVertex\tMinimum Distance from Source %d\n", source);
    for (int vertex = 0; vertex < TOTAL_VERTICES; vertex++) {
        printf("%d\t%d\n", vertex, shortestDistances[vertex]);
    }
}

int main() {
    // Weighted graph represented as adjacency matrix
    // 0 indicates no direct connection between vertices
    int graphData[TOTAL_VERTICES][TOTAL_VERTICES] = {
        {0, 10, 0, 30, 100, 0},
        {10, 0, 50, 0, 0, 0},
        {0, 50, 0, 20, 10, 0},
        {30, 0, 20, 0, 60, 0},
        {100, 0, 10, 60, 0, 0},
        {0, 0, 0, 0, 0, 0} // isolated vertex for testing
    };
    
    int startingVertex = 0; // Starting point for algorithm
    
    printf("Computing shortest paths originating from vertex %d...\n", startingVertex);
    computeShortestPaths(graphData, startingVertex);
    
    return 0;
}