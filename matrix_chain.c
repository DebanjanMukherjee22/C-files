#include <stdio.h>
#include <stdlib.h>
int m[10][10], s[10][10];
void matrix_chain(int *p, int n)
{
    int i, l, j, k, q;
    for (i = 1; i <= n; i++)
        m[i][i] = 0;
    for (l = 2; l <= n; l++)
    {
        for (i = 1; i <= (n - l + 1); i++)
        {
            j = i + l - 1;
            m[i][j] = 9999;
            for (k = i; k <= j - 1; k++)
            {
                q = (m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]);
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}
void optimal_paren(int i, int j)
{
    if (i == j)
        printf("A%d", i);
    else
    {
        printf("(");
        optimal_paren(i, s[i][j]);
        optimal_paren(s[i][j] + 1, j);
        printf(")");
    }
}
int main()
{
    int n, p[10], i;
    printf("Enter the number of matrices\n");
    scanf("%d", &n);
    printf("Enter the matrices\n");
    for (i = 0; i <= n; i++)
        scanf("%d", &p[i]);
    matrix_chain(p, n);
    printf("The minimum multiplication is: %d\n", m[1][n]);
    optimal_paren(1, n);
    return 0;
}