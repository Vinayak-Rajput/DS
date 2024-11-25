#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function prototype
void selectionSort(int array[], int size);

int main() {
    srand(time(NULL)); // Seed the random number generator

    int totalElements = 30000; // Total elements to generate
    int elements[totalElements];

    // Generate random elements in the range [0, 999]
    for (int i = 0; i < totalElements; i++) {
        elements[i] = rand() % 1000;
    }

    // Test sorting on increasing subset sizes
    for (int subsetSize = 5000; subsetSize < totalElements; subsetSize += 2000) {
        int subset[subsetSize];

        // Copy the first `subsetSize` elements to a new array
        for (int i = 0; i < subsetSize; i++) {
            subset[i] = elements[i];
        }

        // Measure the time taken to sort the subset
        clock_t start = clock(); // Start the timer
        selectionSort(subset, subsetSize); // Perform selection sort
        clock_t stop = clock(); // Stop the timer

        // Calculate and print the duration
        double duration = ((double)(stop - start) / CLOCKS_PER_SEC);
        printf("Time taken to sort %d elements is %f seconds\n", subsetSize, duration);
    }

    return 0;
}

// Function to perform selection sort
void selectionSort(int array[], int size) {
    int minIndex;

    // Loop through each element in the array
    for (int i = 0; i < size - 1; i++) {
        minIndex = i; // Assume the current index is the minimum

        // Find the index of the smallest element in the remaining array
        for (int j = i + 1; j < size; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j; // Update the index of the minimum element
            }
        }

        // Swap the minimum element with the current element
        if (minIndex != i) {
            int temp = array[minIndex];
            array[minIndex] = array[i];
            array[i] = temp;
        }
    }
}
