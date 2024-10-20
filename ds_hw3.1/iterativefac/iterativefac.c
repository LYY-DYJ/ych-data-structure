#include<stdio.h>

long long int fac(int n);

int main(){
	int n = 5;
	printf("fac(%d)=%lld\n",n,fac(n));
	return 0;
}

long long int fac(int n)
{
	long long int result = 1;
	for(int i=n;i>0;i--)
	{
		result*=i;
	}
	return result;
}
