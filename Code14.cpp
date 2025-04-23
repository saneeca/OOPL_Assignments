#include <iostream>
#include <string>
using namespace std;

// Base class: Vehicle
class Vehicle 
{
protected:
    float mileage;
    float price;
public:
    void setVehicleInfo(float m, float p) 
{
        mileage = m;
        price = p;
    }

    void displayVehicleInfo() 
{
        cout << "Mileage: " << mileage << " km/l" << endl;
        cout << "Price: $" << price << endl;
    }
};

// Derived class: Car
class Car : public Vehicle 
{
protected:
    float ownershipCost;
    int warranty;
    int seatingCapacity;
    string fuelType;
public:
    void setCarInfo(float cost, int warr, int seat, string fuel) 
{
        ownershipCost = cost;
        warranty = warr;
        seatingCapacity = seat;
        fuelType = fuel;
    }

    void displayCarInfo() 
{
        cout << "Ownership Cost: $" << ownershipCost << endl;
        cout << "Warranty: " << warranty << " years" << endl;
        cout << "Seating Capacity: " << seatingCapacity << endl;
        cout << "Fuel Type: " << fuelType << endl;
        displayVehicleInfo();
    }
};

// Derived class: Bike
class Bike : public Vehicle 
{
protected:
    int cylinders;
    int gears;
    string coolingType;
    string wheelType;
    float tankSize;
public:
    void setBikeInfo(int cyl, int gr, string cooling, string wheel, float tank) 
{
        cylinders = cyl;
        gears = gr;
        coolingType = cooling;
        wheelType = wheel;
        tankSize = tank;
    }

    void displayBikeInfo() 
{
        cout << "Number of Cylinders: " << cylinders << endl;
        cout << "Number of Gears: " << gears << endl;
        cout << "Cooling Type: " << coolingType << endl;
        cout << "Wheel Type: " << wheelType << endl;
        cout << "Fuel Tank Size: " << tankSize << " inches" << endl;
        displayVehicleInfo();
    }
};

// Subclass: Audi
class Audi : public Car 
{
private:
    string modelType;
public:
    void setAudiInfo(string model, float cost, int warr, int seat, string fuel, float m, float p) 
{
        modelType = model;
        setCarInfo(cost, warr, seat, fuel);
        setVehicleInfo(m, p);
    }

    void displayAudiInfo() 
{
        cout << "\n--- Audi Car Information ---" << endl;
        cout << "Model Type: " << modelType << endl;
        displayCarInfo();
    }
};

// Subclass: Ford
class Ford : public Car 
{
private:
    string modelType;
public:
    void setFordInfo(string model, float cost, int warr, int seat, string fuel, float m, float p) 
{
        modelType = model;
        setCarInfo(cost, warr, seat, fuel);
        setVehicleInfo(m, p);
    }

    void displayFordInfo() 
{
        cout << "\n--- Ford Car Information ---" << endl;
        cout << "Model Type: " << modelType << endl;
        displayCarInfo();
    }
};

// Subclass: Bajaj
class Bajaj : public Bike {

private:
    string makeType;
public:
    void setBajajInfo(string make, int cyl, int gr, string cooling, string wheel, float tank, float m, float p) 
{
        makeType = make;
        setBikeInfo(cyl, gr, cooling, wheel, tank);
        setVehicleInfo(m, p);
    }

    void displayBajajInfo() 
{
        cout << "\n--- Bajaj Bike Information ---" << endl;
        cout << "Make Type: " << makeType << endl;
        displayBikeInfo();
    }
};

// Subclass: TVS
class TVS : public Bike 
{
private:
    string makeType;
public:
    void setTVSInfo(string make, int cyl, int gr, string cooling, string wheel, float tank, float m, float p) 
{
        makeType = make;
        setBikeInfo(cyl, gr, cooling, wheel, tank);
        setVehicleInfo(m, p);
    }

    void displayTVSInfo() 
{
        cout << "\n--- TVS Bike Information ---" << endl;
        cout << "Make Type: " << makeType << endl;
        displayBikeInfo();
    }
};

// Main Function
int main() 
{
    // Audi
    Audi audiCar;
    audiCar.setAudiInfo("A4", 15000, 5, 5, "Petrol", 18.5, 45000);
    audiCar.displayAudiInfo();

    // Ford
    Ford fordCar;
    fordCar.setFordInfo("Mustang", 20000, 4, 4, "Diesel", 15.0, 55000);
    fordCar.displayFordInfo();

    // Bajaj
    Bajaj bajajBike;
    bajajBike.setBajajInfo("Pulsar", 2, 5, "Air", "Alloys", 13.0, 40.0, 95000);
    bajajBike.displayBajajInfo();

    // TVS
    TVS tvsBike;
    tvsBike.setTVSInfo("Apache", 1, 4, "Oil", "Spokes", 12.0, 45.0, 85000);
    tvsBike.displayTVSInfo();

    return 0;
}
