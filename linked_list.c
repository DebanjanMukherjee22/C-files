#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
} *start = NULL;
void create(int data)
{
    struct node *tmp, *q;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->link = NULL;
    if (start == NULL)
        start = tmp;
    else
    {
        q = start;
        while (q->link != NULL)
            q = q->link;
        q->link = tmp;
    }
}
void display()
{
    struct node *q;
    if (start == NULL)
        printf("list is empty");
    else
    {
        q = start;
        while (q != NULL)
        {
            printf("%d ", q->info);
            q = q->link;
        }
    }
}
void add_beg(int data)
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->link = start;
    start = tmp;
}
void add_after(int data, int pos)
{
    int i;
    struct node *q, *tmp;
    q = start;
    for (i = 0; i < pos - 1; i++)
    {
        q = q->link;
        if (q == NULL)
        {
            printf("there are less than %d element", pos);
        }
    }
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->link = q->link;
    q->link = tmp;
}
void add_end(int data)
{
    struct node *tmp, *q;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->link = NULL;
    if (start == NULL)
        start = tmp;
    else
    {
        q = start;
        while (q->link != NULL)
            q = q->link;
        q->link = tmp;
    }
}
void del_beg()
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp = start;
    start = start->link;
    free(tmp);
}
void del_middle(int pos)
{
    struct node *tmp, *q;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp = start;
    q = start;
    for (int i = 0; i < pos; i++)
    {
        if (i == 0 && pos == 1)
        {
            start = start->link;
            free(tmp);
        }
        else
        {
            if (i == pos - 1 && tmp)
            {
                q->link = tmp->link;
                free(tmp);
            }
            else
            {
                q = tmp;
                if (q == NULL)
                {
                    printf("\n enter value is greater than the no of node in list");
                    break;
                }
                tmp = tmp->link;
            }
        }
    }
}
void del_end()
{
    struct node *tmp = start;
    while (tmp->link->link != NULL)
        tmp = tmp->link;
    tmp->link = NULL;
}
void count()
{
    struct node *q;
    q = start;
    int n = 0;
    while (q != NULL)
    {
        q = q->link;
        n++;
    }
    printf("the current list contain %d no of nodes", n);
}
void search(int data)
{
    struct node *q;
    int p = 0, f = 0;
    q = start;
    while (q != NULL)
    {
        if (q->info == data)
        {
            printf("item %d is found in %d position", data, p);
            f = 1;
        }
        q = q->link;
        p++;
    }
    if (f == 0)
        printf("the entered %d item is not present in the list", data);
}
void reverse()
{
    struct node *p1, *p2, *p3;
    if (start == NULL)
        printf("list is empty");
    else if (start->link == NULL)
        printf("the current list contain 1 node so reverse is not needed");
    else
    {
        p1 = start;
        p2 = p1->link;
        p3 = p2->link;
        p1->link = NULL;
        p2->link = p1;
        while (p3 != NULL)
        {
            p1 = p2;
            p2 = p3;
            p3 = p3->link;
            p2->link = p1;
        }
        start = p2;
    }
}
void add_end(int data);
void add_after(int data, int pos);
void add_beg(int data);
void display();
void create(int data);
void del_beg();
void del_middle(int pos);
void del_end();
void count();
void search(int data);
void reverse();
int main()
{
    int n, i, m, ch;
    while (1)
    {
        printf("\n1.To create \n2.To add node in first\n3.To add in between\n4.To add in end\n5.To del 1st element\n");
        printf("6.del from middle\n7.del from end\n8.display\n9.To Count\n10.To search\n11.reverse\n12.exit");
        printf("\nenter your choice:-");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("enter the no of node you want to insert:-");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
            {
                printf("enter the %d element:-", i + 1);
                scanf("%d", &m);
                create(m);
            }
            break;
        case 2:
            printf("enter the value you want to insert in beginning:-");
            scanf("%d", &m);
            add_beg(m);
            break;
        case 3:
            printf("enter the position you want to insert:-");
            scanf("%d", &n);
            printf("enter the element you want to insert in that at that position:-");
            scanf("%d", &m);
            add_after(m, n);
            break;
        case 4:
            printf("enter the elment you want to add in end");
            scanf("%d", &m);
            add_end(m);
            break;
        case 5:
            del_beg();
            break;
        case 6:
            printf("enter the position of node to delete from list indexing starting from 1-");
            scanf("%d", &m);
            del_middle(m);
            break;
        case 7:
            del_end();
            break;
        case 8:
            display();
            break;
        case 9:
            count();
            break;
        case 10:
            printf("enter the value to search:");
            scanf("%d", &m);
            search(m);
            break;
        case 11:
            reverse();
            break;
        case 12:
            exit(0);
        default:
            printf("\n wrong input\n");
            break;
        }
    }
}