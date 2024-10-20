#include<stdio.h>

long long int fac(int n,long int result);

int main()
{
    int n = 1024*1024;
    printf("fac(%d)=%lld\n",n,fac(n,1));
    return 0;
}

long long int fac(int n,long int result)
{
    if(n==1) return result;
    else return fac(n-1,n*result);
}
