#include <stdio.h>

int f(int m, int n)
{
    int result = 0;
    if (m > 0)
    {
        for (int i = 1; i <= n && i <= m; i++)
        {
            result += f(m - i, i);
        }
    }
    else
        result = 1;
    return result;
}

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    printf("f(%d,%d)=%d\n", m, n, f(m, n));
    return 0;
}