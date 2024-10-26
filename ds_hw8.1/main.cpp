#include<iostream>

int kmp(char *p, char *t);

int main()
{
    char p[]="123";
    char t[]="01230000";
    std::cout<<kmp(p,t)<<std::endl;
    return 0;
}