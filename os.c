
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

// Function prototypes
void* quick_sort(void* data);
void* merge_sort(void* data);
void print_array(int arr[], int size);
void merge(int arr[], int l, int m, int r);
int partition(int arr[], int low, int high);

// Struct to hold data for sorting
struct SortData {
    int* arr;
    int start;
    int end;
};

// Quick sort function
void* quick_sort(void* data) {
    struct SortData* sd = (struct SortData*)data;
    int* arr = sd->arr;
    int start = sd->start;
    int end = sd->end;

    if (start < end) {
        int pi = partition(arr, start, end);

        struct SortData sd1 = {arr, start, pi - 1};
        struct SortData sd2 = {arr, pi + 1, end};

        quick_sort(&sd1);
        quick_sort(&sd2);
    }

    pthread_exit(NULL);
}

// Merge sort function
void* merge_sort(void* data) {
    struct SortData* sd = (struct SortData*)data;
    int* arr = sd->arr;
    int start = sd->start;
    int end = sd->end;

    if (start < end) {
        int mid = start + (end - start) / 2;

        struct SortData sd1 = {arr, start, mid};
        struct SortData sd2 = {arr, mid + 1, end};

        merge_sort(&sd1);
        merge_sort(&sd2);

        merge(arr, start, mid, end);
    }

    pthread_exit(NULL);
}

// Utility function to print an array
void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Utility function to merge two subarrays of arr[]
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temporary arrays */
    int L[n1], R[n2];

    /* Copy data to temporary arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /* Merge the temporary arrays back into arr[l..r]*/
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Utility function for partitioning array for QuickSort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than the pivot
        if (arr[j] < pivot) {
            i++; // Increment index of smaller element
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // Swap arr[i + 1] and arr[high] (or pivot)
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    clock_t start, end;
    double time_taken;

    // Non-threaded sorting
    start = clock();
    struct SortData sd1 = {arr, 0, n - 1};
    quick_sort(&sd1);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for quick sort without multithreading: %f seconds\n", time_taken);

    // Threaded sorting
    start = clock();
    struct SortData sd2 = {arr, 0, n - 1};
    pthread_t tid;
    pthread_create(&tid, NULL, quick_sort, (void*)&sd2);
    pthread_join(tid, NULL);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for quick sort with multithreading: %f seconds\n", time_taken);

    // Print sorted array
    printf("Sorted array: ");
    print_array(arr, n);

    return 0;
}
