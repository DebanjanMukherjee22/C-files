// Stack using Linked List
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
} *top = NULL;

void push(int item)
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = item;
    tmp->link = top;
    top = tmp;
}

void pop()
{
    struct node *tmp;
    int item;
    if (top == NULL)
    {
        printf("Stack Underflow!!!\n");
    }
    else
    {
        tmp = top;
        item = top->info;
        printf("The popped item is= %d\n",item);
        top = top->link;
        free(tmp);
    }
}

void display()
{
    struct node *tmp;
    tmp = top;
    if (top == NULL)
    {
        printf("stack Underflow!!!\n");
    }
    else
    {
        printf("The stack elements are: \n");
        while (tmp != NULL)
        {
            printf("%d\n", tmp->info);
            tmp = tmp->link;
        }
    }
}

int main()
{
    int choice, item;
    while (1)
    {
        printf("Press\n (1) for Push\n (2) for Pop\n (3) for DISPLAY\n (4) for EXIT\n");
        printf("Enter your choice: \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the item: ");
            scanf("%d", &item);
            push(item);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Wrong Choice!!!\n");
        }
    }
    return 0;
}