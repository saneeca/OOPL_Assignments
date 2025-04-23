#include <iostream>
using namespace std;

// Base class Shape
class Shape 
{
public:
    virtual void print() 
{
        cout << "This is a shape" << endl;
    }
};

// Derived class Polygon inheriting Shape
class Polygon : public Shape '
{
public:
    void print() override 
{
        cout << "Polygon is a shape" << endl;
    }
};

// Derived class Rectangle inheriting Polygon
class Rectangle : public Polygon 
{
public
    void print() override 
{
        cout << "Rectangle is a polygon" << endl;
    }
};

// Derived class Triangle inheriting Polygon
class Triangle : public Polygon 
{
public:
    void print() override 
{
        cout << "Triangle is a polygon" << endl;
    }
};

// Derived class Square inheriting Rectangle
class Square : public Rectangle 
{
public:
    void print() override 
{
        cout << "Square is a rectangle" << endl;
    }
};

int main()
{
    Shape shape;
    Polygon polygon;
    Rectangle rectangle;
    Triangle triangle;
    Square square;

    // Call print function on each object
    cout << "Shape object: ";
    shape.print();

    cout << "Polygon object: ";
    polygon.print();

    cout << "Rectangle object: ";
    rectangle.print();

    cout << "Triangle object: ";
    triangle.print();

    cout << "Square object: ";
    square.print();

    return 0;
}
