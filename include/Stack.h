#include <stdio.h>
template <class T>
class Stack
{
private:
    T *sp;
    int top;
    int maxsize;

public:
    Stack(int size);
    Stack(Stack &stack);
    ~Stack();
    bool is_empty();
    int length();
    bool pop(T &item);
    bool push(T &item);
    bool get_top(T &item);
    bool modify_top(T &item);
};

template <class T>
Stack<T>::Stack(int size)
{
    maxsize = size;
    sp = new T[maxsize];
    top = -1;
}

template <class T>
Stack<T>::Stack(Stack &stack)
{
    maxsize = stack.maxsize;
    sp = new T[maxsize];
    top = stack.top;
    for (int i = 0; i <= top; i++)
    {
        sp[i] = stack.sp[i];
    }
}

template <class T>
Stack<T>::~Stack()
{
    delete[] sp;
}

template <class T>
bool Stack<T>::is_empty()
{
    return top == -1;
}

template <class T>
int Stack<T>::length()
{
    return top + 1;
}

template <class T>
bool Stack<T>::pop(T &item)
{
    if (top == -1)
    {
#ifdef STACK_PRINT
        printf("Underflow!\n");
#endif
        return false;
    }
    else
    {
        item = sp[top];
        top--;
        return true;
    }
}

template <class T>
bool Stack<T>::get_top(T &item)
{
    if (top == -1)
    {
        return false;
    }
    else
    {
        item = sp[top];
        return true;
    }
}

template <class T>
bool Stack<T>::modify_top(T &item)
{
    if (top == -1)
    {
        return false;
    }
    else
    {
        sp[top] = item;
        return true;
    }
}

template <class T>
bool Stack<T>::push(T &item)
{
    if (top == maxsize - 1)
    {
#ifdef STACK_PRINT
        printf("Overflow!\n");
#endif
        return 0;
    }
    else
    {
        top++;
        sp[top] = item;
        return 1;
    }
}
