#include <iostream>
#include <math.h>

struct GaussPoint
{
    double w;
    double x;
};

double test_func(double x);
double gaussintegrate(double func(double));

int main()
{
    std::cout << gaussintegrate(test_func) << std::endl;
}

double test_func(double x)
{
    double y;
    y = x * x * x * x;
    return y;
}

double gaussintegrate(double func(double))
{
    GaussPoint gausspoint[8];
    double y = 0;
    gausspoint[0].w = 0.3626837833783620;gausspoint[0].x = -0.1834346424956498;
    gausspoint[1].w = 0.3626837833783620;gausspoint[1].x = 0.1834346424956498;
    gausspoint[2].w = 0.3137066458778873;gausspoint[2].x = -0.5255324099163290;
    gausspoint[3].w = 0.3137066458778873;gausspoint[3].x = 0.5255324099163290 ;
    gausspoint[4].w = 0.2223810344533745;gausspoint[4].x = -0.7966664774136267;
    gausspoint[5].w = 0.2223810344533745;gausspoint[5].x = 0.7966664774136267;
    gausspoint[6].w = 0.1012285362903763;gausspoint[6].x = -0.9602898564975363;
    gausspoint[7].w = 0.1012285362903763;gausspoint[7].x = 0.9602898564975363;
    for(int i=0;i<8;i++){
        y += gausspoint[i].w * func(gausspoint[i].x);
    }
    return y;
}