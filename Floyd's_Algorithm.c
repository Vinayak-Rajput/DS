#include<stdio.h>

// Function to return the minimum of two integers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to compute the shortest paths using Floyd-Warshall algorithm
void floydWarshall(int distanceMatrix[][10], int size) {
    // Iterate through all intermediate vertices
    for (int k = 1; k <= size; k++) {
        // Iterate through all source vertices
        for (int i = 1; i <= size; i++) {
            // Iterate through all destination vertices
            for (int j = 1; j <= size; j++) {
                // Update the shortest path distance
                distanceMatrix[i][j] = min(distanceMatrix[i][j], 
                                           distanceMatrix[i][k] + distanceMatrix[k][j]);
            }
        }
    }
}

int main() {
    int distanceMatrix[10][10]; // Matrix to store graph weights
    int numVertices; // Number of vertices in the graph

    // Input the number of vertices
    printf("Enter the number of vertices (n): ");
    scanf("%d", &numVertices);

    // Input the adjacency matrix
    printf("Enter the graph's adjacency matrix (use a large number like 999 for no edge):\n");
    for (int i = 1; i <= numVertices; i++) {
        for (int j = 1; j <= numVertices; j++) {
            scanf("%d", &distanceMatrix[i][j]);
        }
    }

    // Perform Floyd-Warshall algorithm to compute shortest paths
    floydWarshall(distanceMatrix, numVertices);

    // Output the shortest path matrix
    printf("\nShortest Path Matrix:\n");
    for (int i = 1; i <= numVertices; i++) {
        for (int j = 1; j <= numVertices; j++) {
            printf("%d ", distanceMatrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
