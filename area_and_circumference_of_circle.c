#include <stdio.h>
int main()
{
    float r, a, c;
    printf("Enter the radius of Circle : ");
    scanf("%f", &r);
    c = 2 * 3.141592 * r;
    a = 3.14 * r * r;
    printf("Area of circle :%g", a);
    printf("Circumference of circle :%g", c);
}