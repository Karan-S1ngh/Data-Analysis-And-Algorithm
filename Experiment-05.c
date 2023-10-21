// Dijkstra C Program 

#include <stdio.h>

#define INFINITY 999

void dijkstra(int n, int graph[10][10], int start) {
    int distance[10], visited[10] = {0}, min, u, i;

    for (i = 1; i <= n; i++) {
        distance[i] = INFINITY;
    }

    distance[start] = 0;

    for (i = 1; i <= n; i++) {
        min = INFINITY;
        for (u = 1; u <= n; u++) {
            if (!visited[u] && distance[u] < min) {
                min = distance[u];
                start = u;
            }
        }

        visited[start] = 1;

        for (u = 1; u <= n; u++) {
            if (!visited[u] && graph[start][u] && distance[start] + graph[start][u] < distance[u]) {
                distance[u] = distance[start] + graph[start][u];
            }
        }
    }

    printf("Vertex -> Shortest Distance from Source\n");
    for (i = 1; i <= n; i++) {
        printf("%d -> %d\n", i, distance[i]);
    }
}

int main() {
    int n, graph[10][10], i, j, start,counter=0;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            counter++;
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the source node: ");
    scanf("%d", &start);

    dijkstra(n, graph, start);
    
    printf("Time Complexity = %d ",counter);
}



/*OUTPUT
Enter the number of nodes: 6
Enter the cost matrix:
0 7 0 0 0 3
7 0 4 0 0 2
0 4 0 8 5 5
0 0 8 0 3 0
0 0 5 3 0 6
3 2 3 0 6 0
Enter the source node: 1
Vertex -> Shortest Distance from Source
1 -> 0
2 -> 5
3 -> 6
4 -> 12
5 -> 9
6 -> 3
Time Complexity=36
*/
