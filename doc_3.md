## Program 3: Linked List Reverse Traversal

### Overview
This document describes a singly linked list program that prints the list in reverse order using recursion. The list itself remains unchanged; recursion uses the call stack to produce reversed output.

---

### Data structure
The program implements a standard singly linked list where each node points to the next node.

#### Struct definition
```c
struct node {
    int data;
    struct node *next;
};

struct node *head = NULL; // global head pointer
```

### Functions
- `insert(int val)` — create a new node and insert it at the head of the list.
- `display()` — traverse the list from head to tail and print values in order.
- `reverse_print(struct node *temp)` — recursively print nodes in reverse order.

### How the reverse traversal works
1. Insertions are done at the head, so inserting values 10 then 20 yields: 20 -> 10.
2. `reverse_print(temp)` works as:
   - If `temp == NULL`, return (base case).
   - Recursively call `reverse_print(temp->next)`.
   - After the recursive call returns, print `temp->data` (unwinding phase), producing reversed output.

### Example
Interactive run example:

```
Enter number of nodes: 3
Enter value: 1
Enter value: 2
Enter value: 3

Normal list: 3 2 1
Reverse traversal: 1 2 3
```

### Performance & constraints
- **Time Complexity:** $O(n)$ — each node visited once.
- **Space Complexity:** $O(n)$ — recursion uses call stack proportional to list length.
- **Memory management:** nodes allocated with `malloc` should be freed when no longer needed.

**Note:** For very large lists recursion depth may cause stack overflow; use an explicit stack (iterative) approach to avoid that.

---

End of document.
