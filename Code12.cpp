#include <iostream>
using namespace std;

// Base class Fruit
class Fruit 
{
protected:
    int numFruits;  

public:
    // Constructor to initialize the number of fruits
    Fruit(int num) : numFruits(num) {}

    // Virtual function to print the number of fruits (can be overridden)
    virtual void printCount() 
{
        cout << "Total number of fruits: " << numFruits << endl;
    }

    // Virtual function to get the total number of fruits (can be overridden)
    virtual int getTotalFruits() 
{
        return numFruits;
    }
};

// Derived class Apples
class Apples : public Fruit 
{
public:
    // Constructor to initialize the number of apples
    Apples(int num) : Fruit(num) {}

    // Override to print the number of apples
    void printCount() override 
{
        cout << "Number of apples: " << numFruits << endl;
    }

    // Override to get the total number of apples
    int getTotalFruits() override 
{
        return numFruits;
    }
};

// Derived class Mangoes
class Mangoes : public Fruit 
{
public:
    // Constructor to initialize the number of mangoes
    Mangoes(int num) : Fruit(num) {}

    // Override to print the number of mangoes
    void printCount() override 
{
        cout << "Number of mangoes: " << numFruits << endl;
    }

    // Override to get the total number of mangoes
    int getTotalFruits() override 
{
        return numFruits;
    }
};

int main() 
{
    int numApples, numMangoes;

    cout << "Enter the number of apples: ";
    cin >> numApples;
    cout << "Enter the number of mangoes: ";
    cin >> numMangoes;

    // Create objects of Apples and Mangoes
    Apples apples(numApples);
    Mangoes mangoes(numMangoes);

    // Display the number of apples and mangoes
    apples.printCount();
    mangoes.printCount();

    // Calculate and display the total number of fruits in the basket
    int totalFruits = apples.getTotalFruits() + mangoes.getTotalFruits();
    cout << "Total number of fruits in the basket: " << totalFruits << endl;

    return 0;
}
