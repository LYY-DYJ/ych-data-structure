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
    Circle circle(1);
    Triangle triangle(4,3);
    Rectangle rectangle(5,3);
    Square square(1);
    List<Shape *> shape_ptr_list;
    shape_ptr_list.append(&polygon);
    shape_ptr_list.append(&another_polygon);
    shape_ptr_list.append(&circle);
    shape_ptr_list.append(&triangle);
    shape_ptr_list.append(&rectangle);
    shape_ptr_list.append(&square);
    std::cout << shape_ptr_list << std::endl;
    double area_sum=0,perimeter_sum=0;
    for (int i = 0; i < shape_ptr_list.length(); i++)
    {
        Shape* tmp;
        shape_ptr_list.get_value(i,tmp);
        area_sum+=tmp->area();
        perimeter_sum+=tmp->perimeter();
    }
    std::cout<<"area_sum:"<<area_sum<<",perimeter_sum:"<<perimeter_sum<<std::endl;
}