#include<Token.h>

Token::Token()
{
    type=NONE;
    strcpy(lexeme,"");
    literal.value=0;
}
Token::Token(Token& t)
{
    type=t.type;
    strcpy(lexeme,t.lexeme);
    literal.value=t.literal.value;
}
std::ostream& operator<<(std::ostream &os, Token& t)
{
    os<<"{type:"<<t.type<<",lexeme:"<<t.lexeme<<"}";
    return os;
}