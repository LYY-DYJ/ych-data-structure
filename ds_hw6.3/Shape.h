#include <iostream>
#include <Arr_List.h>

class Shape
{
protected:
    class Point
    {
    public:
        double _x, _y;
        Point();
        Point(double x, double y);
        // friend std::ostream &operator<<(std::ostream &os, const Point &p);
    };

public:
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
    double radius() const;
    double area() const;
    double perimeter() const;
    void print(std::ostream &os = std::cout) const;
};

class Polygon : Shape
{
};

// class Triangle : Shape
// {
// private:
//     double _base;
//     double _height;

// public:
//     Triangle();
//     Triangle(double base, double height);
//     void set_base(double base);
//     void set_height(double height);
//     double base() const;
//     double height() const;
//     double area() const;
//     double perimeter() const;
//     void print(std::ostream &os = std::cout) const;
// };

// class Rectangle : Shape
// {
// private:
//     double _width;
//     double _height;

// public:
//     Rectangle();
//     Rectangle(double width, double height);
//     void set_width(double width);
//     void set_height(double height);
//     double width() const;
//     double height() const;
//     double area() const;
//     double perimeter() const;
//     void print(std::ostream &os = std::cout) const;
// };

// class Square : Shape
// {
// private:
//     Rectangle _rect;

// public:
//     Square();
//     Square(double side);
//     void set_side(double side);
//     double area() const;
//     double perimeter() const;
//     void print(std::ostream &os = std::cout) const;
// };