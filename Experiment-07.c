//Bellman Ford C Code

#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 100
#define INF INT_MAX
int counter=0;
int graph[MAX_VERTICES][MAX_VERTICES];
int V;

void BellmanFord(int src) {
    int dist[MAX_VERTICES];

    // Initialize distances from source to all other vertices as INF
    for (int i = 1; i <= V; i++)
        dist[i] = INF;
    dist[src] = 0;

    // Relax edges V-1 times
    for (int count = 1; count <= V - 1; count++) {
        for (int u = 1; u <= V; u++) {
            counter++;
            for (int v = 1; v <= V; v++) {
                if (graph[u][v] != 0 && dist[u] != INF && dist[u] + graph[u][v] < dist[v])
                    dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the shortest distances
    printf("Vertex   Distance from Source\n");
    for (int i = 1; i <= V; i++) {
        if (dist[i] == INF) {
            printf("%d \t\t INFINITY\n", i);
        } else {
            printf("%d \t\t %d\n", i, dist[i]);
        }
    }
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    printf("Enter the adjacency matrix:\n");
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int source;
    printf("Enter the source vertex: ");
    scanf("%d", &source);

    BellmanFord(source);

    printf("Time Complexity = %d",counter);
    return 0;
}

/*OUTPUT
Enter the number of vertices: 7
Enter the adjacency matrix:
0 6 5 5 0 0 0
0 0 0 0 -1 0 0
0 -2 0 0 1 0 0
0 0 -2 0 0 -1 0
0 0 0 0 0 0 3
0 0 0 0 0 0 3
0 0 0 0 0 0 0
Enter the source vertex: 1
Vertex   Distance from Source
1 		 0
2 		 1
3 		 3
4 		 5
5 		 0
6 		 4
7 		 3
Time Complexity = 42
*/
