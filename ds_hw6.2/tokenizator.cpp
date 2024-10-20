#include <string.h>
#include <Arr_List.h>
#include <Stack.h>
#include <Token.h>
#include <printf.h>

Arr_List<Token> *tokenizator(char *text)
{
    Arr_List<Token> *listp;
    listp = new Arr_List<Token>(10);

    int i = 0;
    while (text[i] != '\0')
    {
        Token token;
        if (text[i] == '+' || text[i] == '-' || text[i] == '*' || text[i] == '/')
        {
            token.type = OPERATOR;
            char str_tmp[2] = {text[i], '\0'};
            strcat(token.lexeme, str_tmp);
            token.literal.op = text[i];
            i++;
            listp->append(token);
        }
        else if (text[i] >= '0' && text[i] <= '9')
        {
            token.type = NUMBER;
            while (text[i] >= '0' && text[i] <= '9')
            {
                char str_tmp[1] = {text[i]};
                strcat(token.lexeme, str_tmp);
                i++;
            }
            char str_tmp[1] = {'\0'};
            strcat(token.lexeme, str_tmp);
            sscanf(token.lexeme, "%d", &token.literal.value);
            listp->append(token);
        }
        else if (text[i] == '(')
        {
            token.type = LEFT_BRACKET;
            char str_tmp[2] = {text[i], '\0'};
            strcat(token.lexeme, str_tmp);
            token.literal.op = text[i];
            i++;
            listp->append(token);
        }
        else if (text[i] == ')')
        {
            token.type = RIGHT_BRACKET;
            char str_tmp[2] = {text[i], '\0'};
            strcat(token.lexeme, str_tmp);
            token.literal.op = text[i];
            i++;
            listp->append(token);
        }
        else if(text[i]==' '||text[i]=='\n'||text[i]=='\t'||text[i]=='\0')
        {
            i++;
        }
        else
        {
            printf("Unrecognized input\n");
            return nullptr;
            i++;
        }
    }
    return listp;
}

// int main()
// {
//     char text[100] = "10 2+ 32*)()5";
//     Arr_List<Token> *listp = tokenizator(text);
//     listp->show();
//     return 0;
// }