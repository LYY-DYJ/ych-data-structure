#include <iostream>
#include <Arr_List.h>

class Shape
{
public:
    class Point
    {
    public:
        double x, y;
        Point();
        Point(double x, double y);
        void print(std::ostream &os = std::cout) const;
    };
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void print(std::ostream &os) const = 0;
    friend std::ostream &operator<<(std::ostream &os, const Shape &s);
    friend std::ostream &operator<<(std::ostream &os, const Point &p);
};

class Circle : public Shape
{
private:
    double _radius;
    Point _center;

public:
    Circle();
    Circle(double radius);
    Circle(double radius, Point center);
    void set_radius(double radius);
    void set_center(Point center);
    double radius() const;
    Point center() const;
    double area() const;
    double perimeter() const;
    void print(std::ostream &os = std::cout) const;
};

class Polygon : Shape
{

public:
    Polygon(int point_n, );
};
