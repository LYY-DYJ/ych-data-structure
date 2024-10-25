#include <Shape.h>
#include <math.h>
#include <iostream>
// Point
Shape::Point::Point() : x(0), y(0) {}
Shape::Point::Point(double x, double y) : x(x), y(y) {}
Shape::Point::Point(const Point &p) : x(p.x), y(p.y) {}
void Shape::Point::print(std::ostream &os) const
{
    os << "(" << x << "," << y << ")";
}
std::ostream &operator<<(std::ostream &os, const Shape::Point &p)
{
    p.print(os);
    return os;
}
// Point

// Shape
std::ostream &operator<<(std::ostream &os, const Shape &s)
{
    s.print(os);
    return os;
}
// Shape

// Circle
Circle::Circle() : _radius(0) {}
Circle::Circle(double r) : _radius(r), _center(Point(0, 0)) {}
Circle::Circle(double r, const Point &c) : _radius(r), _center(c) {}
void Circle::set_radius(double r) { _radius = r; }
void Circle::set_center(const Point &c) { _center = c; }
double Circle::radius() const { return _radius; }
Shape::Point Circle::center() const { return _center; }
double Circle::area() const { return M_PI * _radius * _radius; }
double Circle::perimeter() const { return 2 * M_PI * _radius; }
void Circle::print(std::ostream &os) const
{
    os << "{\"type\":\"Circle\",\"radius\":" << _radius << ",\"center\":" << _center << "}";
}
// Circle

// Polygon
Polygon::Polygon():_point_list(){}
Polygon::Polygon(const List<Point> &point_list) : _point_list(point_list) {}
Polygon::Polygon(int n, const Point *p) : _point_list(n, p) {}
Polygon::Polygon(const Polygon &p) : _point_list(p._point_list) {}
Polygon &Polygon::operator=(const List<Point> &point_list)
{
    _point_list = point_list;
    return *this;
}
Polygon &Polygon::operator=(const Polygon &p)
{
    _point_list = p._point_list;
    return *this;
}
List<Shape::Point> &Polygon::point_list() { return _point_list; }
List<Shape::Point> Polygon::point_list() const { return _point_list; }
double Polygon::area() const
{
    double area=0;
    Point p1, p2;
    int i;
    for (i = 0; i < _point_list.length() - 1; i++)
    {
        _point_list.get_value(i, p1);
        _point_list.get_value(i + 1, p2);
        area += p1.x * p2.y - p1.y * p2.x;
    }
    _point_list.get_value(i, p1);
    _point_list.get_value(0, p2);
    area += p1.x * p2.y - p1.y * p2.x;
    area /= 2;
    return area > 0 ? area : -area;
}
double Polygon::perimeter() const
{
    double perimeter=0;
    Point p1, p2, v;
    int i;
    for (i = 0; i < _point_list.length() - 1; i++)
    {
        _point_list.get_value(i, p1);
        _point_list.get_value(i + 1, p2);
        v = Point(p1.x - p2.x, p1.y - p2.y);
        perimeter += sqrt(v.x * v.x + v.y * v.y);
    }
    _point_list.get_value(i, p1);
    _point_list.get_value(0, p2);
    v = Point(p1.x - p2.x, p1.y - p2.y);
    perimeter += sqrt(v.x * v.x + v.y * v.y);
    return perimeter;
}
void Polygon::print(std::ostream& os) const
{
    os<<"{\"type\":\"Polygon\",\"pointlist\":"<<_point_list<<"}";
}
// Polygon


//Triangle
Triangle::Triangle(const Point* pt_list):_polygon(3,pt_list){}
Triangle::Triangle(double base,double height)
{
    Point pt_list[]={Point(0,0),Point(base,0),Point(0,height)};
    _polygon=Polygon(3,pt_list);
}
double Triangle::area()const{return _polygon.area();} 
double Triangle::perimeter()const{return _polygon.perimeter();} 
void Triangle::print(std::ostream& os) const
{
    
    os<<"{\"type\":\"Triangle\",\"point_list\":"<<_polygon.point_list()<<"}";
}
//Triangle

//Rectangle
Rectangle::Rectangle(double width, double height)
{
    Point pt_list[]={Point(0,0),Point(width,0),Point(width,height),Point(0,height)};
    _polygon=Polygon(4,pt_list);
}
List<Shape::Point> Rectangle::point_list() const { return _polygon.point_list(); }
double Rectangle::area()const{return _polygon.area();} 
double Rectangle::perimeter()const{return _polygon.perimeter();} 
void Rectangle::print(std::ostream& os) const
{
    
    os<<"{\"type\":\"Rectangle\",\"point_list\":"<<_polygon.point_list()<<"}";
}
//Rectangle

//Square
Square::Square(double side):_rect(side,side){}
List<Shape::Point> Square::point_list() const { return _rect.point_list(); }
double Square::area()const{return _rect.area();}
double Square::perimeter()const{return _rect.perimeter();}
void Square::print(std::ostream& os) const
{
    os<<"{\"type\":\"Square\",\"point_list\":"<<_rect.point_list()<<"}";
}
//Square