#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Macro to allocate memory and check for null pointer
#define MALLOC(p, s, t)           \
    p = (t)malloc(s);             \
    if (p == NULL) {              \
        printf("Insufficient Memory\n"); \
        exit(0);                  \
    }

// Definition of the tree node
struct tree {
    int info;
    struct tree *left;
    struct tree *right;
};
typedef struct tree *NODE;

// Function prototypes
NODE createTree(NODE, int);
NODE insertNode(NODE, int);
void preorderTraversal(NODE);
void inorderTraversal(NODE);
void postorderTraversal(NODE);
int searchKey(NODE, int);

// Global variable for number of nodes
int nodeCount;

int main() {
    int choice, done = 0, searchResult = 0, searchKeyVal;
    NODE root = NULL;

    while (!done) {
        printf("\nBinary Tree Operations\n");
        printf("1. Create Tree\n");
        printf("2. Preorder Traversal\n");
        printf("3. Inorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Search\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of nodes: ");
                scanf("%d", &nodeCount);
                root = createTree(root, nodeCount);
                break;

            case 2:
                printf("Preorder Traversal: ");
                preorderTraversal(root);
                printf("\n");
                break;

            case 3:
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;

            case 4:
                printf("Postorder Traversal: ");
                postorderTraversal(root);
                printf("\n");
                break;

            case 5:
                printf("Enter key to search: ");
                scanf("%d", &searchKeyVal);
                searchResult = searchKey(root, searchKeyVal);
                if (searchResult == 1)
                    printf("Key Found\n");
                else
                    printf("Key Not Found\n");
                break;

            case 6:
                done = 1;
                break;

            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}

// Function to create a binary search tree with multiple nodes
NODE createTree(NODE root, int nodeCount) {
    int value;
    if (root == NULL) {
        for (int i = 1; i <= nodeCount; i++) {
            printf("Enter data for node %d: ", i);
            scanf("%d", &value);
            root = insertNode(root, value);
        }
    } else {
        printf("Tree already has some data\n");
    }
    return root;
}

// Function to insert a node into the binary search tree
NODE insertNode(NODE node, int value) {
    if (node == NULL) {
        MALLOC(node, sizeof(struct tree), NODE);
        node->info = value;
        node->left = node->right = NULL;
    } else if (value == node->info) {
        printf("Duplicate Entry\n");
    } else if (value < node->info) {
        node->left = insertNode(node->left, value);
    } else {
        node->right = insertNode(node->right, value);
    }
    return node;
}

// Function to search for a key in the binary search tree
int searchKey(NODE node, int key) {
    if (node == NULL) {
        return 0;
    } else if (key == node->info) {
        return 1;
    } else if (key < node->info) {
        return searchKey(node->left, key);
    } else {
        return searchKey(node->right, key);
    }
}

// Function for preorder traversal
void preorderTraversal(NODE node) {
    if (node != NULL) {
        printf("%d ", node->info);
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }
}

// Function for inorder traversal
void inorderTraversal(NODE node) {
    if (node != NULL) {
        inorderTraversal(node->left);
        printf("%d ", node->info);
        inorderTraversal(node->right);
    }
}

// Function for postorder traversal
void postorderTraversal(NODE node) {
    if (node != NULL) {
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        printf("%d ", node->info);
    }
}
