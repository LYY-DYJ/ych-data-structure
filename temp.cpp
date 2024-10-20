#include<stdio.h>

int main()
{
    int a=1;
    int *p;
    p=&a;
    *p=2;
    printf("%d\n",a);
}