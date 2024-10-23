#include <Shape.h>
#include <math.h>
#include <iostream>

Shape::Point::Point():_x(0),_y(0){}
Shape::Point::Point(double x,double y):_x(x),_y(y){}
std::ostream &operator<<(std::ostream &os, const Shape::Point &p)
{
    os<<"("<<p._x<<","<<p._y<<")";
    return os;
}

std::ostream &operator<<(std::ostream &os, const Shape &s)
{
    s.print(os);
    return os;
}

Circle::Circle() : _radius(0) {}
Circle::Circle(double r) : _radius(r) {}
void Circle::set_radius(double r) { _radius = r; }
double Circle::radius() const { return _radius; }
double Circle::area() const { return M_PI * _radius * _radius; }
double Circle::perimeter() const { return 2 * M_PI * _radius; }
void Circle::print(std::ostream &os) const
{
    os << "{type:Circle,radius:" << _radius << "}";
}

// Triangle::Triangle() : _base(0), _height(0) {}
// Triangle::Triangle(double b, double h) : _base(b), _height(h) {}
// void Triangle::set_base(double b){_base=b;}
// void Triangle::set_height(double h){_height=h;}
// double Triangle::base()const{return _base;}
// double Triangle::height()const{return _height;}
// double Triangle::area()const{return _base*_height/2;}
// double Triangle::perimeter()const{}


// Rectangle::Rectangle() : _width(0), _height(0) {}
// Rectangle::Rectangle(double w, double h) : _width(w), _height(h) {};
// void Rectangle::set_width(double w) { _width = w; }
// void Rectangle::set_height(double h) { _height = h; }
// double Rectangle::width() const { return _width; }
// double Rectangle::height() const { return _height; }
// double Rectangle::area() const { return _width * _height; }
// double Rectangle::perimeter() const{return 2 * (_width + _height);}
// void Rectangle::print(std::ostream &os) const
// {
//     os << "{type:Rectangle,width:" << _width << ",height:" << _height << "}";
// }

// Square::Square(){Rectangle rect(0, 0);}
// Square::Square(double side){Rectangle rect(side, side);}
// void Square::set_side(double side)
// {
//     _rect.set_width(side);
//     _rect.set_height(side);
// }
// double Square::area() const{return _rect.area();}
// double Square::perimeter() const{return _rect.perimeter();}
// void Square::print(std::ostream &os) const
// {
//     os << "{type:Square,side:" << _rect.width() << "}";
// }
