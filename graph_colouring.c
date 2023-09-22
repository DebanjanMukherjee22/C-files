#include <stdio.h>
int G[10][10], x[30], m, n, f = 0;
void nextvalue(int k)
{
    int j;
    while (1)
    {
        x[k] = (x[k] + 1) % (m + 1);
        if (x[k] == 0)
            return;
        for (j = 1; j <= n; j++)
        {
            if (G[j][k] != 0 && x[k] == x[j])
                break;
        }
        if (j == n + 1)
            return;
    }
}
void m_coloring(int k)
{
    int i;
    while (1)
    {
        nextvalue(k);
        if (x[k] == 0)
            return;
        if (k == n)
        {
            f = 1;
            for (i = 1; i <= k; i++)
                printf("%d\t", x[i]);
            printf("\n");
        }
        if (k < n)
            m_coloring(k + 1);
    }
}
int main()
{
    int e, i, j, u, v;
    printf("Enter the number of vertex:\n");
    scanf("%d", &n);
    printf("Enter the number of edges:\n");
    scanf("%d", &e);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            G[i][j] = 0;
        }
    }
    printf("Enter the starting vertex and ending vertex:\n");
    for (i = 1; i <= e; i++)
    {
        scanf("%d%d", &u, &v);
        G[u][v] = G[v][u] = 1;
    }
    for (m = 1; m <= n; m++)
    {
        m_coloring(1);
        if (f == 1)
        {
            printf("Coloured with %d colours", m);
            break;
        }
    }
    return 0;
}