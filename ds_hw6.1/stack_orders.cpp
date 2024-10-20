#include <stdio.h>
#include <Stack.h>
void stack_orders(int *input, int begin, int end, Stack &stack, Stack &output)
{
    int tmp = -1;
    if (!stack.is_empty())
    {
        Stack pop_stack = stack;
        pop_stack.pop(tmp);
        Stack pop_output = output;
        pop_output.push(tmp);
        stack_orders(input, begin, end, pop_stack, pop_output);
    }
    if (!(begin > end))
    {
        Stack push_stack = stack;
        push_stack.push(input[begin]);
        Stack push_output = output;
        stack_orders(input, begin + 1, end, push_stack, push_output);
    }
    if (begin > end && stack.is_empty())
    {
        output.reverse_show();
    }
}
#define NUM 4

int main()
{
    Stack stack(NUM);
    Stack output(NUM);
    int input[NUM];
    for(int i=0;i<NUM;i++)
    {
        input[i]=i+1;
    }
    stack_orders(input, 0, NUM-1, stack, output);
}