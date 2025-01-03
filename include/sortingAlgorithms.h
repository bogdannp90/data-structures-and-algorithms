#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

// Description: This file contains the prototypes of the functions that are used to implement the sorting algorithms.

const int MAX_SIZE = 100; // Define a constant for the array size

/**
 * @brief Merges two subarrays of arr.
 * @param left Left index of the subarray.
 * @param mid Middle index of the subarray.
 * @param right Right index of the subarray.
 * @param arr Array to be sorted.
 */
void merge(int left, int mid, int right, float arr[MAX_SIZE]);

/**
 * @brief Sorts an array using the bubble sort algorithm.
 * @param n Number of elements in the array.
 * @param arr Array to be sorted.
 */
void bubbleSort(int n, float arr[MAX_SIZE]);

/**
 * @brief Sorts an array using the selection sort algorithm.
 * @param n Number of elements in the array.
 * @param arr Array to be sorted.
 */
void selectionSort(int n, float arr[MAX_SIZE]);

/**
 * @brief Sorts an array using the counting sort algorithm.
 * @param n Number of elements in the array.
 * @param arr Array to be sorted.
 */
void countingSort(int n, float arr[MAX_SIZE]);

/**
 * @brief Sorts an array using the merge sort algorithm.
 * @param left Left index of the subarray.
 * @param right Right index of the subarray.
 * @param arr Array to be sorted.
 */
void mergeSort(int left, int right, float arr[MAX_SIZE]);

/**
 * @brief Sorts an array using the quick sort algorithm.
 * @param left Left index of the subarray.
 * @param right Right index of the subarray.
 * @param arr Array to be sorted.
 */
void quickSort(int left, int right, float arr[MAX_SIZE]);

/**
 * @brief Sorts an array using the insertion sort algorithm.
 * @param n Number of elements in the array.
 * @param arr Array to be sorted.
 */
void insertionSort(int n, float arr[MAX_SIZE]);

/**
 * @brief Sorts an array using the shell sort algorithm.
 * @param n Number of elements in the array.
 * @param arr Array to be sorted.
 */
void shellSort(int n, float arr[MAX_SIZE]);

/**
 * @brief Sorts an array using the radix sort algorithm.
 * @param n Number of elements in the array.
 * @param arr Array to be sorted.
 */
void radixSort(int n, int arr[MAX_SIZE]);

/**
 * @brief Performs a sequential search on an array.
 * @param n Number of elements in the array.
 * @param arr Array to be searched.
 * @param key Key to be searched for.
 */
void sequentialSearch(int n, const float arr[MAX_SIZE], float key);

/**
 * @brief Performs a binary search on a sorted array.
 * @param left Left index of the subarray.
 * @param right Right index of the subarray.
 * @param arr Array to be searched.
 * @param key Key to be searched for.
 */
void binarySearch(int left, int right, float arr[MAX_SIZE], float key);

/**
 * @brief Handles sorting algorithms.
 */
void handleSortingAlgorithms();

#endif // SORTING_ALGORITHMS_H