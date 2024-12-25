#include "sortingAlgorithms.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Merge function used in merge sort
void merge(int left, int mid, int right, float arr[MAX_SIZE]) {
    int i = left;
    int j = mid + 1;
    int k = 0;
    float temp[MAX_SIZE];

    // Merge the two halves into temp array
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    // Copy the merged elements back into the original array
    for (int r = 0; r < k; r++) arr[left + r] = temp[r];
}

// Helper function to count the number of digits in an integer
int countDigits(int x) {
    int numDigits = 0;

    if (x == 0)
        return 1;
    else
        while (x > 0) {
            numDigits++;
            x = x / 10;
        }
    return numDigits;
}

// Bubble sort algorithm
void bubbleSort(int n, float arr[MAX_SIZE]) {
    bool sorted;
    do {
        sorted = true;
        for (int i = 0; i <= n - 2; i++) {
            if (arr[i] > arr[i + 1]) {
                sorted = false;
                float temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    } while (!sorted);
}

// Selection sort algorithm
void selectionSort(int n, float arr[MAX_SIZE]) {
    for (int j = 0; j <= n - 2; j++) {
        float min = arr[j];
        int pos = j;
        for (int k = j + 1; k <= n - 1; k++) {
            if (arr[k] < min) {
                min = arr[k];
                pos = k;
            }
        }
        if (pos != j) swap(arr[pos], arr[j]);
    }
}

// Counting sort algorithm
void countingSort(int n, float arr[MAX_SIZE]) {
    int count[MAX_SIZE] = {0};
    for (int i = 0; i <= n - 2; i++) {
        for (int j = i + 1; j <= n - 1; j++) {
            if (arr[i] <= arr[j]) count[j]++;
            else count[i]++;
        }
    }
    float temp[n];
    copy_n(arr, n, temp);
    for (int j = 0; j <= n - 1; j++) arr[count[j]] = temp[j];
}

// Merge sort algorithm
void mergeSort(int left, int right, float arr[MAX_SIZE]) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(left, mid, arr);
        mergeSort(mid + 1, right, arr);
        merge(left, mid, right, arr);
    }
}

// Quick sort algorithm
void quickSort(int left, int right, float arr[MAX_SIZE]) {
    if (left < right) {
        float pivot = arr[left];
        int count = 0;
        for (int i = left + 1; i <= right; i++) if (arr[i] <= pivot) count++;
        swap(arr[left], arr[left + count]);
        int i = left;
        int j = right;
        while (i < j) {
            while (arr[i] < pivot) i++;
            while (arr[j] >= pivot) j--;
            if (i < j) {
                swap(arr[i], arr[j]);
                if (i < right) i++;
                if (j > left) j--;
            }
        }
        quickSort(left, left + count - 1, arr);
        quickSort(left + count + 1, right, arr);
    }
}

// Insertion sort algorithm
void insertionSort(int n, float arr[MAX_SIZE]) {
    for (int i = 0; i < n; i++) {
        float temp = arr[i];
        int j = i - 1;
        while (j >= 0 && temp < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

// Shell sort algorithm
void shellSort(int n, float arr[MAX_SIZE]) {
    int gap = n / 2;
    while (gap >= 1) {
        int i = 0;
        while ((i + gap) <= (n - 1)) {
            int j = i;
            float temp = arr[i + gap];
            while (arr[j] > temp && j >= 0) {
                arr[j + gap] = arr[j];
                j = j - gap;
            }
            arr[j + gap] = temp;
            i++;
        }
        gap = gap / 2;
    }
}

// Radix sort algorithm
void radixSort(int n, int arr[MAX_SIZE]) {
    int maxVal = 0;

    // Find the maximum value in the array
    for (int i = 0; i < n; i++)
        if (maxVal < arr[i]) maxVal = arr[i];

    int maxDigits = countDigits(maxVal);

    // Perform counting sort for every digit
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        int output[MAX_SIZE];
        int count[10] = {0};

        // Count occurrences of digits
        for (int i = 0; i < n; i++) {
            int digit = (arr[i] / exp) % 10;
            count[digit]++;
        }

        // Update count array
        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];

        // Build the output array
        for (int i = n - 1; i >= 0; i--) {
            int digit = (arr[i] / exp) % 10;
            output[count[digit] - 1] = arr[i];
            count[digit]--;
        }

        // Copy the output array to arr
        for (int i = 0; i < n; i++)
            arr[i] = output[i];
    }
}

// Sequential search algorithm
void sequentialSearch(int n, float arr[MAX_SIZE], float key) {
    int occurrences = 0;
    for (int i = 0; i < n; i++) if (arr[i] == key) occurrences++;
    if (occurrences == 0) cout << "Element not found in the array!";
    if (occurrences == 1) cout << "The element " << key << " appears once in the array." << endl << endl;
    if (occurrences != 1) cout << "The element " << key << " appears " << occurrences << " times in the array." << endl << endl;
}

// Binary search algorithm
void binarySearch(int left, int right, float arr[MAX_SIZE], float key) {
    if (key < arr[left] || key > arr[right]) {
        cout << "Element not found in the array!\n";
        return;
    }
    if (left < right) {
        int mid = (left + right) / 2;
        if (arr[mid] == key) {
            cout << "The searched element is in the array at position " << mid << "\n";
            return;
        }
        if (key < arr[mid] && left <= mid - 1) binarySearch(left, mid - 1, arr, key);
        if (key > arr[mid]) binarySearch(mid + 1, right, arr, key);
    } else {
        if (arr[left] == key)
            cout << "The searched element is in the array at position " << left << endl << endl;
        else
            cout << "Element not found in the array!" << endl << endl;
    }
}

// Enum for sorting options
enum SortingOptions {
    EXIT = 0,
    BUBBLE_SORT,
    COUNTING_SORT,
    SELECTION_SORT,
    QUICK_SORT,
    MERGE_SORT,
    INSERTION_SORT,
    SHELL_SORT,
    RADIX_SORT,
    SEQUENTIAL_SEARCH,
    BINARY_SEARCH
};

// Function to print the array
void printArray(const vector<float>& arr) {
    for (float num : arr) {
        cout << num << " ";
    }
    cout << endl << endl;
}

// Function to handle sorting algorithms menu
void handleSortingAlgorithms() {
    int op;
    int n;
    vector<float> arr, sortedArr;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    arr.resize(n);
    cout << endl << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << endl;

    do {
        cout << "Sorting Algorithms" << endl;
        cout << "1. Bubble Sort" << endl;
        cout << "2. Counting Sort" << endl;
        cout << "3. Selection Sort" << endl;
        cout << "4. Quicksort" << endl;
        cout << "5. Merge Sort" << endl;
        cout << "6. Insertion Sort" << endl;
        cout << "7. Shell Sort" << endl;
        cout << "8. Radix Sort" << endl;
        cout << "9. Sequential Search in an array" << endl;
        cout << "10. Binary Search in an array" << endl;
        cout << "0. Exit sorting algorithms!" << endl;
        cout << "Option for sorting algorithms: ";
        cin >> op;
        cout << endl;

        sortedArr = arr;

        switch (op) {
            case BUBBLE_SORT:
                bubbleSort(n, sortedArr.data());
                cout << "The array sorted with Bubble Sort is: ";
                printArray(sortedArr);
                break;

            case COUNTING_SORT:
                countingSort(n, sortedArr.data());
                cout << "The array sorted with Counting Sort is: ";
                printArray(sortedArr);
                break;

            case SELECTION_SORT:
                selectionSort(n, sortedArr.data());
                cout << "The array sorted with Selection Sort is: ";
                printArray(sortedArr);
                break;

            case QUICK_SORT:
                quickSort(0, n - 1, sortedArr.data());
                cout << "The array sorted with Quick Sort is: ";
                printArray(sortedArr);
                break;

            case MERGE_SORT:
                mergeSort(0, n - 1, sortedArr.data());
                cout << "The array sorted with Merge Sort is: ";
                printArray(sortedArr);
                break;

            case INSERTION_SORT:
                insertionSort(n, sortedArr.data());
                cout << "The array sorted with Insertion Sort is: ";
                printArray(sortedArr);
                break;

            case SHELL_SORT:
                shellSort(n, sortedArr.data());
                cout << "The array sorted with Shell Sort is: ";
                printArray(sortedArr);
                break;

            case RADIX_SORT: {
                vector<int> sortedArrInt(n);
                for (int i = 0; i < n; i++) {
                    sortedArrInt[i] = static_cast<int>(sortedArr[i]);
                }
                radixSort(n, sortedArrInt.data());
                cout << "The array sorted with Radix Sort is: ";
                for (int num : sortedArrInt) {
                    cout << num << " ";
                }
                cout << endl << endl;
                break;
            }

            case SEQUENTIAL_SEARCH: {
                cout << "Enter the element you are looking for: ";
                float key;
                cin >> key;
                sequentialSearch(n, sortedArr.data(), key);
                break;
            }

            case BINARY_SEARCH:
                quickSort(0, n - 1, sortedArr.data());
                cout << "The sorted array is: ";
                printArray(sortedArr);
                cout << "Enter the element you are looking for: ";
                float key;
                cin >> key;
                binarySearch(0, n - 1, sortedArr.data(), key);
                break;

            case EXIT:
                cout << "Exiting sorting algorithms menu." << endl;
                break;

            default:
                cout << "Invalid option!" << endl;
                break;
        }
    } while (op != EXIT);
}