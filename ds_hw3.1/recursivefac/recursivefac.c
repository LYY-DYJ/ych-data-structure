#include<stdio.h>

long int fac(int n);

int main()
{
    int n = 1024*1024;
    printf("fac(%d)=%ld\n",n,fac(n));
    return 0;
}

long int fac(int n)
{
    if(n==1) return 1;
    else return n*fac(n-1);
}
