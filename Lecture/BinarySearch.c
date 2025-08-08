#include <stdio.h>

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int binarySearch(int arr[], int size, int key, int *comparisonCount) {
    int low = 0;
    int high = size - 1;
    *comparisonCount = 0;

    while (low <= high) {
        (*comparisonCount)++;

        int mid = low + (high - low) / 2;

        printf(" -> round %d: between arr[%d] = %d\n", *comparisonCount, mid, arr[mid]);

        if (arr[mid] == key) {
            return mid;
        }


        if (arr[mid] > key) {
            high = mid - 1;
        }

        else {
            low = mid + 1;
        }
    }


    return -1;
}


void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main() {
    int arr[] = {1, 15, 5, 7, 10, 9, 10, 3, 45, 155};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    bubbleSort(arr, n);

    printf("Original array: ");
    printArray(arr, n);

    int comparisons; 

    int key1 = 5;
    printf("Searching for %d...\n", key1);
    int result1 = binarySearch(arr, n, key1, &comparisons);

    if (result1 != -1) {
        printf("%d %d\n", key1, result1);
    } else {
        printf(" %d\n", key1);
    }
    printf(" %d\n", comparisons);


    int key2 = 90;
    printf("Searching for %d...\n", key2);
    int result2 = binarySearch(arr, n, key2, &comparisons);
    
    if (result2 != -1) {
        printf("%d %d\n", key2, result2);
    } else {
        printf("%d\n", key2);
    }
    printf("%d\n", comparisons);


    return 0;
}