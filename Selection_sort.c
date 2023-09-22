//selection sort
#include<stdio.h>
void selectionSort(int a[], int n) {
    int i, j, minIndex, temp;
    for (i = 0; i < n-1; i++) {
        minIndex = i;
        for (j = i+1; j < n; j++) {
            if (a[j] < a[minIndex])
                minIndex = j;
        }
        temp = a[minIndex];
        a[minIndex] = a[i];
        a[i] = temp;
    }
}
int main() {
    int n, i;
    printf("Enter the total number of elements in the array: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements of the array: \n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    selectionSort(a, n);

    printf("Sorted array: \n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}