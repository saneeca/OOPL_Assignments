#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Base class Marks
class Marks 
{
protected:
    static int rollNoCounter; // Static counter for generating roll numbers
    int rollNo;               // Roll number of the student
    string name;              // Name of the student

public:
    Marks(string studentName) 
{
        rollNo = ++rollNoCounter;  // Automatically generate roll number
        name = studentName;
    }

    // Virtual function to be overridden in derived classes
    virtual void getMarks() = 0;

    // Virtual function to return total marks, overridden in derived classes
    virtual int totalMarks() = 0;

    // Function to display student details
    void displayDetails() 
{
        cout << "Roll No: " << rollNo << ", Name: " << name << endl;
    }
};

// Initialize static roll number counter
int Marks::rollNoCounter = 0;

// Derived class for Physics
class Physics : public Marks 
{
protected:
    int physicsMarks;

public:
    Physics(string studentName, int marks) : Marks(studentName) 
{
        physicsMarks = marks;
    }

    void getMarks() override 
{
        cout << "Enter Physics marks for " << name << ": ";
        cin >> physicsMarks;
    }

    int totalMarks() override 
{
        return physicsMarks;
    }
};

// Derived class for Chemistry
class Chemistry : public Marks 
{
protected:
    int chemistryMarks;

public:
    Chemistry(string studentName, int marks) : Marks(studentName) 
{
        chemistryMarks = marks;
    }

    void getMarks() override 
{
        cout << "Enter Chemistry marks for " << name << ": ";
        cin >> chemistryMarks;
    }

    int totalMarks() override 
{
        return chemistryMarks;
    }
};

// Derived class for Mathematics
class Mathematics : public Marks 
{
protected:
    int mathMarks;

public:
    Mathematics(string studentName, int marks) : Marks(studentName) 
{
        mathMarks = marks;
    }

    void getMarks() override 
{
        cout << "Enter Mathematics marks for " << name << ": ";
        cin >> mathMarks;
    }

    int totalMarks() override 
{
        return mathMarks;
    }
};

// Class to handle class of students
class Class 
{
private:
    vector<Marks*> students;

public:
    void addStudent(string name, int physicsMarks, int chemistryMarks, int mathMarks) 
{
        Physics* studentPhysics = new Physics(name, physicsMarks);
        Chemistry* studentChemistry = new Chemistry(name, chemistryMarks);
        Mathematics* studentMathematics = new Mathematics(name, mathMarks);

        students.push_back(studentPhysics);
        students.push_back(studentChemistry);
        students.push_back(studentMathematics);
    }

    // Function to display all students and calculate total and average marks
    void displayAndCalculate() 
{
        int totalMarksClass = 0;
        for (auto& student : students) 
        {
            student->displayDetails();
            totalMarksClass += student->totalMarks();
        }

        cout << "Total marks of the class: " << totalMarksClass << endl;
        cout << "Average marks of the class: " << (double)totalMarksClass / students.size() << endl;
    }
};

int main() 
{
    int numStudents;
    cout << "Enter the number of students in the class: ";
    cin >> numStudents;

    Class studentClass;

    for (int i = 0; i < numStudents; ++i) 
    {
        string studentName;
        int physicsMarks, chemistryMarks, mathMarks;

        cout << "Enter name of student " << i + 1 << ": ";
        cin >> studentName;

        cout << "Enter marks for Physics: ";
        cin >> physicsMarks;

        cout << "Enter marks for Chemistry: ";
        cin >> chemistryMarks;

        cout << "Enter marks for Mathematics: ";
        cin >> mathMarks;

        studentClass.addStudent(studentName, physicsMarks, chemistryMarks, mathMarks);
    }

    // Display all students and calculate total and average marks
    studentClass.displayAndCalculate();

    return 0;
}
