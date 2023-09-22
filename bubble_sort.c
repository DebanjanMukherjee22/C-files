#include <stdio.h>
int main()
{
    int a[10], i, j, n, t = 0;
    printf("Enter the size of the array:");
    scanf("%d", &n);
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (a[j] >= a[j + 1])
            {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
    printf("The sorted array is:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]) ;
    }
    return 0;
}