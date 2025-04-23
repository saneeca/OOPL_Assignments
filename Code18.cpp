#include <iostream>
#include <string>
using namespace std;

class Student 
{
private:
    string name;  

public:
    // Constructor that takes an optional string parameter
    // If no name is provided, it defaults to "Unknown"
    Student(string n = "Unknown") 
{
        name = n;
    }

    // Function to display the student's name
    void displayName() 
{
        cout << "Student Name: " << name << endl;
    }
};

int main() 
{
    Student student1("Rama");  
    Student student2;              
    // Display the names of the students
    student1.displayName();
    student2.displayName();

    return 0;
}
