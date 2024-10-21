#include <Stack.h>
#include <iostream>

#define STACK_MAXSIZE 100

bool knap(int s, int n, int *w)
{
    struct frame
    {
        int s, n;
        int *w;
        int rd;
        bool k;
    };
    Stack<frame> knap_stack(STACK_MAXSIZE);
    frame curr = {s, n, w, 0, false};
    frame callee;
    knap_stack.push(curr);
label0:
    knap_stack.get_top(curr);
    if (curr.s == 0)
    {
        curr.k = true;
        knap_stack.modify_top(curr);
        goto label3;
    }
    if (curr.s < 0 || (curr.s > 0 && curr.n < 1))
    {
        curr.k = false;
        knap_stack.modify_top(curr);
        goto label3;
    }
    else
    {
        callee = {curr.s - curr.w[curr.n - 1], curr.n - 1, curr.w, 1, false};
        knap_stack.push(callee);
        goto label0;
    }
label1:
    knap_stack.pop(callee);
    knap_stack.get_top(curr);
    if (callee.k == true)
    {
        std::cout<<curr.w[curr.n - 1]<<" ";
        curr.k=true;
        knap_stack.modify_top(curr);
        goto label3;
    }
    else
    {
        callee = {curr.s,curr.n-1,curr.w,2,false};
        knap_stack.push(callee);
        goto label0;
    }
label2:
    knap_stack.pop(callee);
    knap_stack.get_top(curr);
    curr.k=callee.k;
    knap_stack.modify_top(curr);
    goto label3;    
label3:
    switch (curr.rd)
    {
    case 0:
        return curr.k;
        break;
    case 1:
        goto label1;
        break;
    case 2:
        goto label2;
        break;
    default:
        std::cout<<"Undefined rd!"<<std::endl;
        return false;
        break;
    }
}