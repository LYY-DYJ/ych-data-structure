# DS_HW_6.3 Shape Inheritance System #
## 实现 ##
以下是Shape.h，对Shape基类及其派生类的声明和定义，类的成员函数的定义在Shape.cpp中
### Shape.h ###
#### Shape ####
_Point_  
Shape中定义了类Point，用于Shape的派生类的点，定义在Shape中是为了防止Point变成全局可见的类，被错误调用。  
相应的声明了Point类的打印函数，这里打印函数有两种调用方法，一种在已经实现的对象后调用，可以通过默认值直接实现打印，另一种通过将流输出函数声明为友元函数，让流输出函数调用print来对ostream进行修改。   

_接口_  
area(),perimeter(),print()是纯虚函数，必须在派生类中实现。print这里统一使用json格式

_流输出函数_  
流输出函数因为不是Shape内部的函数，所以不能声明为虚函数，也就不能直接多态。类的流输出函数的多态可以通过调用print函数实现，print来实现多态。这里流输出函数会被所有派生类继承，所以任何派生类对象都可以调用，并且流输出函数的输入参数是Shape&，可以容纳任何派生类的引用
```cpp
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
```
这里定义了Circle类
```cpp
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
```
这里实现了Polygon类，Polygon类的核心就是一个作为点的容器的列表。Polygon不用实现深拷贝，因为列表类在实现时已经实现了深拷贝。
```cpp
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
```
以下分别定义了Triangle,Rectangle,Square类，按理来说他们都是Polygon，应该继承Polygon，但是这并不符合继承的原则。他们并不能实现Polygon的全部功能,比如通过point_list函数访问Polygon的点列，并能够修改，如果在Triangle中实现这个功能，外部操作就可能会把三角形变成四边形。所以这里均采用了组合，将Polygon声明为一个成员。只使用Polygon的一部分功能。同理Square将Rectangle声明为一个成员。
```cpp
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
```
Shape.cpp是对Shape.h中声明的成员函数的定义
### Shape.cpp ###
```cpp
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
```
Polygon只要调用List类，就能实现构造和复制的深拷贝，同时还保存了点的个数。计算面积用各边叉积求和，计算周长是各边平方和相加
```cpp
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
```
## 测试与结果 ##
### main.cpp ###
Shape的容器不用额外实现，利用模板将List的成员类型改成Shape*即可，然后在放进区的时候对Shape的派生类取址，因为继承关系，所以他们都可以放进去。
这里有一个麻烦的地方，我实现的List的流输出重载本来是调用每个元素的流输出，Shape中定义的点列的流输出就是对每个点流输出。虽然我实现了Shape的流输出，但是存放在List中的是Shape指针。怎么办呢？我修改了我的List，在流输出重载那里使用了模板编程，使用is_pointer，如果List存放的类型是指针，就在流输出时自动解指针，具体参看List.h

```cpp
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
```
## 结果 ##
如图所示，用json格式将两个Polygon，一个Circle,一个Triangle,一个Rectangle，一个Square都打印出来了。并统计了总面积和总周长。无论是容器，还是流输出，还是统计面积时，都将所有的派生类的引用和指针放进了Shape&和Shape*，并调用了各自的成员函数，实现了多态。
![结果](image.png)
## 附List.h ##
### List.h ###
在最后面的对流输出的重载中使用了模板编程
```cpp
#ifndef LIST_H
#define LIST_H
#include <iostream>

template <class T>
class List
{
private:
    T *listp;
    int maxsize;
    int curlen;
    void upscaling();

public:
    List();
    List(const List &l);
    List(int n, const T *);
    List &operator=(const List &l);
    ~List();
    // 判断数列是否为空
    bool is_empty() const;
    // 返回数列的长度
    int length() const;
    // 在数列末尾添加元素
    void append(const T &value);
    // 在数列中位置p插入元素
    void insert(int p, const T &value);
    // 移除数列中位置p的元素(不要使用还没写完)
    bool remove(int p);
    // 设置数列中位置p的元素
    void set_value(int p, const T &value);
    // 查询数列中位置p的元素
    bool get_value(int p, T &value) const;
    // 查找数列中的元素，如果有，返回1并通过参数返回位置，否则返回0
    bool find_value(int &p, const T &value) const;
    // 打印列表
    void print(std::ostream &os = std::cout) const;
    // 流输出重载
    template <typename TT>
    friend std::ostream &operator<<(std::ostream &os, const List<TT> &list);
};

#define INITIAL_LIST_MAXSIZE 8
template <class T>
List<T>::List()
{
    maxsize = INITIAL_LIST_MAXSIZE;
    listp = new T[maxsize];
    curlen = 0;
}
#undef INITIAL_LIST_MAXSIZE

template <class T>
List<T>::List(const List &l)
{
    maxsize = l.maxsize;
    listp = new T[maxsize];
    curlen = l.curlen;
    for (int i = 0; i < curlen; i++)
    {
        listp[i] = l.listp[i];
    }
}
template <class T>
List<T>::List(int n, const T *l)
{
    maxsize = 2 * n;
    listp = new T[maxsize];
    curlen = n;
    for (int i = 0; i < curlen; i++)
    {
        listp[i] = l[i];
    }
}

template <class T>
List<T> &List<T>::operator=(const List &l)
{
    maxsize = l.maxsize;
    listp = new T[maxsize];
    curlen = l.curlen;
    for (int i = 0; i < curlen; i++)
    {
        listp[i] = l.listp[i];
    }
    return *this;
}

template <class T>
List<T>::~List()
{
    delete[] listp;
}

template <class T>
void List<T>::upscaling()
{
    T *new_listp;
    new_listp = new T[maxsize * 2];
    for (int i = 0; i < curlen; i++)
    {
        new_listp[i] = listp[i];
    }
    delete[] listp;
    listp = new_listp;
    maxsize = 2 * maxsize;
}

template <class T>
bool List<T>::is_empty() const
{
    return (curlen == 0);
}

template <class T>
int List<T>::length() const
{
    return curlen;
}

template <class T>
void List<T>::append(const T &value)
{
    if (curlen == maxsize)
    {
        upscaling();
    }
    listp[curlen] = value;
    curlen++;
}

template <class T>
void List<T>::insert(int p, const T &value)
{
    while (p >= maxsize || curlen == maxsize)
    {
        upscaling();
    }
    if (p < curlen)
    {
        for (int i = curlen; i > p; i--)
        {
            listp[i] = listp[i - 1];
        }
        listp[p] = value;
        curlen++;
    }
    else
    {
        for (int i = curlen; i < p; i++)
        {
            listp[i] = 0;
        }
        listp[p] = value;
        curlen = p + 1;
    }
}

template <class T>
void List<T>::set_value(int p, const T &value)
{
    while (p >= maxsize || curlen == maxsize)
    {
        upscaling();
    }
    if (p < curlen)
    {
        listp[p] = value;
    }
    else
    {
        for (int i = curlen; i < p; i++)
        {
            listp[i] = 0;
        }
        listp[p] = value;
        curlen = p + 1;
    }
}

template <class T>
bool List<T>::get_value(int p, T &value) const
{
    if (p < curlen)
    {
        value = listp[p];
        return 1;
    }
    else
    {
        return 0;
    }
}

template <class T>
bool List<T>::find_value(int &p, const T &value) const
{
    int i;
    for (i = 0; i < curlen && listp[i] != value; i++)
        ;
    if (i == curlen)
        return 0;
    else
    {
        p = i;
        return 1;
    }
}

template <class T>
void List<T>::print(std::ostream &os) const
{
    os << "[";
    for (int i = 0; i < length(); i++)
    {
        if (i > 0)
        {
            os << ",";
        }
        T tmp;
        get_value(i, tmp);
        if constexpr (std::is_pointer_v<T>)
            os << *tmp;
        else
            os << tmp;
    }
    os << "]";
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const List<T> &list)
{
    list.print(os);
    return os;
}

#endif

```