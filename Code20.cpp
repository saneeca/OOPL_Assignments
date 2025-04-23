#include <iostream>
using namespace std;

class AddAmount 
{
private:
    double amount;

public:
    // Constructor without parameters, amount remains $50
    AddAmount() 
{
        amount = 50.0;
    }

    // Constructor with a parameter to add a specified amount to the Piggie Bank
    AddAmount(double addAmount) 
{
        amount = 50.0 + addAmount;  // Adding the specified amount to the initial $50
    }

    void displayAmount() 
{
        cout << "Final amount in the Piggie Bank: $" << amount << endl;
    }
};

int main() 
{
    AddAmount bank1;
    bank1.displayAmount();  
    AddAmount bank2(25.0);  // Adding $25
    bank2.displayAmount();  

    return 0;
}
