# Program 8: Sorting Algorithms & Analysis

## Overview
This program provides a suite of four fundamental sorting algorithms. It demonstrates the differences in efficiency by counting the exact number of Comparisons (checking if A > B) and Swaps (moving data) performed by each algorithm on the same set of randomly generated data.

## Algorithms Implemented

### 1. Bubble Sort
A simple algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. The pass through the list is repeated until the list is sorted.
* **Behavior**: Large elements bubble to the end of the list.



### 2. Selection Sort
This algorithm divides the input list into two parts: a sorted sublist of items which is built up from left to right, and a sublist of the remaining unsorted items.
* **Behavior**: It repeatedly finds the minimum element from the unsorted sublist and moves it to the beginning.



### 3. Insertion Sort
Builds the final sorted array one item at a time. It assumes the first element is sorted, picks the next element, and shifts previous elements to find the correct position for the new key.
* **Behavior**: Similar to sorting playing cards in your hand.



### 4. Merge Sort
An efficient, stable, Divide and Conquer algorithm. It divides the input array into two halves, calls itself for the two halves, and then merges the two sorted halves.
* **Behavior**: Recursive splitting and merging.



## Function Reference

| Function | Description |
| :--- | :--- |
| **cleanInput** | Clears the input buffer to prevent infinite loops on invalid input. |
| **bubbleSort** | Sorts using pairwise swaps. Tracks comparisons and swaps. |
| **selectionSort** | Sorts by finding the minimum. Tracks comparisons and swaps. |
| **insertionSort** | Sorts by shifting elements. Tracks comparisons and shifts. |
| **mergeSort** | Recursive divide and conquer sorter. Tracks comparisons only. |

## Complexity Analysis

| Algorithm | Best Case | Average Case | Worst Case | Space Complexity |
| :--- | :--- | :--- | :--- | :--- |
| **Bubble Sort** | O(n) | O(n^2) | O(n^2) | O(1) |
| **Selection Sort** | O(n^2) | O(n^2) | O(n^2) | O(1) |
| **Insertion Sort** | O(n) | O(n^2) | O(n^2) | O(1) |
| **Merge Sort** | O(n log n) | O(n log n) | O(n log n) | O(n) |

## Test Case
**Input**: Generated random array of size 5: [45, 12, 89, 2, 12]

**Scenario: Selection Sort Selected**
1.  **Pass 1**: Find min (2). Swap 45 and 2. Array: [2, 12, 89, 45, 12]
2.  **Pass 2**: Find min starting from index 1 (12). No swap needed.
3.  **Pass 3**: Find min starting from index 2 (12). Swap 89 and 12. Array: [2, 12, 12, 45, 89]
4.  **Pass 4**: Find min starting from index 3 (45). No swap needed.

**Output:**
Original Array: 45 12 89 2 12
Algorithm: Selection Sort
Sorted Array: 2 12 12 45 89
--- Performance Metrics ---
Total Comparisons: 10
Total Swaps: 2