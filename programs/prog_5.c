#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int adj[MAX][MAX];
int visited[MAX];
int n;

void initGraph(int vertices) {
    n = vertices;
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }
}

void addEdge(int u, int v) {
    if (u >= n || v >= n || u < 0 || v < 0) {
        printf("Error: Nodes must be between 0 and %d\n", n - 1);
        return;
    }
    adj[u][v] = 1;
    adj[v][u] = 1;
}

void cleanInput() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void bfs(int startNode) {
    int queue[MAX];
    int front = 0, rear = 0;
    int bfs_visited[MAX];
    int i;

    if (startNode >= n || startNode < 0) {
        printf("Invalid start node.\n");
        return;
    }

    for(i = 0; i < n; i++) bfs_visited[i] = 0;

    printf("%d ", startNode);
    bfs_visited[startNode] = 1;
    queue[rear++] = startNode;

    while (front < rear) {
        int current = queue[front++];

        for (i = 0; i < n; i++) {
            if (adj[current][i] == 1 && bfs_visited[i] == 0) {
                printf("%d ", i);
                bfs_visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

void dfs(int current) {
    int i;
    printf("%d ", current);
    visited[current] = 1;

    for (i = 0; i < n; i++) {
        if (adj[current][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }
}

int main() {
    int vertices, edges, u, v, i;
    int startNode;

    printf("Enter number of vertices: ");
    while(scanf("%d", &vertices) != 1) {
        printf("Invalid input. Enter a number: ");
        cleanInput();
    }
    
    initGraph(vertices);

    printf("Enter number of edges: ");
    while(scanf("%d", &edges) != 1) {
        printf("Invalid input. Enter a number: ");
        cleanInput();
    }

    for (i = 0; i < edges; i++) {
        printf("\n--- Edge %d ---\n", i + 1);
        
        printf("Enter Start Node (0 to %d): ", n-1);
        while(scanf("%d", &u) != 1) {
            printf("Invalid input. Enter a number: ");
            cleanInput();
        }

        printf("Enter End Node (0 to %d): ", n-1);
        while(scanf("%d", &v) != 1) {
            printf("Invalid input. Enter a number: ");
            cleanInput();
        }

        addEdge(u, v);
    }

    printf("\nEnter start node for BFS: ");
    while(scanf("%d", &startNode) != 1) {
        printf("Invalid input. Enter a number: ");
        cleanInput();
    }
    printf("BFS Traversal: ");
    bfs(startNode);

    for (i = 0; i < n; i++) visited[i] = 0;

    printf("\nEnter start node for DFS: ");
    while(scanf("%d", &startNode) != 1) {
        printf("Invalid input. Enter a number: ");
        cleanInput();
    }
    printf("DFS Traversal: ");
    dfs(startNode);
    printf("\n");

    return 0;
}