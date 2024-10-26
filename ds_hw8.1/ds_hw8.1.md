# DS_HW_8.1 KMP #
## 实现 ##
### build_next.cpp ###
从 n[0:j] 得出 n[j+1]  
循环条件为j in [0,m-2]  
用双重循环实现
```cpp
#include<string.h>
int *build_next(char *p)
{
    int m=strlen(p);
    int *next;
    next = new int[m];
    next[0]=-1;
    int t;
    for(int j=0;j<m-1;j++)
    {
        t = next[j];
        while(t!=-1&&p[j]!=p[t])
        {
            t=next[t];
        }
        next[j+1]=t+1;
    }
    return next;
}
```
### kmp.cpp ###
```cpp
#include <string.h>
int *build_next(char *p);

int kmp(char *p, char *t)
{
    int *next = build_next(p);
    int n = strlen(t);
    int m = strlen(p);
    int i = 0, j = 0;
    while (j != m && i != n)
    {
        if (j == -1 || t[i] == p[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }
    delete[] next;
    return i-j;
}
```
## 测试 ##
### main.cpp ###
```cpp
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
```
## 结果 ##
![alt text](image.png)

