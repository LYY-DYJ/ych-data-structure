#include<iostream>
#include<Shape.h>

#define Pt Shape::Point

int main()
{
    Pt points[]={Pt(1,1),Pt(3,1),Pt(4,2),Pt(2,2)};
    Polygon polygon(4,points);
    Polygon another_polygon;
    another_polygon.point_list().append(Pt(0,0));
    another_polygon.point_list().append(Pt(4,0));
    another_polygon.point_list().append(Pt(0,3));
    std::cout<<polygon<<" "<<polygon.area()<<" "<<polygon.perimeter()<<std::endl;
    std::cout<<another_polygon<<" "<<another_polygon.area()<<" "<<another_polygon.perimeter()<<std::endl;
}