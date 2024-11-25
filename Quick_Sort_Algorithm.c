#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function prototypes
void quicksort(int array[], int low, int high);
int partition(int array[], int low, int high);

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
        quicksort(subset, 0, subsetSize - 1); // Perform quicksort
        clock_t stop = clock(); // Stop the timer

        // Calculate and print the duration
        double duration = ((double)(stop - start) / CLOCKS_PER_SEC);
        printf("Time taken to sort %d elements is %f seconds\n", subsetSize, duration);
    }

    return 0;
}

// Partition function for quicksort
int partition(int array[], int low, int high) {
    int pivot = array[low]; // Choose the first element as the pivot
    int left = low;
    int right = high + 1;
    int temp;

    // Partition the array around the pivot
    while (left <= right) {
        // Move the left pointer until an element greater than the pivot is found
        do {
            left++;
        } while (pivot >= array[left]);

        // Move the right pointer until an element less than or equal to the pivot is found
        do {
            right--;
        } while (pivot < array[right]);

        // Swap elements if the pointers have not crossed
        if (left < right) {
            temp = array[right];
            array[right] = array[left];
            array[left] = temp;
        }
    }

    // Swap the pivot with the right pointer's position
    temp = array[low];
    array[low] = array[right];
    array[right] = temp;

    return right; // Return the partition index
}

// Quicksort function
void quicksort(int array[], int low, int high) {
    if (low >= high) {
        return; // Base case: if the range is invalid or single element
    }

    // Partition the array and sort the two halves recursively
    int partitionIndex = partition(array, low, high);
    quicksort(array, low, partitionIndex - 1); // Sort the left half
    quicksort(array, partitionIndex + 1, high); // Sort the right half
}
