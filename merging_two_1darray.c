#include <stdio.h>
void main()
{
    int a1[10], a2[10], a3[30], i, j, m, n, k;
    printf("Enter the no. of arrays in a1 :");
    scanf("%d", &m);
    printf("\nEnter the no. of arrays in a2 :");
    scanf("%d", &n);
    printf("\nEnter elements in array a1 :");
    for (i = 0; i < m; i++)
        scanf("%d", &a1[i]);
    printf("\nEnter elements in array a2 :");
    for (j = 0; j < n; j++)
        scanf("%d", &a2[j]);
    i = 0;
    j = 0;
    k = 0;
    while ((i < m) && (j < n))
    {
        if (a1[i] <= a2[j])
        {
            a3[k] = a1[i++];
            k++;
        }
        else
        {
            a3[k] = a2[j++];
            k++;
        }
    }
    while (i < m)
    {
        a3[k] = a1[i++];
        k++;
    }
    while (j < n)
    {
        a3[k] = a2[j++];
        k++;
    }
    printf("Merging array is : ");
    for (k = 0; k < m + n; k++)
        printf("%d\t", a3[k]);
}