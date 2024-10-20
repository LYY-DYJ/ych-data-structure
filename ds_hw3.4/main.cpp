#include <iostream>
#include "ComplexNumber.h"

int main()
{
    ComplexNumber c1(0.5, -0.5);
    ComplexNumber c2;
    ComplexNumber c3(7.0);
    std::cin >> c2;
    std::cout << "c1 = " << c1 << '\n'
              << "c2 = " << c2 << '\n'
              << "c3 = " << c3 << '\n'
              << "c1 + c2 = " << c1 + c2 << '\n'
              << "c1 - c2 = " << c1 - c2 << '\n'
              << "c1 * c2 = " << c1 * c2 << '\n'
              << "c1 / c2 = " << c1 / c2 << std::endl;
    return 0;
}
