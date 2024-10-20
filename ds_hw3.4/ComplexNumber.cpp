#include "ComplexNumber.h"

ComplexNumber::ComplexNumber()
{
    this->re = 0;
    this->im = 0;
}

ComplexNumber::ComplexNumber(double re)
{
    this->re = re;
    this->im = 0;
}

ComplexNumber::ComplexNumber(double re, double im)
{
    this->re = re;
    this->im = im;
}

double ComplexNumber::get_re()
{
    return this->re;
}

double ComplexNumber::get_im()
{
    return this->im;
}

double ComplexNumber::get_modulus_squared()
{
    return this->re * this->re + this->im * this->im;
}

void ComplexNumber::set_re(double re)
{
    this->re = re;
}

void ComplexNumber::set_im(double im)
{
    this->im = im;
}

ComplexNumber ComplexNumber::operator+(ComplexNumber &c)
{
    ComplexNumber result;
    result.set_re(this->re + c.re);
    result.set_im(this->im + c.im);
    return result;
}

ComplexNumber ComplexNumber::operator-(ComplexNumber &c)
{
    ComplexNumber result;
    result.set_re(this->re - c.re);
    result.set_im(this->im - c.im);
    return result;
}

ComplexNumber ComplexNumber::operator-()
{
    ComplexNumber result;
    result.set_re(-this->re);
    result.set_im(-this->im);
    return result;
}

ComplexNumber ComplexNumber::operator*(ComplexNumber &c)
{
    ComplexNumber result;
    result.set_re(this->re * c.re - this->im * c.im);
    result.set_im(this->im * c.re + this->re * c.im);
    return result;
}

ComplexNumber ComplexNumber::operator/(ComplexNumber &c)
{
    ComplexNumber result;
    double c_modulus_squared = c.get_modulus_squared();
    result.set_re((this->re * c.re + this->im * c.im) / c_modulus_squared);
    result.set_im((this->im * c.re - this->re * c.im) / c_modulus_squared);
    return result;
}

std::ostream &operator<<(std::ostream &os, ComplexNumber c)
{
    os << "Re: " << c.re << ", Im: " << c.im;
    return os;
}

std::istream &operator>>(std::istream &is, ComplexNumber& c)
{
    is >> c.re >> c.im;
    return is;
}