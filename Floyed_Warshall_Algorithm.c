#include <stdio.h>
void floyd(int a[10][10], int n)
{
    int k, i, j;
    for (k = 1; k <= n; k++)
    {
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (a[i][k] + a[k][j] < a[i][j])
                    a[i][j] = a[i][k] + a[k][j];
            }
        }
    }
    printf("The Matrix is:\n");
    for (i = 1; i <= n; i++)
    {
        printf("\n");
        for (j = 1; j <= n; j++)
            printf("%d\t", a[i][j]);
    }
    printf("\n\n");
}
int main()
{
    int a[10][10], i, j, n, u, v, w, e;
    printf("Enter the number of vertices\n");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (i == j)
                a[i][j] = 0;
            else
                a[i][j] = 999;
        }
    }
    printf("Enter the number of edges\n");
    scanf("%d", &e);
    for (i = 1; i <= e; i++)
    {
        printf("Enter u,v,w:\n");
        scanf("%d%d%d", &u, &v, &w);
        a[u][v] = w;
    }
    floyd(a, n);
    return 0;
}