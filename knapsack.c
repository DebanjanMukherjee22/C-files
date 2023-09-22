#include <stdio.h>
struct knack
{
    int p, w;
    float r, x;
} k[10], temp;
void main()
{
    int i, j, m, n;
    float c = 0;
    printf("Enter the total no. of products:");
    scanf("%d", &n);
    printf("Enter the capacity of knapsack:");
    scanf("%d", &m);
    printf("Enter the elements:");
    for (i = 0; i < n; i++)
    {
        scanf("%d%d", &k[i].p, &k[i].w);
        k[i].x = 0;
        k[i].r = (float)k[i].p / k[i].w;
    }
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (k[i].r < k[j].r)
            {
                temp = k[i];
                k[i] = k[j];
                k[j] = temp;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        if (m > k[i].w)
        {
            k[i].x = 1;
            c += k[i].p;
            m = m - k[i].w;
        }
        else
        {
            k[i].x = (float)m / k[i].w;
            c += k[i].p * k[i].x;
            m = 0;
            break;
        }
    }
    printf("Total profit is:%f\n", c);
    printf("Solution Vector:\t");
    for (i = 0; i < n; i++)
    {
        printf("%f\t", k[i].x);
    }
}
