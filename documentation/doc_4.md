## Program 4: Doubly Linked List Operations

## Overview

A Doubly Linked List (DLL) is a linked list where each node contains an extra pointer to the previous node. This allows for bidirectional traversal and makes deletion easier because nodes know their predecessor.

## Data Structure: DLL Node

The node structure contains three components: the data and two pointers (`next` and `prev`).

### C struct

```c
struct node {
        int data;          // The value
        struct node* next; // Pointer to the next node
        struct node* prev; // Pointer to the previous node
};
```

## Logic Breakdown

1. Inserting After a Node

     To insert a new node after a specific node, update these pointers:

     - The new node's `next` points to the target node's old `next`.
     - The new node's `prev` points to the target node.
     - The target node's `next` is updated to the new node.
     - If the following node exists, its `prev` is updated to the new node.

2. Deleting a Node

     Deletion in a DLL is efficient because each node has a `prev` pointer. To delete a node:

     - Link the previous node's `next` to the deleted node's `next`.
     - Link the next node's `prev` to the deleted node's `prev`.
     - Handle edge cases when deleting the head or the tail.

## Function Reference

- `createNode()`: Allocates memory and initializes pointers to `NULL`.
- `insertFront()`: Adds a node at the beginning of the list.
- `insertAfter()`: Inserts a value immediately after a given node pointer.
- `deleteNode()`: Removes a specific node and repairs links between neighbors.

## Test Case & Results

The `main()` function demonstrates building a list, inserting in the middle, and deleting the tail.

Sample interaction:

- Build list: insert 10, then 20, then 30 (list: 30 <-> 20 <-> 10).
- Insert after: locate node with value 20 and insert 25.
- Delete: remove the last node (10).

### Sample Output

```text
Initial List: 30 <-> 20 <-> 10 <-> NULL
Inserting 25 after 20...
30 <-> 20 <-> 25 <-> 10 <-> NULL
Deleting 10 (the tail)...
30 <-> 20 <-> 25 <-> NULL
```

## Complexity Analysis

- **Time Complexity:**
    - Insertion/Deletion: $O(1)$ if you already have the pointer to the node; otherwise $O(n)$ to search.
    - Traversal: $O(n)$.
- **Space Complexity:** $O(1)$ per operation (excluding node storage).
