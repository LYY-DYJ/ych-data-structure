#include <string.h>

int kmp(char *p, char *t);

char *prepend_palindrome(char *s)
{
    int n = strlen(s);
    char t[n];
    for (int i = 0; i < n; i++)
    {
        t[i] = s[n - 1 - i];
    }
    t[n] = '\0';
    int k = kmp(s, t);
    char *result;
    result = new char[n + k];
    for (int i = 0; i < n + k; i++)
    {
        if (i < k)
        {
            result[i] = s[n - 1 - i];
        }
        else
        {
            result[i] = s[i-k];
        }
    }
    result[n + k] = '\0';
    return result;
}