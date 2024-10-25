#include<iostream>
#include<math.h>
#include"Function.h"
#include"gauss_integrate.tpp"
template<typename F>
double gauss_integrate(F &f, double begin, double end);

int main()
{
    double args[]={1,2,3};
    Polynomial p(3,args);
    Cos cos;
    std::cout<<p.integrate()(3)-p.integrate()(-1)<<std::endl;
    std::cout<<gauss_integrate(p,-1,3)<<std::endl;
    std::cout<<gauss_integrate(cos,0,M_PI/2)<<std::endl;
}