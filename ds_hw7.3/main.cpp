#include <iostream>
#include <Function.h>

double gauss_integrate(Function &f, double begin, double end);

int main()
{
    double a[] = {1, 2, 3};
    Polynomial f(3, a);
    std::cout << f(0) << " " << f(1) << " " << f(2) << std::endl;
    Polynomial f_d = f.derivate();
    std::cout << f_d(0) << " " << f_d(1) << " " << f_d(2) << std::endl;
    Polynomial f_i = f.integrate();
    std::cout << f_i(0) << " " << f_i(1) << " " << f_i(2) << std::endl;
    f.set_arg(1, 0);
    std::cout << f(0) << " " << f(1) << " " << f(2) << std::endl;
    f_i = f.integrate();
    std::cout << f_i(1) - f_i(0) << " " << f_i(2) - f_i(0) << " " << f_i(3) - f_i(0) << std::endl;
    std::cout << gauss_integrate(f, 0, 1) << " " << gauss_integrate(f, 0, 2) << " " << gauss_integrate(f, 0, 3) << std::endl;
    return 0;
}