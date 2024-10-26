#include<iostream>
#include<string.h>

int *build_next(char* p);
int kmp(char *p, char *t);

int main()
{
    char p[]="1230123123";
    char t[]="01230123123000";
    int* next=build_next(p);
    for(int i=0;i<int(strlen(p));i++)
    {
        std::cout<<next[i];
    }
    std::cout<<std::endl;
    std::cout<<kmp(p,t)<<std::endl;
    return 0;
}