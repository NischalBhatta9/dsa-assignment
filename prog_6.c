#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyMin(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        heapifyMin(arr, n, smallest);
    }
}

void buildMinHeap(int arr[], int n) {
    int startIdx = (n / 2) - 1;
    int i;
    
    for (i = startIdx; i >= 0; i--) {
        heapifyMin(arr, n, i);
    }
}

void heapifyMax(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapifyMax(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n) {
    int startIdx = (n / 2) - 1;
    int i;

    for (i = startIdx; i >= 0; i--) {
        heapifyMax(arr, n, i);
    }
}

void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

void cleanInput() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    int n, i;
    int *arr1, *arr2;

    printf("Enter the size of the array: ");
    while(scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Enter a positive integer: ");
        cleanInput();
    }

    arr1 = (int*)malloc(n * sizeof(int));
    arr2 = (int*)malloc(n * sizeof(int));

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        while(scanf("%d", &arr1[i]) != 1) {
            printf("Invalid input. Enter a number: ");
            cleanInput();
        }
        arr2[i] = arr1[i];
    }

    printf("\nOriginal Array: ");
    printArray(arr1, n);

    buildMinHeap(arr1, n);
    printf("Min Heap: ");
    printArray(arr1, n);

    buildMaxHeap(arr2, n);
    printf("Max Heap: ");
    printArray(arr2, n);

    free(arr1);
    free(arr2);

    return 0;
}