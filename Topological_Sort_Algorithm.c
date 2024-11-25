#include<stdio.h>

// Function to perform Topological Sorting
void toposort(int adjacencyMatrix[20][20], int numberOfNodes) {
    int topologicalOrder[10], inDegree[10], stack[10], visited[10];
    int stackTop = 0, currentNode, orderIndex = 1;

    // Initialize arrays
    for (int i = 1; i <= numberOfNodes; i++) {
        topologicalOrder[i] = 0;  // Topological order array
        inDegree[i] = 0;          // In-degree array
        visited[i] = 0;           // Visited nodes array
    }

    // Calculate in-degree for each node
    for (int i = 1; i <= numberOfNodes; i++) {
        for (int j = 1; j <= numberOfNodes; j++) {
            if (adjacencyMatrix[i][j] == 1) {
                inDegree[j]++;
            }
        }
    }

    // Print the in-degree array for debugging
    printf("In-degree Array: ");
    for (int i = 1; i <= numberOfNodes; i++) {
        printf("%d ", inDegree[i]);
    }

    // Find nodes with in-degree 0 and push them onto the stack
    for (int i = 1; i <= numberOfNodes; i++) {
        if (inDegree[i] == 0) {
            stack[++stackTop] = i;
            visited[i] = 1;  // Mark node as visited
        }
    }

    // Perform the topological sorting
    while (stackTop > 0) {
        // Pop a node from the stack
        currentNode = stack[stackTop--];
        topologicalOrder[orderIndex++] = currentNode;

        // Reduce in-degree for neighboring nodes and add them to stack if in-degree becomes 0
        for (int j = 1; j <= numberOfNodes; j++) {
            if (adjacencyMatrix[currentNode][j] == 1 && visited[j] == 0) {
                inDegree[j]--;
                if (inDegree[j] == 0) {
                    stack[++stackTop] = j;
                    visited[j] = 1;  // Mark node as visited
                }
            }
        }
    }

    // Print the topological order
    printf("\nTopological Ordering is: ");
    for (int i = 1; i <= numberOfNodes; i++) {
        printf("%d ", topologicalOrder[i]);
    }
}

int main() {
    int adjacencyMatrix[20][20], numberOfNodes;

    // Input number of nodes
    printf("Enter the number of nodes: ");
    scanf("%d", &numberOfNodes);

    // Input adjacency matrix
    printf("Enter adjacency matrix:\n");
    for (int i = 1; i <= numberOfNodes; i++) {
        for (int j = 1; j <= numberOfNodes; j++) {
            scanf("%d", &adjacencyMatrix[i][j]);
        }
    }

    // Call the Topological Sort function
    toposort(adjacencyMatrix, numberOfNodes);

    return 0;
}
