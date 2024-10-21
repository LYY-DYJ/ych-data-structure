#include<Queue_by_stack.h>
#include<iostream>

#define N 10

int main()
{
    Queue_by_stack<int> q(10);
    for(int i=0;i<N;i++)
    {
        q.enqueue(i);
    }
    int tmp;
    while(q.dequeue(tmp))
    {
        std::cout<<tmp<<" ";
    }
    std::cout<<std::endl;
    return 0;
}