#include <string.h>
int *build_next(char *p)
{
    int m = strlen(p);
    int *next;
    next = new int[m];
    next[0] = -1;
    int t;
    for (int j = 0; j < m - 1; j++)
    {
        t = next[j];
        while (t != -1 && p[j] != p[t])
        {
            t = next[t];
        }
        next[j + 1] = t + 1;
    }
    return next;
}