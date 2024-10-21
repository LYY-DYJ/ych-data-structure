#include<iostream>
bool knap(int s, int n, int *w);
int main()
{
    int w[6]={1,2,3,4,5,20};
    bool b=knap(15,6,w);
    std::cout<<b<<std::endl;
}