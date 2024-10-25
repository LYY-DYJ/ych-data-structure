#include "Function.h"
#include<math.h>
Polynomial::Polynomial()
{
    degree = 0;
    arg_list = new double[1];
    arg_list[0] = 0.0;
}

Polynomial::Polynomial(int n, double *arg)
{
    degree = n;
    arg_list = new double[degree + 1];
    for (int i = 0; i < degree; i++)
    {
        arg_list[i] = arg[i];
    }
}

Polynomial::Polynomial(const Polynomial &p)
{
    degree = p.degree;
    arg_list = new double[degree + 1];
    for (int i = 0; i < degree; i++)
    {
        arg_list[i] = p.arg_list[i];
    }
}

void Polynomial::operator=(const Polynomial &p)
{
    degree = p.degree;
    arg_list = new double[degree + 1];
    for (int i = 0; i < degree; i++)
    {
        arg_list[i] = p.arg_list[i];
    }
}

Polynomial::~Polynomial()
{
    delete[] arg_list;
}

double Polynomial::func(double x) const
{
    double sum = 0.0;
    double exponent = 1.0;
    for (int i = 0; i <= degree; i++)
    {
        sum += exponent * arg_list[i];
        exponent *= x;
    }
    return sum;
}

void Polynomial::set_arg(int n, double arg)
{
    arg_list[n] = arg;
}

void Polynomial::set_arg_list(double *arg)
{
    for (int i = 0; i < degree; i++)
    {
        arg_list[i] = arg[i];
    }
}

double Polynomial::operator()(double x) const
{
    return func(x);
}

Polynomial Polynomial::integrate() const
{
    int new_degree = degree + 1;
    double *new_arg_list;
    new_arg_list = new double[new_degree];
    new_arg_list[0] = 0;
    for (int i = 1; i <= new_degree; i++)
    {
        new_arg_list[i] = arg_list[i - 1] / i;
    }
    Polynomial new_polynomial(new_degree, new_arg_list);
    return new_polynomial;
}

Polynomial Polynomial::derivate() const
{
    int new_degree = degree - 1;
    double *new_arg_list;
    new_arg_list = new double(new_degree);
    for (int i = 0; i <= new_degree; i++)
    {
        new_arg_list[i] = arg_list[i + 1] * (i + 1);
    }
    Polynomial new_polynomial(new_degree, new_arg_list);
    return new_polynomial;
}

double Cos::func(double x)const{return cos(_omega*x+_phi);}
Cos::Cos():_omega(1),_phi(0){}
Cos::Cos(double omega,double phi):_omega(omega),_phi(phi){}
void Cos::operator=(const Cos& c){_omega=c._omega;_phi=c._phi;}
void Cos::set_omega(double omega){_omega=omega;}
void Cos::set_phi(double phi){_phi=phi;}
double Cos::omega(){return _omega;}
double Cos::phi(){return _phi;}
double Cos::operator()(double x)const {return func(x);}