#include <stdio.h>
#include <stdlib.h>

#define INF 99999   // large value for comparison

/* function prototype */
int *Dijkstra(int *graph, int n);

/* Dijkstra shortest path algorithm */
int *Dijkstra(int *graph, int n)
{
    int *dist = (int*)malloc(n * sizeof(int));      // distance array
    int *visited = (int*)calloc(n, sizeof(int));    // visited flag

    int i, j;

    /* initialize distance from source */
    for(i = 0; i < n; i++)
        dist[i] = graph[i];

    visited[0] = 1;   // source node

    for(i = 1; i < n; i++)
    {
        int min = INF;
        int u = -1;

        /* find unvisited node with smallest distance */
        for(j = 1; j < n; j++)
        {
            if(!visited[j] && dist[j] != -1 && dist[j] < min)
            {
                min = dist[j];
                u = j;
            }
        }

        if(u == -1)
            break;

        visited[u] = 1;

        /* update distance of neighbors */
        for(j = 1; j < n; j++)
        {
            int w = graph[u * n + j];

            if(w != -1 && !visited[j])
            {
                int newDist = dist[u] + w;

                if(dist[j] == -1 || newDist < dist[j])
                    dist[j] = newDist;
            }
        }
    }

    return dist;
}

int main()
{
    int n = 5;
    int i, j;

    /* create adjacency matrix */
    int *graph = (int*)malloc(n * n * sizeof(int));

    /* initialize graph with -1 (no edge) */
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            graph[i * n + j] = -1;

    /* define edges */
    graph[0 * n + 1] = 100;
    graph[0 * n + 2] = 80;
    graph[0 * n + 3] = 30;
    graph[0 * n + 4] = 10;

    graph[1 * n + 2] = 20;
    graph[3 * n + 1] = 20;

    graph[3 * n + 2] = 20;
    graph[4 * n + 3] = 10;

    /* run Dijkstra */
    int *d = Dijkstra(graph, n);

    /* print shortest distance */
    for(i = 1; i < n; i++)
        printf("%d ", d[i]);

    return 0;
}