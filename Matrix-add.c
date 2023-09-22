#include <stdio.h>
void main()
{
    int a[5][5], b[5][5], c[5][5], i, j, m, n;
    printf("How many rows and columns?");
    scanf("%d%d", &m, &n);
    printf("\nEnter first matrix:\n");
    for (i = 0; i < m; ++i)
        for (j = 0; j < n; ++j)
            scanf("%d", &a[i][j]);
    printf("\nEnter second matrix:\n");
    for (i = 0; i < m; ++i)
        for (j = 0; j < n; ++j)
            scanf("%d", &b[i][j]);
    printf("First matrix is :\n");
    for (i = 0; i < m; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("Second matrix is :\n");
    for (i = 0; i < m; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < m; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    printf("\nMatrix after addition:\n");
    for (i = 0; i < m; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
}