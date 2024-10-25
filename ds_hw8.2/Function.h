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