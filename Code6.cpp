#include <iostream>
using namespace std;

class DB; // Forward declaration

class DM 
{
    int meters;
    int centimeters;

public:
    DM(int m = 0, int cm = 0) 
{
        meters = m;
        centimeters = cm;
    }

    void getdata() 
{
        cout << "Enter distance in meters and centimeters:\n";
        cout << "Meters: ";
        cin >> meters;
        cout << "Centimeters: ";
        cin >> centimeters;
    }

    void display() 
{
        cout << "Distance: " << meters << " meters, " << centimeters << " centimeters\n";
    }

    friend DM add(DM d1, DB d2); // Friend function
};

class DB 
{
    int feet;
    int inches;

public:
    DB(int f = 0, int in = 0) 
{
        feet = f;
        inches = in;
    }

    void getdata() 
{
        cout << "Enter distance in feet and inches:\n";
        cout << "Feet: ";
        cin >> feet;
        cout << "Inches: ";
        cin >> inches;
    }

    void display() 
{
        cout << "Distance: " << feet << " feet, " << inches << " inches\n";
    }

    friend DM add(DM d1, DB d2); // Friend function
};

// Friend function to add DM and DB, result in DM (meters & cm)
DM add(DM d1, DB d2) 
{
    // Convert DB (feet & inches) to centimeters
    float total_cm_DB = (d2.feet * 30.48) + (d2.inches * 2.54);

    // Convert DM to centimeters
    float total_cm_DM = (d1.meters * 100) + d1.centimeters;

    // Total in cm
    float sum_cm = total_cm_DM + total_cm_DB;

    // Convert back to meters and centimeters
    int result_m = (int)(sum_cm / 100);
    int result_cm = (int)(sum_cm) % 100;

    return DM(result_m, result_cm);
}
int main() 
{
    DM d1;
    DB d2;

    d1.getdata();
    d2.getdata();

    DM result = add(d1, d2); // Result in meters & centimeters

    cout << "\n--- Result in Meters & Centimeters ---\n";
    result.display();

    return 0;
}
