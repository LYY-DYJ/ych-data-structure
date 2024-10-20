#include<iostream>
#include<string.h>

#define MAX_LEXEME_LENGHT 64
enum Token_type{NUMBER,OPERATOR,LEFT_BRACKET,RIGHT_BRACKET,NONE};

union Literal
{
    int value=0;
    float float_value;
    char op;
};



class Token
{
    public:
        Token_type type;
        char lexeme[MAX_LEXEME_LENGHT];
        Literal literal;
        Token();
        Token(Token& t);
        friend std::ostream& operator<<(std::ostream &os, Token& t);
};

