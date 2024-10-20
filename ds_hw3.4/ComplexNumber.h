#include <iostream>
class ComplexNumber
{
private:
    double re;
    double im;
public:
    //构造函数
    ComplexNumber();
    ComplexNumber(double re);
    ComplexNumber(double re, double im);
    //获取复数的实部
    double get_re();
    //获取复数的虚部
    double get_im();
    //获取复数模的平方
    double get_modulus_squared();
    //设置复数的实部
    void set_re(double re);
    //设置复数的虚部
    void set_im(double im);
    //加的重载
    ComplexNumber operator+(ComplexNumber &c);
    //减的重载
    ComplexNumber operator-(ComplexNumber &c);
    //负号的重载
    ComplexNumber operator-();
    //乘的重载
    ComplexNumber operator*(ComplexNumber &c);
    //除的重载
    ComplexNumber operator/(ComplexNumber &c);
    //通过友元函数使iostream库中的输入输出可以访问复数的私有属性，实现输入输出的重载
    friend std::ostream& operator<<(std::ostream &os, ComplexNumber c);
    friend std::istream& operator>>(std::istream &is, ComplexNumber& c);
};