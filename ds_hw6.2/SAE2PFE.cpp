#include <Token.h>
#include <stdio.h>
#include <Arr_List.h>
#include <Stack.h>

Arr_List<Token> *SAE2PFE(Arr_List<Token> *listp)
{
    Stack<Token> stack(listp->length());
    Arr_List<Token> *listp_out;
    listp_out = new Arr_List<Token>(1);
    for (int i = 0; i < listp->length(); i++)
    {
        Token token_current;
        listp->get_value(i, token_current);
        if (token_current.type == NUMBER)
        {
            listp_out->append(token_current);
        }
        else if (token_current.type == OPERATOR)
        {
            Token token_top;
            stack.get_top(token_top);
            while (!stack.is_empty() && token_top.type != LEFT_BRACKET &&
                   (token_current.literal.op == '+' 
                   || token_current.literal.op == '-' 
                   || token_top.literal.op == '*' 
                   || token_top.literal.op == '/'))
            {
                stack.pop(token_top);
                listp_out->append(token_top);
                stack.get_top(token_top);
            }
            stack.push(token_current);
        }
        else if (token_current.type == LEFT_BRACKET)
        {
            stack.push(token_current);
        }
        else if (token_current.type == RIGHT_BRACKET)
        {
            Token token_top;
            stack.get_top(token_top);
            while(!stack.is_empty()&&token_top.type!=LEFT_BRACKET)
            {
                stack.pop(token_top);
                listp_out->append(token_top);
                stack.get_top(token_top);
            }
            if(stack.is_empty())
            {
                printf("Brackets can't match!\n");
                delete listp_out;
                return nullptr;
            }
            else
            {
                stack.pop(token_top);
            }
        }
    }
    while(!stack.is_empty())
    {
        Token token_top;
        stack.pop(token_top);
        if(token_top.type==LEFT_BRACKET)
        {
            printf("Brackets can't match!\n");
            return nullptr;
        }
        listp_out->append(token_top);
    }
    return listp_out;
}
