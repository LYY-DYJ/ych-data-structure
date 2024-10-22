#include <iostream>
#include <stack_reverse.h>

#define N 10

int main()
{
    Stack<int> stack(20);
    for (int i=0; i < N; i++)
    {
        stack.push(i);
    }
    std::cout<<std::endl;
    stack_reverse(stack);
    int tmp;
    while (stack.pop(tmp))
    {
        std::cout << tmp << " ";
    }
    std::cout << std::endl;
}