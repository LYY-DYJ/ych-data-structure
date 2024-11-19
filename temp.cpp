#include <stdio.h>
#include <vector>
template<class T>
class something
{
    public:
        T i;
        int f(int);
};

int main()
{
    something<int> a;
    a.i=1;
    std::vector<something<int>> list;
    list[0].i;
}