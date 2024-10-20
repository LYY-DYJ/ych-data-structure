#include <stdio.h>
#include <cassert>
#include <Arr_List.h>
#include <Stack.h>
#include <Token.h>

Arr_List<Token> *tokenizator(char *text);

int PFE(Arr_List<Token> *listp)
{
    Stack<int> stack(listp->length());
    for (int i = 0; i < listp->length(); i++)
    {
        Token token_current;
        listp->get_value(i, token_current);
        if (token_current.type == OPERATOR)
        {
            int operand1 = 0, operand2 = 0, result = 0;
            if(stack.is_empty())
            {
                printf("Too much operator!");
                return 0;
            }
            stack.pop(operand2);
            if(stack.is_empty())
            {
                printf("Too much operator!");
                return 0;
            }
            stack.pop(operand1);
            if (token_current.literal.op == '+')
            {
                result = operand1 + operand2;
            }
            else if (token_current.literal.op == '-')
            {
                result = operand1 - operand2;
            }
            else if (token_current.literal.op == '*')
            {
                result = operand1 * operand2;
            }
            else if (token_current.literal.op == '/')
            {
                result = operand1 / operand2;
            }
            else
            {
                assert(0 && "In PFE, operator undefined");
            }
            stack.push(result);
        }
        else
        {
            stack.push(token_current.literal.value);
        }
    }
    int return_value = 0;
    stack.pop(return_value);
    if(!stack.is_empty())
    {
        printf("Too much operand!");
        return 0;
    }
    return return_value;
}