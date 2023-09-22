#include <stdio.h>
#include <stdlib.h>
#define MAX 6
int queue[MAX], f = -1, r = -1;
int main()
{
    int ch;
    while (1)
    {
        printf("\n1.Insertion\n2.Deletion\n3.Display\n4.Exit");
        printf("\nEnter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insertion();
            break;
        case 2:
            deletion();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("\nWrong choice\n");
        }
    }
}
void insertion()
{
    int item;
    if (r == MAX - 1)
        printf("Queue is full");
    else
    {
        printf("Enter the element:");
        scanf("%d", &item);
        if (f == -1)
            f = 0;
        r = r + 1;
        queue[r] = item;
    }
}
void deletion()
{
    int item;
    if (f == -1 || f > r)
        printf("\nQueue is empty\n");
    else
    {
        item = queue[f];
        f = f + 1;
        printf("\nDeleted item is %d", item);
    }
}
void display()
{
    int i;
    if (f == -1 || f > r)
        printf("\nQueue is empty");
    else
    {
        printf("The queue is:\n");
        for (i = f; i <= r; i++)
            printf("%d\n", queue[i]);
    }
}