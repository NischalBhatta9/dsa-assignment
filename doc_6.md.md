# Program 6: Heap Construction (Min & Max)

## Overview
This program takes an unsorted array of integers and converts it into two different Binary Heap structures: a **Min Heap** and a **Max Heap**. Heaps are essential data structures used in efficient sorting algorithms (Heapsort) and priority queues.

## Data Structure: Binary Heap
A Binary Heap is a complete binary tree which satisfies the heap property. It is typically represented as an array.

* **Min Heap Property**: The key at the root must be minimum among all keys present in the Binary Heap. The same property must be recursively true for all nodes in the Binary Tree.
* **Max Heap Property**: The key at the root must be maximum among all keys present in the Binary Heap. The same property must be recursively true for all nodes in the Binary Tree.



## Algorithm Description

### Building the Heap (Heapify)
The conversion process uses an algorithm called **Heapify**. Instead of inserting elements one by one (which is O(N log N)), we treat the array as a complete binary tree and fix the heap property from the bottom up.

1.  **Identify Non-Leaf Nodes**: The leaves of the tree naturally satisfy the heap property because they have no children. We only need to process nodes that have children.
2.  **Reverse Traversal**: We start from the last non-leaf node (index `n/2 - 1`) and move upwards to the root (index `0`).
3.  **Sift Down**: For each node, we compare it with its children.
    * For **Min Heap**: If a child is smaller than the parent, they swap.
    * For **Max Heap**: If a child is larger than the parent, they swap.
    * If a swap occurs, we recursively "sift down" the element to ensure the subtree remains a valid heap.



## Functions

| Function | Description |
| :--- | :--- |
| **heapifyMin** | Ensures the Min Heap property for a subtree rooted at index `i`. |
| **heapifyMax** | Ensures the Max Heap property for a subtree rooted at index `i`. |
| **buildMinHeap** | Iterates through all non-leaf nodes and applies `heapifyMin`. |
| **buildMaxHeap** | Iterates through all non-leaf nodes and applies `heapifyMax`. |
| **cleanInput** | Clears the buffer to handle invalid user inputs safely. |

## Test Case
**Input Array**: `[3, 9, 2, 1, 4, 5]`

**Process**:
* **Min Heap**: The smallest elements bubble to the top. `1` becomes the root.
* **Max Heap**: The largest elements bubble to the top. `9` becomes the root.

**Execution Results**:
* **Min Heap**: `1 3 2 9 4 5` (1 is smaller than 3 and 2).
* **Max Heap**: `9 4 5 1 3 2` (9 is larger than 4 and 5).

## Complexity Analysis
* **Time Complexity**: O(N)
    While `heapify` takes O(log N), building the heap from scratch is mathematically proven to be linear time, O(N), because most nodes are near the bottom and have little "sifting" to do.
* **Space Complexity**: O(1)
    The transformation happens in-place within the array. We used an auxiliary array in `main` only to preserve the data for the second demonstration.