#include <stdio.h>
#define max 10
int array[max];
void merge_sort(int, int);
void merge(int, int, int);

int main()
{
    int n, i;
    printf("enter the number of the element :");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("enter the data %d:", i + 1);
        scanf("%d", &array[i]);
    }
    merge_sort(0, n - 1);
    for (i = 0; i < n; i++)
        printf("\n data -%d: %d", i + 1, array[i]);
    return 0;
}
void merge_sort(int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        merge_sort(low, mid);
        merge_sort(mid + 1, high);
        merge(low, mid, high);
    }
}
void merge(int low, int mid, int high)
{
    int i, k;
    i = k = low;
    int r;
    int j = mid + 1;
    int temp[max];
    while (i <= mid && j <= high)
    {
        if (array[i] < array[j])
        {
            temp[k++] = array[i++];
        }
        else
        {
            temp[k++] = array[j++];
        }
    }
    while (i <= mid)
    {
        temp[k++] = array[i++];
    }
    while (j <= high)
    {
        temp[k++] = array[j++];
    }

    for (r = low; r <= high; r++)
        array[r] = temp[r];
}