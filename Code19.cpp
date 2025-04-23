#include <iostream>
using namespace std;

class Rectangle 
{
private:
    double length, breadth;

public:
    // Constructor with no parameters (defaults to 0, 0)
    Rectangle() 
{
        length = 0;
        breadth = 0;
    }

    // Constructor with two parameters (length and breadth)
    Rectangle(double l, double b) 
{
        length = l;
        breadth = b;
    }

    // Constructor with one parameter (both length and breadth are assigned the same value)
    Rectangle(double side) 
{
        length = side;
        breadth = side;
    }

    // Function to calculate the area of the rectangle
    double calculateArea() 
{
        return length * breadth;
    }
};

int main() 
{
    Rectangle rect1;          // No parameters
    Rectangle rect2(5, 10);   // Two parameters
    Rectangle rect3(7);       // One parameter (both sides are 7)

    cout << "Area of rect1 (no parameters): " << rect1.calculateArea() << endl;
    cout << "Area of rect2 (5, 10): " << rect2.calculateArea() << endl;
    cout << "Area of rect3 (7, 7): " << rect3.calculateArea() << endl;

    return 0;
}
