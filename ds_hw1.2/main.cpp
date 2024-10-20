#include <iostream>
#include <math.h>
#include "point.cpp"

void get_point(point point);
int main()
{
    point pointlist[2];
    std::cout << "pointlist[0] test" << std::endl;
    pointlist[0].set_x(4);
    pointlist[0].set_y(3);
    get_point(pointlist[0]);
    pointlist[0].set_rou(10);
    get_point(pointlist[0]);
    pointlist[0].set_theta(M_PI_2 - pointlist[0].get_theta());
    get_point(pointlist[0]);

    std::cout << "pointlist[1] test" << std::endl;
    pointlist[1].set_x(-4);
    pointlist[1].set_y(3);
    get_point(pointlist[1]);
    pointlist[1].set_rou(10);
    get_point(pointlist[1]);
    pointlist[1].set_theta(M_PI + pointlist[1].get_theta());
    get_point(pointlist[1]);
    return 0;
}
// 测试所有point对象输出函数的函数
void get_point(point point)
{
    std::cout << "x     = " << point.get_x() << std::endl;
    std::cout << "y     = " << point.get_y() << std::endl;
    std::cout << "rou   = " << point.get_rou() << std::endl;
    std::cout << "theta = " << point.get_theta() << std::endl;
}
