# Program 5: Graph Implementation using Adjacency Matrix

## Overview
This program implements an Undirected Graph using an Adjacency Matrix data structure. It demonstrates two fundamental graph traversal algorithms:
1.  **Breadth-First Search (BFS)**: Explores the graph layer by layer.
2.  **Depth-First Search (DFS)**: Explores the graph by going as deep as possible along each branch.

## Data Structure: Adjacency Matrix
The graph is represented by a 2D array (matrix) of size V x V, where V is the number of vertices.

* **adj[i][j] = 1**: Indicates an edge exists between vertex i and vertex j.
* **adj[i][j] = 0**: Indicates no edge exists.
* **Symmetry**: Since the graph is undirected, the matrix is symmetric.


## Algorithm Descriptions

### 1. Breadth-First Search (BFS)
BFS uses a Queue data structure (First-In, First-Out).
1.  Start at a selected source node.
2.  Visit the node and add it to the queue.
3.  While the queue is not empty:
    * Remove the front node.
    * Find all unvisited neighbors of this node.
    * Mark them as visited and add them to the queue.


### 2. Depth-First Search (DFS)
DFS uses the system stack via Recursion (Last-In, First-Out).
1.  Start at a selected source node and mark it as visited.
2.  Look for an adjacent, unvisited neighbor.
3.  Recursively call DFS on that neighbor.
4.  If no unvisited neighbors exist, backtrack to the previous node.


## Functions

| Function | Description |
| :--- | :--- |
| **initGraph(vertices)** | Initializes the adjacency matrix with zeros. |
| **addEdge(u, v)** | Creates a bidirectional link between vertex u and vertex v. |
| **cleanInput()** | Clears the input buffer to prevent errors if invalid text is entered. |
| **bfs(startNode)** | Performs iterative traversal using a queue array. |
| **dfs(current)** | Performs recursive traversal using the system call stack. |

## Test Case
**Graph Configuration:**
* **Vertices:** 4 (0, 1, 2, 3)
* **Edges:** (0-1), (0-2), (1-3)

**Visual Representation:**
  2 -- 0 -- 1 -- 3

**Execution:**
* **BFS (Start 0):** Visits neighbors 1 and 2, then moves to 1's neighbor (3).
    * Result: 0 1 2 3
* **DFS (Start 0):** Visits 1, then goes deep to 3, then backtracks to 0 to visit 2.
    * Result: 0 1 3 2

## Complexity Analysis
* **Time Complexity:** O(V^2)
  The matrix requires scanning an entire row (V columns) for every vertex visited.
* **Space Complexity:** O(V^2)
  The space required for the 2D array grows quadratically with the number of vertices.