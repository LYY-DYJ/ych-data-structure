#include <stdio.h>
#include <stdlib.h>
void printroll(int **a, int h1, int h2, int w1, int w2)
{
    if (h1 > h2 || w1 > w2) return;
    printroll(a, h1 + 1, h2 - 1, w1 + 1, w2 - 1);
    int i, j;
    for (i = h1, j = w1; j <= w2; j++)
        printf("%d ", a[i][j]);
    for (i = h1 + 1, j = w2; i <= h2; i++)
        printf("%d ", a[i][j]);
    for (i = h2, j = w2 - 1; j >= w1; j--)
        printf("%d ", a[i][j]);
    for (i = h2 - 1, j = w1; i >= h1 + 1; i--)
        printf("%d ", a[i][j]);
}
int main()
{
    int w = 4,h = 4;
    int **a;
    a = (int **)malloc(sizeof(int *) * h);
    for (int i = 0; i < h; i++)
        a[i] = (int *)malloc(sizeof(int) * w);
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
        {
            a[i][j] = w * i + j + 1;
            if (j == w - 1)
                printf("%d\n", a[i][j]);
            else
                printf("%d\t", a[i][j]);
        }
    printroll(a, 0, h - 1, 0, w - 1);
    printf("\n");
    return 0;
}