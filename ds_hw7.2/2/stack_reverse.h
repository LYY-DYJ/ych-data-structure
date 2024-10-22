#include <Stack.h>

template <typename T>
void stack_reverse(Stack<T> &stack)
{
    Stack<T> buffer(stack.length());
    T top;
    T tmp;
    for (int i = 0; i < stack.length(); i++)
    {
        stack.pop(top);
        int length=stack.length();
        for (int j = 0; j < length - i; j++)
        {
            stack.pop(tmp);
            buffer.push(tmp);
        }
        stack.push(top);
        while(!buffer.is_empty())
        {
            buffer.pop(tmp);
            stack.push(tmp);
        }
    }
}