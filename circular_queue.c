#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int cqueue[MAX], f = -1, r = -1;
void insertion()
{
    int item;
    if ((f == 0 && r == MAX - 1) || (f == r + 1))
        printf("\nCircular queue is full\n");
    else
    {
        printf("\nEnter the element to be inserted:");
        scanf("%d", &item);
        if (f == -1)
        {
            f = 0;
            r = 0;
        }
        else if (r == MAX - 1)
        {
            r = 0;
        }
        else
            r = r + 1;
        cqueue[r] = item;
    }
}
void deletion()
{
    int item;
    if (f == -1)
        printf("\nCircular queue is empty\n");
    else
    {
        item = cqueue[f];
        printf("\nDeleted item is %d", item);
        if (f == r)
        {
            f = -1;
            r = -1;
        }
        else if (f == MAX - 1)
            f = 0;
        else
            f = f + 1;
    }
}
void display()
{
    int i;
    if (f == -1)
        printf("\nCircular queue is empty\n");
    else
    {
        if (f <= r)
        {
            for (i = 0; i <= f - 1; i++)
                printf("__,");
            for (i = f; i <= r; i++)
                printf("%d ,", cqueue[i]);
            for (i = r + 1; i <= MAX - 1; i++)
                printf("__,");
        }
        else
        {
            for (i = 0; i <= r; i++)
                printf("%d ,", cqueue[i]);
            for (i = r + 1; i <= f - 1; i++)
                printf("__,");
            for (i = f; i <= MAX - 1; i++)
                printf("%d ,", cqueue[i]);
        }
    }
}
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
            exit(1);
        default:
            printf("\nWrong choice\n");
        }
    }
    return 0;
}