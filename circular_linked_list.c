#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node sn;
sn *start = NULL;
void initialise(int x)
{
    if (start == NULL)
    {
        sn *newnode;
        newnode = (sn *)malloc(sizeof(sn));
        newnode->data = x;
        start = newnode;
        newnode->next = start;
    }
    else
        printf("list is not empty\n");
}
void insert_begin(int x)
{
    sn *newnode, *i;
    newnode = (sn *)malloc(sizeof(sn));
    newnode->data = x;
    newnode->next = start;
    for (i = start; i->next != start; i = i->next)
        ;
    start = newnode;
    i->next = start;
}
void insert_end(int x)
{
    sn *newnode, *i;
    newnode = (sn *)malloc(sizeof(sn));
    newnode->data = x;
    for (i = start; i->next != start; i = i->next)
        ;
    i->next = newnode;
    newnode->next = start;
}
void display()
{
    if (start == NULL)
    {
        printf("list is empty\n");
    }
    else
    {
        sn *i;
        for (i = start; i->next != start; i = i->next)
            printf("%d ", i->data);
        printf("%d ", i->data);
    }
}
void count()
{
    int n = 0;
    sn *i;
    for (i = start; i != NULL; i = i->next)
        n++;
    printf("%d ", n);
}
void insert_after(int x, int y)
{
    sn *newnode, *i;

    for (i = start; i->data != x || i != NULL; i = i->next)
        ;
    printf("data found");
    newnode = (sn *)malloc(sizeof(sn));
    newnode->data = y;
    newnode->next = i->next;
    i->next = newnode;
}
void insert_before(int x, int y)
{
    sn *newnode, *i;
    if (start->data == x)
        insert_begin(y);
    else
    {
        for (i = start; i->next->data != x || i != NULL; i = i->next)
            ;
        printf("data found");
        newnode = (sn *)malloc(sizeof(sn));
        newnode->data = y;
        newnode->next = i->next;
        i->next = newnode;
    }
}
void insert_after_position(int x, int y)
{
    sn *newnode, *i;
    int j = 1;
    for (i = start; j != x; i = i->next)
        j++;
    newnode = (sn *)malloc(sizeof(sn));
    newnode->data = y;
    newnode->next = i->next;
    i->next = newnode;
}
void insert_before_position(int x, int y)
{
    sn *newnode, *i;
    int j = 1;
    if (x == 1)
        insert_begin(y);
    else
    {
        for (i = start; j != x - 1; i = i->next)
            j++;
        newnode = (sn *)malloc(sizeof(sn));
        newnode->data = y;
        newnode->next = i->next;
        i->next = newnode;
    }
}
int main()
{
    int ch, i, element, value;
    while (3 * 3 == 9)
    {
        printf("enter the choice:\n 1 to initialise\n 2 to insert begin\n 3 to display\n 4 to insert at end\n 5 to count number of nodes\n press 6 to insert after\n press 7 to insert before\n press 8 to insert after position\n press 9 to insert before position\n 10 to exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Initialization\n");
            printf("enter data to insert");
            scanf("%d", &element);
            initialise(element);
            break;
        case 2:
            printf("insert begin\n");
            printf("enter data to insert at the begin");
            scanf("%d", &element);
            insert_begin(element);
            break;
        case 3:
            printf("display\n");
            display();
            break;
        case 4:
            printf("insert end\n");
            printf("enter data to insert at the end");
            scanf("%d", &element);
            insert_end(element);
            break;
        case 5:
            printf("count the number of nodes");
            count();
            break;
        case 6:
            printf("enter the value after which you want to insert");
            scanf("%d", &value);
            printf("enter the value you want to insert");
            scanf("%d", &element);
            insert_after(value, element);
            break;
        case 7:
            printf("enter the value before which you want to insert");
            scanf("%d", &value);
            printf("enter the value you want to insert");
            scanf("%d", &element);
            insert_before(value, element);
            break;
        case 8:
            printf("enter the position after which you want to insert");
            scanf("%d", &value);
            printf("enter the value you want to insert");
            scanf("%d", &element);
            insert_after_position(value, element);
            break;
        case 9:
            printf("enter the position before which you want to insert");
            scanf("%d", &value);
            printf("enter the value you want to insert");
            scanf("%d", &element);
            insert_before_position(value, element);
            break;
        case 10:
            exit(1);
        default:
            printf("wrong choice\n");
        }
    }
}
