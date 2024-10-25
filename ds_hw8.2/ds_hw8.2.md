# DS_HW_8.2 Template&Functor#

## 实现 ##
将gauss_integrate的Functor类参数定义为模板T，函数会自动识别类型，只要保证不同的Functor类都可以用()操作符重载访问带参数的函数即可。
### gauss_integrate.tpp ###
```cpp
#include <Function.h>
template<typename F>
double gauss_integrate(F &f, double begin, double end)
{
    struct GaussPoint
    {
        double w;
        double x;
    } gausspoint[8];
    gausspoint[0].w = 0.3626837833783620;gausspoint[0].x = -0.1834346424956498;
    gausspoint[1].w = 0.3626837833783620;gausspoint[1].x = 0.1834346424956498;
    gausspoint[2].w = 0.3137066458778873;gausspoint[2].x = -0.5255324099163290;
    gausspoint[3].w = 0.3137066458778873;gausspoint[3].x = 0.5255324099163290 ;
    gausspoint[4].w = 0.2223810344533745;gausspoint[4].x = -0.7966664774136267;
    gausspoint[5].w = 0.2223810344533745;gausspoint[5].x = 0.7966664774136267;
    gausspoint[6].w = 0.1012285362903763;gausspoint[6].x = -0.9602898564975363;
    gausspoint[7].w = 0.1012285362903763;gausspoint[7].x = 0.9602898564975363;
    double y = 0;
    for(int i=0;i<8;i++){
        y += gausspoint[i].w * f((gausspoint[i].x)*(end-begin)/2+(end+begin)/2)*(end-begin)/2;
    }
    return y;
}
```
为了演示gauss_integrate函数可以通过template自动匹配类，并实现不同Functor类的积分，实现类似重载和多态的功能，定义了两个类，一个是多项式，另一个是余弦。通过这种方法，可以不用定义抽象基类作为接口，没有虚函数查表的过程，可以减少运行时间；代价是每有一种不同的Functor类被放到模板参数，编译器就会自动生成一种不同的函数代码，而只用继承就不会有这个问题。
### Function.h ###
```cpp
#ifndef FUNCTION_H
#define FUNCTION_H
class Polynomial
{
private:
    double func(double x) const;
    double *arg_list;
    int degree;

public:
    Polynomial();
    Polynomial(int degree, double *arg_list);
    Polynomial(const Polynomial &p);
    void operator=(const Polynomial &p);
    ~Polynomial();
    void set_arg(int n, double arg);
    void set_arg_list(double *arg_list);
    double operator()(double x) const;
    Polynomial integrate() const;
    Polynomial derivate() const;
};

class Cos
{
private:
    double func(double s) const;
    double _omega,_phi;

public:
    Cos();
    Cos(double omega,double phi);
    void operator=(const Cos& s);
    void set_omega(double omega);
    void set_phi(double phi);
    double omega();
    double phi();
    double operator()(double x) const;
};
#endif
```
### Function.cpp ###
```cpp
#ifndef FUNCTION_H
#define FUNCTION_H
class Polynomial
{
private:
    double func(double x) const;
    double *arg_list;
    int degree;

public:
    Polynomial();
    Polynomial(int degree, double *arg_list);
    Polynomial(const Polynomial &p);
    void operator=(const Polynomial &p);
    ~Polynomial();
    void set_arg(int n, double arg);
    void set_arg_list(double *arg_list);
    double operator()(double x) const;
    Polynomial integrate() const;
    Polynomial derivate() const;
};

class Cos
{
private:
    double func(double s) const;
    double _omega,_phi;

public:
    Cos();
    Cos(double omega,double phi);
    void operator=(const Cos& s);
    void set_omega(double omega);
    void set_phi(double phi);
    double omega();
    double phi();
    double operator()(double x) const;
};
#endif
```
## 测试 ##
可以看到我定义了两个Functor类
### main.cpp ###
```cpp
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
```

## 结果 ##
可以看到定积分的结果与多项式积分准确值相同，也计算出了cos在[0,pi/2]的定积分是1，gauss积分函数放入不同的类对象，均完成了积分
![result](image.png)