#include <iostream>
#include <string.h>

char *prepend_palindrome(char *s);

int main()
{
    char str[100];
    while (scanf("%s",str))
    {
        char *result = prepend_palindrome(str);
        for (int i = 0; i < int(strlen(result)); i++)
        {
            std::cout << result[i];
        }
        std::cout << std::endl;
 
    }
    return 0;
}