#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int stack[MAX], t = -1;
void push()
{
    int item;
    if (t == MAX - 1)
        printf("\n The stack is full\n");
    else
    {
        printf("\nEnter the item to insert:-");
        scanf("%d", &item);
        t++;
        stack[t] = item;
    }
}
void pop()
{
    int item;
    if (t == -1)
        printf("\nThe stack is empty nothing can be del\n");
    else
    {
        item = stack[t];
        printf("\nThe deleted item is %d", item);
        t--;
    }
}
void display()
{
    int i;
    if (t == -1)
    {
        printf("\nThe stack is empty\n");
    }
    else
    {
        for (i = t; i >= 0; i--)
            printf("%d   ", stack[i]);
    }
}
int main()
{
    int ch;
    while (1)
    {
        printf("\n 1.To insert\n 2.To remove\n 3.To display\n 4.To exit\n");
        printf("enter your choice:-");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push();
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
            printf("\n wrong input kindly try again");
            break;
        }
    }
}