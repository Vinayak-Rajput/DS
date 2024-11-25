#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function prototypes
void mergeSort(int array[], int low, int high);
void merge(int array[], int low, int mid, int high);

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
        mergeSort(subset, 0, subsetSize - 1); // Perform merge sort
        clock_t stop = clock(); // Stop the timer

        // Calculate and print the duration
        double duration = ((double)(stop - start) / CLOCKS_PER_SEC);
        printf("Time taken to sort %d elements is %f seconds\n", subsetSize, duration);
    }

    return 0;
}

// Function to perform merge sort
void mergeSort(int array[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2; // Find the middle point

        // Recursively sort the two halves
        mergeSort(array, low, mid);
        mergeSort(array, mid + 1, high);

        // Merge the sorted halves
        merge(array, low, mid, high);
    }
}

// Function to merge two sorted subarrays
void merge(int array[], int low, int mid, int high) {
    int tempArray[30000]; // Temporary array for merging
    int leftIndex = low;   // Start of the left subarray
    int rightIndex = mid + 1; // Start of the right subarray
    int mergedIndex = low; // Index for merged array

    // Merge elements from both subarrays into the temporary array
    while (leftIndex <= mid && rightIndex <= high) {
        if (array[leftIndex] < array[rightIndex]) {
            tempArray[mergedIndex++] = array[leftIndex++];
        } else {
            tempArray[mergedIndex++] = array[rightIndex++];
        }
    }

    // Copy remaining elements from the left subarray, if any
    while (leftIndex <= mid) {
        tempArray[mergedIndex++] = array[leftIndex++];
    }

    // Copy remaining elements from the right subarray, if any
    while (rightIndex <= high) {
        tempArray[mergedIndex++] = array[rightIndex++];
    }

    // Copy the sorted elements back to the original array
    for (int i = low; i <= high; i++) {
        array[i] = tempArray[i];
    }
}
