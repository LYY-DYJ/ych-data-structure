#include <stdio.h>
class Stack
{
private:
    int *sp;
    int top;
    int maxsize;

public:
    Stack(int size);
    Stack(Stack &stack);
    ~Stack();
    bool is_empty();
    bool pop(int &item);
    bool push(int item);
    bool get_top(int &item);
    void show();
    void reverse_show();
};

#ifndef STACK_H
#define STACK_H

Stack::Stack(int size)
{
    maxsize = size;
    sp = new int[maxsize];
    top = -1;
}

Stack::Stack(Stack &stack)
{
    maxsize = stack.maxsize;
    sp = new int[maxsize];
    top = stack.top;
    for (int i = 0; i <= top; i++)
    {
        sp[i] = stack.sp[i];
    }
}

Stack::~Stack()
{
    delete[] sp;
}

bool Stack::is_empty()
{
    return top == -1;
}

bool Stack::pop(int &item)
{
    if (top == -1)
    {
        printf("Underflow!\n");
        return false;
    }
    else
    {
        item = sp[top];
        top--;
        return true;
    }
}

bool Stack::get_top(int &item)
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

bool Stack::push(int item)
{
    if (top == maxsize - 1)
    {
        printf("Overflow!\n");
        return 0;
    }
    else
    {
        top++;
        sp[top] = item;
        return 1;
    }
}

void Stack::show()
{
    for (int i = top; i >= 0; i--)
    {
        printf("%d", sp[i]);
    }
    printf("\n");
}

void Stack::reverse_show()
{
    for (int i = 0; i <= top; i++)
    {
        printf("%d", sp[i]);
    }
    printf("\n");
}
#endif