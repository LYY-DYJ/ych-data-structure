#include<iostream>
#include<Shape.h>

#define P Shape::Point

int main()
{
    Circle c(1.0,P(1,2));
    std::cout<<c<<std::endl;
    std::cout<<c.radius()<<" "<<c.center()<<std::endl;
    std::cout<<c.area()<<" "<<c.perimeter()<<std::endl;
    return 0;
}
