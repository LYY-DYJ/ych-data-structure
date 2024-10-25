#include <iostream>
#include <List.h>

class Shape
{
public:
    class Point
    {
    public:
        double x, y;
        Point();
        Point(double x, double y);
        Point(const Point &);
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
    Circle(double radius, const Point &center);
    void set_radius(double radius);
    void set_center(const Point &center);
    double radius() const;
    Point center() const;
    double area() const;
    double perimeter() const;
    void print(std::ostream &os = std::cout) const;
};

class Polygon : public Shape
{
private:
    List<Point> _point_list;

public:
    Polygon();
    Polygon(const List<Point> &point_list);
    Polygon(int n, const Point *);
    Polygon(const Polygon &);
    Polygon &operator=(const List<Point> &point_list);
    Polygon &operator=(const Polygon &);
    List<Point> &point_list();
    List<Point> point_list() const; // this two funcion are not overload because of const
    double area() const;
    double perimeter() const;
    void print(std::ostream &os = std::cout) const;
};

class Triangle : public Shape
{
private:
    Polygon _polygon;

public:
    Triangle(const Point *);
    Triangle(double base, double height);
    double area() const;
    double perimeter() const;
    void print(std::ostream &os = std::cout) const;
};

class Rectangle : public Shape
{
private:
    Polygon _polygon;

public:
    Rectangle(double width, double height);
    List<Point> point_list() const;
    double area() const;
    double perimeter() const;
    void print(std::ostream &os = std::cout) const;
};

class Square : public Shape
{
private:
    Rectangle _rect;

public:
    Square(double side);
    List<Point> point_list() const;
    double area() const;
    double perimeter() const;
    void print(std::ostream &os = std::cout) const;
};
