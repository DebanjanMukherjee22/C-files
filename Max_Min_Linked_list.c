#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *start = NULL;
struct node *tmp = NULL;
struct node *q = NULL;

int max, min, i;

void create(int);

void main()
{
    int a, n;
    printf("Enter the no. of nodes :\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the data :");
        scanf("%d", &a);
        create(a);
    }
    max = start->data;
    min = start->data;
    for (q = start; q != NULL; q = q->link)
    {
        if (max < q->data)
            max = q->data;
        if (min > q->data)
            min = q->data;
    }

    printf("\nEntered list is :\n\n");
    for (q = start; q != NULL; q = q->link)
        printf("%d\t", q->data);

    printf("\n\nMAX = %d      MIN = %d", max, min);
}

void create(int a)
{

    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->data = a;
    tmp->link = NULL;
    if (start == NULL)
    {
        start = tmp;
    }
    else
    {
        for (q = start; q->link != NULL; q = q->link)
            continue;
        q->link = tmp;
    }
}