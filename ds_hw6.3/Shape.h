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
        Point(const Point&);
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
    Circle(double radius,const Point& center);
    void set_radius(double radius);
    void set_center(const Point& center);
    double radius() const;
    Point center() const;
    double area() const;
    double perimeter() const;
    void print(std::ostream &os = std::cout) const;
};

class Polygon :public Shape
{
protected:
    List<Point> _point_list;

public:
    Polygon();
    Polygon(const List<Point>& point_list);
    Polygon(int n,const Point*);
    Polygon(const Polygon&);
    Polygon& operator=(const List<Point>& point_list);
    Polygon& operator=(const Polygon&);
    List<Point>& point_list();
    double area() const;
    double perimeter() const;
    void print(std::ostream &os=std::cout) const;
};

class Triangle:public Polygon
{
public:
    Triangle(const Point*);
    void print(std::ostream &os=std::cout) const;
};