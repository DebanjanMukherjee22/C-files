#include <stdio.h>
int main()
{
    int arr[10];
    int item, n, pos, i;
    printf("Enter the size of array:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter element:");
        scanf("%d", &arr[i]);
    }
    printf("The elements are\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }
    printf("Enter the position of item to be deleted:");
    scanf("%d", &pos);
    if (pos >= n + 1)
        printf("Deletion not possible");
    else
    {
        for (i = pos; i < n - 1; i++)
            arr[i] = arr[i + 1];
    }
    n = n - 1;
    printf("The element are\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }
    return 0;
}