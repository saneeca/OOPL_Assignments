#include <iostream>
#include <string>
using namespace std;

// Base class
class Person 
{
protected:
    string name;
    int code;

public:
    void setPersonDetails(string n, int c) 
{
        name = n;
        code = c;
    }

    void showPersonDetails() const 
{
        cout << "Name: " << name << "\nCode: " << code << endl;
    }
};

// Derived from Person
class Account : virtual public Person 
{
protected:
    float pay;

public:
    void setAccountDetails(float p) 
{
        pay = p;
    }

    void showAccountDetails() const 
{
        cout << "Pay: $" << pay << endl;
    }
};

// Derived from Person
class Admin : virtual public Person 
{
protected:
    int experience;

public:
    void setAdminDetails(int exp) 
{
        experience = exp;
    }

    void showAdminDetails() const 
{
        cout << "Experience: " << experience << " years" << endl;
    }
};

// Derived from Account and Admin (Hybrid Inheritance)
class Master : public Account, public Admin 
{
public:
    void setMasterDetails(string n, int c, float p, int exp) 
{
        setPersonDetails(n, c);   // From Person
        setAccountDetails(p);     // From Account
        setAdminDetails(exp);     // From Admin
    }

    void showMasterDetails() const 
{
        showPersonDetails();
        showAccountDetails();
        showAdminDetails();
    }
};

int main() 
{
    Master m;
    string name;
    int code, experience;
    float pay;

    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter code: ";
    cin >> code;
    cout << "Enter pay: ";
    cin >> pay;
    cout << "Enter experience: ";
    cin >> experience;

    m.setMasterDetails(name, code, pay, experience);
    cout << "\n--- Master Details ---\n";
    m.showMasterDetails();

    return 0;
}
