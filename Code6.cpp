#include <iostream>
using namespace std;

class DB;  // Forward declaration for the friend function

class DM 
{
private:
    int meters;
    int centimeters;

public:
    // Constructor to initialize DM object
    DM(int m = 0, int cm = 0) : meters(m), centimeters(cm) {}

    // Friend function to add DM and DB objects
    friend DM addDistance(const DM& dm, const DB& db);

    // Function to display DM object in meters and centimeters
    void display() 
{
        cout << meters << " meters " << centimeters << " centimeters" << endl;
    }
};

class DB 
{
private:
    int feet;
    int inches;

public:
    // Constructor to initialize DB object
    DB(int ft = 0, int in = 0) : feet(ft), inches(in) {}

    // Friend function to add DM and DB objects
    friend DM addDistance(const DM& dm, const DB& db);

    // Function to display DB object in feet and inches
    void display() 
{
        cout << feet << " feet " << inches << " inches" << endl;
    }
};

// Friend function to add DM and DB distances
DM addDistance(const DM& dm, const DB& db) 
{
    // Convert DB (feet and inches) to meters and centimeters
    int totalInches = db.feet * 12 + db.inches;
    int totalCentimeters = totalInches * 2.54;

    // Add the distances in DM (meters and centimeters) and DB (converted to centimeters)
    int totalCentimetersFinal = dm.meters * 100 + dm.centimeters + totalCentimeters;
    
    // Convert back to meters and centimeters
    int meters = totalCentimetersFinal / 100;
    int centimeters = totalCentimetersFinal % 100;

    // Create and return a new DM object with the result
    return DM(meters, centimeters);
}

int main() {
    int meters, centimeters, feet, inches;

    cout << "Enter distance in DM (meters and centimeters):" << endl;
    cout << "Meters: ";
    cin >> meters;
    cout << "Centimeters: ";
    cin >> centimeters;
    DM dm(meters, centimeters);

    cout << "Enter distance in DB (feet and inches):" << endl;
    cout << "Feet: ";
    cin >> feet;
    cout << "Inches: ";
    cin >> inches;
    DB db(feet, inches);

    // Adding DM and DB distances
    DM result = addDistance(dm, db);

    // Display the result in DM format (meters and centimeters)
    cout << "Resulting distance in DM format (meters and centimeters): ";
    result.display();

    // Display the result in DB format (feet and inches)
    int totalCentimetersResult = result.meters * 100 + result.centimeters;
    int totalInchesResult = totalCentimetersResult / 2.54;
    int resultFeet = totalInchesResult / 12;
    int resultInches = totalInchesResult % 12;

    cout << "Resulting distance in DB format (feet and inches): ";
    cout << resultFeet << " feet " << resultInches << " inches" << endl;

    return 0;
}
