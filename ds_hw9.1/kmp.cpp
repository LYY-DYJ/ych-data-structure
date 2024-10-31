#include <string.h>
int *build_next(char *p);

int kmp(char *p, char *t)
{
    int *next = build_next(p);
    int n = strlen(t);
    int m = strlen(p);
    int i = 0, j = 0;
    while (j != m && i != n)
    {
        if (j == -1 || t[i] == p[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }
    delete[] next;
    return i - j;
}