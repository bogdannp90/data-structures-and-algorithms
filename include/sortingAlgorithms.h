#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

// Description: This file contains the prototypes of the functions that are used to implement the sorting algorithms.

const int MAX_SIZE = 100; // Define a constant for the array size

void merge(int left, int mid, int right, float arr[MAX_SIZE]);

void bubbleSort(int n, float arr[MAX_SIZE]);

void selectionSort(int n, float arr[MAX_SIZE]);

void countingSort(int n, float arr[MAX_SIZE]);

void mergeSort(int left, int right, float arr[MAX_SIZE]);

void quickSort(int left, int right, float arr[MAX_SIZE]);

void insertionSort(int n, float arr[MAX_SIZE]);

void shellSort(int n, float arr[MAX_SIZE]);

void radixSort(int n, int arr[MAX_SIZE]);

void sequentialSearch(int n, float arr[MAX_SIZE], float key);

void binarySearch(int left, int right, float arr[MAX_SIZE], float key);

void handleSortingAlgorithms();

#endif // SORTING_ALGORITHMS_H