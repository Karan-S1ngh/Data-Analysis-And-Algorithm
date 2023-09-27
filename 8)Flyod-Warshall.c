#include <stdio.h>
#include <limits.h>

// Maximum number of vertices
#define V 100

int counter = 0;

// Function to print the solution matrix
void printSolution(int dist[V][V], int n) {
    printf("Shortest distances between every pair of vertices:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INT_MAX) {
                printf("INF ");
            } else {
                printf("%d   ", dist[i][j]);
            }
        }
        printf("\n");
    }
}

// Function to perform the Floyd-Warshall algorithm
void floydWarshall(int graph[V][V], int n) {
    int dist[V][V];

    // Initialize the dist matrix to be the same as the input graph matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Update dist[][] if a shorter path is found
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                counter++;
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the resulting matrix
    printSolution(dist, n);
}

int main() {
    int n;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int graph[V][V];

    printf("Enter the graph matrix (%dx%d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    floydWarshall(graph, n);
    
    printf("Time Complexity = %d", counter);
    return 0;
}

/*OUTPUT
Enter the number of vertices: 3
Enter the graph matrix (3x3):
0 4 11
6 0 2
3 99999999 0
Shortest distances between every pair of vertices:
0   4   6   
5   0   2   
3   7   0 
Time Complexity = 27
*/
