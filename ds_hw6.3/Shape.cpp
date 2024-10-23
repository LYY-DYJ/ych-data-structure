#include <Shape.h>
#include <math.h>
#include <iostream>
//Point
Shape::Point::Point() : x(0), y(0) {}
Shape::Point::Point(double x, double y) : x(x), y(y) {}
Shape::Point::Point(const Point& p) : x(p.x), y(p.y) {}
void Shape::Point::print(std::ostream &os) const
{
    os << "(" << x << "," << y << ")";
}
std::ostream &operator<<(std::ostream &os, const Shape::Point &p)
{
    p.print(os);
    return os;
}
//Point

//Shape
std::ostream &operator<<(std::ostream &os, const Shape &s)
{
    s.print(os);
    return os;
}
//Shape

//Circle
Circle::Circle() : _radius(0) {}
Circle::Circle(double r) : _radius(r), _center(Point(0, 0)) {}
Circle::Circle(double r,const Point& c) : _radius(r), _center(c) {}
void Circle::set_radius(double r) { _radius = r; }
void Circle::set_center(const Point& c) { _center = c; }
double Circle::radius() const { return _radius; }
Shape::Point Circle::center() const {return _center;}
double Circle::area() const { return M_PI * _radius * _radius; }
double Circle::perimeter() const { return 2 * M_PI * _radius; }
void Circle::print(std::ostream &os) const
{
    os << "{type:Circle,radius:" << _radius << ",center:" << _center << "}";
}
//Circle

//Polygon
Polygon::Polygon(const List<Point>& point_list):_point_list(point_list){}
Polygon::Polygon(const Polygon& p):_point_list(p._point_list){}

//Polygon
