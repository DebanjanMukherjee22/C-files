#include <stdio.h>
void bellman(int G[][10], int edge[][10], int V, int E, int source);
int main()
{
    int V, E, i, j, k, u, v, w, s;
    int G[10][10], edge[10][10];
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &V, &E);
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            G[i][j] = 0;
        }
    }
    k = 0;
    for (i = 1; i <= E; i++)
    {
        printf("Enter u, v and w for edge %d: ", i);
        scanf("%d %d %d", &u, &v, &w);
        G[u][v] = w;
        edge[k][0] = u;
        edge[k][1] = v;
        k++;
    }
    printf("Enter source vertex: ");
    scanf("%d", &s);
    bellman(G, edge, V, E, s);
    return 0;
}
void bellman(int G[][10], int edge[][10], int V, int E, int source)
{
    int i, j, k, flag = 1, d[10];
    for (i = 0; i < V; i++)
    {
        d[i] = 999;
    }
    d[source] = 0;
    for (i = 0; i < V - 1; i++)
    {
        for (k = 0; k < E; k++)
        {
            int u = edge[k][0];
            int v = edge[k][1];
            if (d[u] + G[u][v] < d[v])
            {
                d[v] = d[u] + G[u][v];
            }
        }
    }
    for (k = 0; k < E; k++)
    {
        int u = edge[k][0];
        int v = edge[k][1];
        if (d[u] + G[u][v] < d[v])
        {
            flag = 0;
            break;
        }
    }
    if (flag == 0)
    {
        printf("negative edge cycle is present\n");
    }
    else
    {
        printf("Minimum distances from source vertex %d:\n", source);
        for (i = 0; i < V; i++)
        {
            printf("Vertex %d: Distance = %d\n", i, d[i]);
        }
    }
}
