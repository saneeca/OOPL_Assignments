#include <iostream>
using namespace std;

class Mammals 
{
public:
    void mammalInfo() 
{
        cout << "I am a mammal" << endl;
    }
};

class MarineAnimals 
{
public:
    void marineAnimalInfo() 
{
        cout << "I am a marine animal" << endl;
    }
};

class BlueWhale : public Mammals, public MarineAnimals 
{
public:
    void blueWhaleInfo() 
{
        cout << "I belong to both the categories: Mammals as well as Marine Animals" << endl;
    }
};

int main() 
{
    // Object of Mammals
    Mammals mammalObj;
    cout << "1. Mammals object:" << endl;
    mammalObj.mammalInfo();

    // Object of MarineAnimals
    MarineAnimals marineObj;
    cout << "\n2. MarineAnimals object:" << endl;
    marineObj.marineAnimalInfo();

    // Object of BlueWhale
    BlueWhale blueWhaleObj;
    cout << "\n3. BlueWhale object (its own function):" << endl;
    blueWhaleObj.blueWhaleInfo();

    // Accessing parent class functions from BlueWhale object
    cout << "\n4. BlueWhale object calling parent class functions:" << endl;
    blueWhaleObj.mammalInfo();
    blueWhaleObj.marineAnimalInfo();

    return 0;
}
