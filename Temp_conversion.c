#include<stdio.h>
void main()
{
    float a,b,c;
    printf("Give input in celcius:");
    scanf("%d",&c);
    a=(9*c)/5+32;
    printf("The conversion of C to F is :%d\n",a);
    b=(a-32)*5/9;
    printf("The conversion of F to C is :%d\n",b);
}