// Quick Sort
#include <stdio.h>  
#include <stdlib.h>
int a[10], n, i, j, p, pivot, t, m;
int partition(int a[], int l, int u)
{
    pivot = a[u];
    i = l - 1;
    for (j = l; j < u; j++)
    {
        if (a[j] < pivot)
        {
            i += 1;
            m = a[i];
            a[i] = a[j];
            a[j] = m;
        }
    }
    t = a[i + 1];
    a[i + 1] = a[u];
    a[u] = t;
    return i + 1;
}
void quicksort(int a[], int l, int u)
{
    if (l < u)
    {
        p = partition(a, l, u);
        quicksort(a, l, p - 1);
        quicksort(a, p + 1, u);
    }
}
void main()
{
    printf("Enter the number of elements you wanna take:\n");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    quicksort(a, 0, n - 1);
    printf("The sorted array using quick sort is:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
}