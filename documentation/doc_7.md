# Program 7: Dijkstra's Shortest Path Algorithm

## Overview
This program implements **Dijkstra's Algorithm**, a popular algorithm for finding the shortest paths between nodes in a graph. It is designed to handle graphs with non-negative edge weights. The algorithm calculates the shortest distance from a single source node to all other nodes in the network.

## Data Structure: Weighted Adjacency Matrix
The graph is represented using a 2D array (matrix). unlike previous unweighted graphs where `1` represented a connection, here the integer value represents the **cost** or **weight** of the edge.

* `graph[i][j] = 5`: There is an edge from `i` to `j` with a weight of 5.
* `graph[i][j] = 0`: There is no direct edge (treated as infinite distance during calculation).



## Algorithm Description

### Initialization
1.  **Cost Matrix**: Convert the input graph into a cost matrix where `0` (no edge) is replaced by `INF` (infinity), except for the distance to itself.
2.  **Distance Array**: Initialize the distance to all nodes as `INF`, except the start node which is `0`.
3.  **Visited Array**: Keep track of nodes for which the shortest path is already finalized.

### The Relaxation Loop
The algorithm repeats the following steps until all nodes are visited:

1.  **Select Min**: Look at all unvisited nodes and pick the one with the smallest current distance from the start. Let's call this node `u`.
2.  **Mark Visited**: Mark `u` as visited.
3.  **Relax Neighbors**: Check all neighbors of `u`. If the distance to `u` plus the weight of the edge `u-v` is less than the current known distance to `v`, update `v`'s distance.

$$
if (distance[u] + cost[u][v] < distance[v]) \{
    distance[v] = distance[u] + cost[u][v];
\}
$$



## Functions

| Function | Description |
| :--- | :--- |
| **dijkstra** | The core logic. It initializes arrays, performs the relaxation loop, and prints the final paths and costs. |
| **main** | Handles user input for the number of vertices and the weighted matrix. |

## Test Case

**Input Graph (3 vertices):**
* 0 -> 1 (Weight 4)
* 0 -> 2 (Weight 8)
* 1 -> 2 (Weight 2)
* 2 -> 1 (Weight 1)

**Matrix Input:**
```text
0 4 8
0 0 2
0 1 0