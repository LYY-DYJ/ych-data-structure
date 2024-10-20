#include <Stack.h>

bool stack_orders_judge(int *a, int *b, int len)
{
    Stack stack(len);
    int i = 0;
    int j = 0;
    int stack_top = 0;
    while (j < len)
    {
        stack.get_top(stack_top);
        while (i < len && (stack.is_empty() || stack_top != b[j]))
        {
            stack.push(a[i]);
            i++;
            stack.get_top(stack_top);
        }
        if (stack_top == b[j])
        {
            stack.pop(stack_top);
            j++;
        }
        else if (i == len)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int a[3]={1,2,3};
    int b[3]={3,1,2};
    printf("%d\n",stack_orders_judge(a,b,3));
    return 0;
}