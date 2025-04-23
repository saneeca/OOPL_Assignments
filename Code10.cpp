#include <iostream>
using namespace std;

class Employee 
{
private:
    int age;
    int yearsOfService;
    double salary;

public:
    // Default constructor
    Employee() : age(0), yearsOfService(0), salary(0.0) {}

    // Parameterized constructor
    Employee(int a, int y, double s) 
{
        age = a;
        yearsOfService = y;
        salary = s;
    }

    // Accessors
    int getAge() const { return age; }
    int getYearsOfService() const { return yearsOfService; }
    double getSalary() const { return salary; }

    // Mutators
    void setAge(int a) { age = a; }
    void setYearsOfService(int y) { yearsOfService = y; }
    void setSalary(double s) { salary = s; }

    // Method to get salary in thousands, rounded manually
    int salaryInThousands() const 
{
        int thousands = static_cast<int>(salary) / 1000;
        int remainder = static_cast<int>(salary) % 1000;
        if (remainder >= 500)
            thousands += 1;
        return thousands;
    }

    // Display method
    void display() const 
{
        cout << "Age: " << age
             << ", Years of Service: " << yearsOfService
             << ", Salary: $" << salary
             << ", Rounded Salary in Thousands: $" << salaryInThousands() << "K\n";
    }
};
int main() {
    Employee emp1;
    emp1.setAge(30);
    emp1.setYearsOfService(5);
    emp1.setSalary(55000);

    Employee emp2(45, 20, 132400);

    cout << "Employee 1:\n";
    emp1.display();

    cout << "Employee 2:\n";
    emp2.display();

    return 0;
}
