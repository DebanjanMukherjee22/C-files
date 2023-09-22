#include<stdio.h>
void main()
{
    float p,r,t,i;
    printf("Enter the principle amount :");
    scanf("%d",&p);
    printf("Enter the rate of interest :");
    scanf("%d",&r);
    printf("Enter the time in years : ");
    scanf("%d",&t);
    i=(p*t*r) / 100;
    printf("The value of simple interest is :%d",i);
}