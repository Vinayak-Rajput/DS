#include <stdio.h>

// Global variable to count the number of moves
int moveCount = 0;

/*
 * Function to solve Tower of Hanoi problem
 * n      : number of disks
 * source : source peg (represented by a character)
 * aux    : auxiliary peg (represented by a character)
 * destination : destination peg (represented by a character)
 */
void towerOfHanoi(int n, char source, char aux, char destination) {
    if (n > 0) {
        // Move (n-1) disks from source to auxiliary peg
        towerOfHanoi(n - 1, source, destination, aux);

        // Move the nth disk from source to destination peg
        printf("Disk %d moved from %c --> %c\n", n, source, destination);
        moveCount++;  // Increment the move counter

        // Move (n-1) disks from auxiliary peg to destination peg
        towerOfHanoi(n - 1, aux, source, destination);
    }
}

int main() {
    int numDisks;

    // Get the number of disks from the user
    printf("Enter the number of disks: ");
    scanf("%d", &numDisks);

    // Call the Tower of Hanoi function to solve the problem
    towerOfHanoi(numDisks, 'A', 'B', 'C');

    // Output the total number of moves required
    printf("Number of moves taken to move disks from source to destination: %d\n", moveCount);

    return 0;
}
