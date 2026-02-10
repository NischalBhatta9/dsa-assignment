#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long comparisons = 0;
long long swaps = 0;

void cleanInput() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    swaps++;
}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void bubbleSort(int arr[], int n) {
    int i, j;
    comparisons = 0;
    swaps = 0;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    comparisons = 0;
    swaps = 0;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        if (min_idx != i)
            swap(&arr[min_idx], &arr[i]);
    }
}

void insertionSort(int arr[], int n) {
    int i, key, j;
    comparisons = 0;
    swaps = 0;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0) {
            comparisons++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                swaps++;
                j = j - 1;
            } else {
                break;
            }
        }
        arr[j + 1] = key;
    }
}

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++) L[i] = arr[l + i];
    for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) {
        comparisons++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    free(L);
    free(R);
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int n, choice, i;
    int *arr;

    srand(time(0)); 

    printf("Enter number of elements to generate: ");
    while(scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Enter a positive integer: ");
        cleanInput();
    }

    arr = (int*)malloc(n * sizeof(int));
    
    for(i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    printf("\nOriginal Array:\n");
    printArray(arr, n);

    printf("\nChoose a Sorting Algorithm:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Merge Sort\n");
    printf("Enter choice (1-4): ");
    
    while(scanf("%d", &choice) != 1 || choice < 1 || choice > 4) {
        printf("Invalid choice. Enter a number between 1 and 4: ");
        cleanInput();
    }

    switch(choice) {
        case 1:
            bubbleSort(arr, n);
            printf("\nAlgorithm: Bubble Sort\n");
            break;
        case 2:
            selectionSort(arr, n);
            printf("\nAlgorithm: Selection Sort\n");
            break;
        case 3:
            insertionSort(arr, n);
            printf("\nAlgorithm: Insertion Sort\n");
            break;
        case 4:
            comparisons = 0;
            swaps = 0;
            mergeSort(arr, 0, n - 1);
            printf("\nAlgorithm: Merge Sort\n");
            break;
    }

    printf("Sorted Array:\n");
    printArray(arr, n);

    printf("\n--- Performance Metrics ---\n");
    printf("Total Comparisons: %lld\n", comparisons);
    if (choice == 4) {
        printf("Total Swaps: N/A (Merge Sort uses array copy)\n");
    } else {
        printf("Total Swaps/Shifts: %lld\n", swaps);
    }

    free(arr);
    return 0;
}