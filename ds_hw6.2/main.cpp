#include <stdio.h>

#include <Arr_List.h>
#include <Token.h>

Arr_List<Token> *tokenizator(char *text);
int PFE(Arr_List<Token> *listp);
Arr_List<Token> *SAE2PFE(Arr_List<Token> *listp);
int main()
{
    char text[100];
    while (fgets(text, sizeof(text), stdin))
    {
        if (!strcmp(text, ""))
            continue;
        Arr_List<Token> *listp = tokenizator(text);
        if(listp==nullptr)
        {
            continue;
        }
        listp->show();
        Arr_List<Token> *listp_PFE = SAE2PFE(listp);
        if (listp_PFE == nullptr)
        {
           continue;
        }
        listp_PFE->show();
        int result = PFE(listp_PFE);
        printf("%s = %d\n", text, result);
    }
}