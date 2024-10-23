#include <iostream>
#include <List.h>
#include <Shape.h>

#define Pt Shape::Point

int main()
{
    Pt points[] = {Pt(1, 1), Pt(3, 1), Pt(4, 2), Pt(2, 2)};
    Polygon polygon(4, points);
    Polygon another_polygon;
    another_polygon.point_list().append(Pt(0, 0));
    another_polygon.point_list().append(Pt(4, 0));
    another_polygon.point_list().append(Pt(0, 3));
    Pt tri_points[]={Pt(0, 0),Pt(4, 0),Pt(0, 3)};
    Triangle triangle(tri_points);
    List<Shape*> shape_ptr_list;
    shape_ptr_list.append(&polygon);
    shape_ptr_list.append(&another_polygon);
    shape_ptr_list.append(&triangle);
    std::cout<<shape_ptr_list<<std::endl;
}