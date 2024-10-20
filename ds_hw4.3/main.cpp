#include<stdio.h>
class Array
{
private:
    int length;
    int *a;

public:
    Array(int len)
    {
        a = new int[len];
        length = len;
        printf("array created\n");
    }
    ~Array()
    {
        delete[] a;
        printf("array deleted\n");
    }
};

int main()
{
    Array a(10);
    Array b=a;
    return 0;
}