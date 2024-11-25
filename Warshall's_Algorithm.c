#include<stdio.h>

// Function to compute the transitive closure using Warshall's algorithm
void warshall(int pathMatrix[][10], int size) {
    // Iterate through all intermediate nodes
    for (int k = 1; k <= size; k++) {
        // Iterate through all source nodes
        for (int i = 1; i <= size; i++) {
            // Iterate through all destination nodes
            for (int j = 1; j <= size; j++) {
                // Update pathMatrix[i][j] to 1 if there is a path from i to j through k
                pathMatrix[i][j] = pathMatrix[i][j] || (pathMatrix[i][k] && pathMatrix[k][j]);
            }
        }
    }
}

int main() {
    int adjacencyMatrix[10][10]; // Matrix to store the graph
    int numVertices; // Number of vertices in the graph

    // Input the number of vertices
    printf("Enter the number of vertices (n): ");
    scanf("%d", &numVertices);

    // Input the adjacency matrix
    printf("Enter the adjacency matrix (use 1 for edge and 0 for no edge):\n");
    for (int i = 1; i <= numVertices; i++) {
        for (int j = 1; j <= numVertices; j++) {
            scanf("%d", &adjacencyMatrix[i][j]);
        }
    }

    // Perform Warshall's algorithm to compute the transitive closure
    warshall(adjacencyMatrix, numVertices);

    // Output the resultant path matrix
    printf("\nResultant Path Matrix:\n");
    for (int i = 1; i <= numVertices; i++) {
        for (int j = 1; j <= numVertices; j++) {
            printf("%d ", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
