#include <iostream>
#include <string>
using namespace std;

// Base class
class Staff 
{
protected:
    int code;
    string name;

public:
    void setStaffDetails(int c, string n) 
{
        code = c;
        name = n;
    }

    void showStaffDetails() const 
{
        cout << "Code: " << code << "\nName: " << name << endl;
    }
};

// Derived class - Teacher
class Teacher : public Staff 
{
    string subject;
    string publication;

public:
    void setTeacherDetails(int c, string n, string subj, string pub) 
{
        setStaffDetails(c, n);
        subject = subj;
        publication = pub;
    }

    void showTeacherDetails() const 
{
        showStaffDetails();
        cout << "Subject: " << subject << "\nPublication: " << publication << endl;
    }
};

// Derived class - Officer
class Officer : public Staff 
{
    string grade;

public:
    void setOfficerDetails(int c, string n, string g) 
{
        setStaffDetails(c, n);
        grade = g;
    }

    void showOfficerDetails() const 
{
        showStaffDetails();
        cout << "Grade: " << grade << endl;
    }
};

// Derived class - Typist
class Typist : public Staff 
{
protected:
    int speed;

public:
    void setTypistDetails(int c, string n, int s) 
{
        setStaffDetails(c, n);
        speed = s;
    }

    void showTypistDetails() const 
{
        showStaffDetails();
        cout << "Typing Speed: " << speed << " wpm" << endl;
    }
};

// Derived from Typist - Regular
class Regular : public Typist 
{
public:
    void setRegularDetails(int c, string n, int s) 
{
        setTypistDetails(c, n, s);
    }

    void showRegularDetails() const 
{
        showTypistDetails();
    }
};

// Derived from Typist - Casual
class Casual : public Typist 
{
    float dailyWages;

public:
    void setCasualDetails(int c, string n, int s, float wage) 
{
        setTypistDetails(c, n, s);
        dailyWages = wage;
    }

    void showCasualDetails() const 
{
        showTypistDetails();
        cout << "Daily Wages: $" << dailyWages << endl;
    }
};

int main() 
{
    Teacher t;
    Officer o;
    Regular r;
    Casual c;

    // Sample data
    t.setTeacherDetails(101, "Alice", "Mathematics", "Oxford");
    o.setOfficerDetails(102, "Bob", "A");
    r.setRegularDetails(103, "Charlie", 50);
    c.setCasualDetails(104, "Diana", 45, 150.75);

    cout << "\n--- Teacher ---\n";
    t.showTeacherDetails();

    cout << "\n--- Officer ---\n";
    o.showOfficerDetails();

    cout << "\n--- Regular Typist ---\n";
    r.showRegularDetails();

    cout << "\n--- Casual Typist ---\n";
    c.showCasualDetails();

    return 0;
}
