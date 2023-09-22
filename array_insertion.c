#include <stdio.h>
int main()
{
    int arr[10];
    int n, i, item, pos;
    printf("Enter the size of the array:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter element %d:",i+1);
        scanf("%d", &arr[i]);
    }
    printf("The elements are\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\nEnter position where element to be inserted:");
    scanf("%d", &pos);
    pos--;
    printf("\nEnter item to be inserted:");
    scanf("%d", &item);
    for (i = n - 1; i >= pos; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[pos] = item;
    n = n + 1;
    printf("\nThe elements are\n");
    for (i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    }
}