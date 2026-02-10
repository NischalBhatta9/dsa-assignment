#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define INF 9999

void dijkstra(int graph[MAX][MAX], int n, int startNode) {
    int cost[MAX][MAX], distance[MAX], pred[MAX];
    int visited[MAX], count, minDistance, nextNode, i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (graph[i][j] == 0)
                cost[i][j] = INF;
            else
                cost[i][j] = graph[i][j];
        }
    }

    for (i = 0; i < n; i++) {
        distance[i] = cost[startNode][i];
        pred[i] = startNode;
        visited[i] = 0;
    }

    distance[startNode] = 0;
    visited[startNode] = 1;
    count = 1;

    while (count < n - 1) {
        minDistance = INF;

        for (i = 0; i < n; i++) {
            if (distance[i] < minDistance && !visited[i]) {
                minDistance = distance[i];
                nextNode = i;
            }
        }

        visited[nextNode] = 1;
        for (i = 0; i < n; i++) {
            if (!visited[i]) {
                if (minDistance + cost[nextNode][i] < distance[i]) {
                    distance[i] = minDistance + cost[nextNode][i];
                    pred[i] = nextNode;
                }
            }
        }
        count++;
    }

    for (i = 0; i < n; i++) {
        if (i != startNode) {
            printf("\nDistance to node %d = %d", i, distance[i]);
            printf("\nPath = %d", i);
            j = i;
            do {
                j = pred[j];
                printf(" <- %d", j);
            } while (j != startNode);
        }
    }
    printf("\n");
}

int main() {
    int graph[MAX][MAX], i, j, n, u, startNode;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter the adjacency matrix (0 for no edge, positive value for weight):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("\nEnter the starting node: ");
    scanf("%d", &startNode);

    dijkstra(graph, n, startNode);

    return 0;
}