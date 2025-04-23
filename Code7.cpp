#include <iostream>
using namespace std;

class SimpleCircle 
{
private:
    int itsRadius;

public:
    // Default constructor
    SimpleCircle();
    // Parameterized constructor
    SimpleCircle(int radius);
    // Copy constructor
    SimpleCircle(const SimpleCircle& other);
    // Destructor
    ~SimpleCircle();

    int getRadius() const;
    void setRadius(int radius);

    SimpleCircle& operator++();    // Prefix
    SimpleCircle operator++(int);  // Postfix
    SimpleCircle& operator=(const SimpleCircle& other);
};

// Default constructor
SimpleCircle::SimpleCircle() 
{
    itsRadius = 5;
}

// Parameterized constructor
SimpleCircle::SimpleCircle(int radius) 
{
    itsRadius = radius;
}

// Copy constructor
SimpleCircle::SimpleCircle(const SimpleCircle& other) 
{
    itsRadius = other.itsRadius;
}

// Destructor
SimpleCircle::~SimpleCircle() 
{
    // No dynamic memory, nothing to release
}

// Accessors
int SimpleCircle::getRadius() const 
{
    return itsRadius;
}

void SimpleCircle::setRadius(int radius) 
{
    itsRadius = radius;
}

// Prefix increment
SimpleCircle& SimpleCircle::operator++() 
{
    ++itsRadius;
    return *this;
}

// Postfix increment
SimpleCircle SimpleCircle::operator++(int) 
{
    SimpleCircle temp = *this;
    itsRadius++;
    return temp;
}

// Assignment operator
SimpleCircle& SimpleCircle::operator=(const SimpleCircle& other) 
{
    if (this != &other) {
        itsRadius = other.itsRadius;
    }
    return *this;
}

// Main function
int main() 
{
    SimpleCircle c1;             // Uses default constructor (radius = 5)
    SimpleCircle c2(9);          // Uses parameterized constructor (radius = 9)

    ++c1;                        // Prefix increment
    c2++;                        // Postfix increment

    cout << "Circle 1 radius: " << c1.getRadius() << endl;  // Should be 6
    cout << "Circle 2 radius: " << c2.getRadius() << endl;  // Should be 10

    c1 = c2;  // Assignment
    cout << "After assignment, Circle 1 radius: " << c1.getRadius() << endl;  // Should be 10

    return 0;
}
