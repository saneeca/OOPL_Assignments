#include <iostream>
#include <string>
using namespace std;

class RBI 
{
protected:
    double minBalance;        
    double maxWithdrawalLimit; 
    double minInterestRate;    

public:
    // Constructor to initialize RBI guidelines
    RBI() 
{
        minBalance = 500.0;  
        maxWithdrawalLimit = 50000.0; 
        minInterestRate = 4.0; 
    }

    // Function to display RBI guidelines
    void displayRBIGuidelines() 
{
        cout << "RBI Guidelines:" << endl;
        cout << "Minimum Balance: " << minBalance << " INR" << endl;
        cout << "Maximum Withdrawal Limit: " << maxWithdrawalLimit << " INR" << endl;
        cout << "Minimum Interest Rate: " << minInterestRate << "%" << endl;
    }

    // Getter functions for RBI guidelines
    double getMinBalance() { return minBalance; }
    double getMaxWithdrawalLimit() { return maxWithdrawalLimit; }
    double getMinInterestRate() { return minInterestRate; }
};

class Customer 
{
private:
    string name;
    string address;
    int accountNumber;

public:
    // Constructor to initialize customer details
    Customer(string n, string a, int accNum) : name(n), address(a), accountNumber(accNum) {}

    // Function to display customer details
    void displayCustomerDetails() 
{
        cout << "Customer Name: " << name << endl;
        cout << "Customer Address: " << address << endl;
        cout << "Account Number: " << accountNumber << endl;
    }
};

// Account Class
class Account : public RBI 
{
protected:
    double balance;
    Customer customer;

public:
    // Constructor to initialize account details
    Account(Customer c, double initialBalance) : customer(c), balance(initialBalance) {}

    // Function to deposit money into the account
    void deposit(double amount) 
{
        balance += amount;
        cout << "Deposited: " << amount << " INR" << endl;
        cout << "Updated Balance: " << balance << " INR" << endl;
    }

    // Function to withdraw money from the account
    void withdraw(double amount) 
{
        if (amount <= balance && amount <= getMaxWithdrawalLimit()) 
        {
            balance -= amount;
            cout << "Withdrawn: " << amount << " INR" << endl;
            cout << "Updated Balance: " << balance << " INR" << endl;
        } 
        else 
        {
            cout << "Withdrawal failed! Either insufficient balance or withdrawal exceeds limit." << endl;
        }
    }

    // Function to check account balance
    void checkBalance() 
{
        cout << "Current Balance: " << balance << " INR" << endl;
    }

    // Function to calculate interest
    void calculateInterest() 
{
        double interest = (balance * getMinInterestRate()) / 100;
        cout << "Interest for this year: " << interest << " INR" << endl;
    }

    // Function to display account details
    virtual void displayAccountDetails() 
{
        customer.displayCustomerDetails();
        cout << "Account Balance: " << balance << " INR" << endl;
    }
};

// Derived class SBI
class SBI : public Account 
{
public:
    // Constructor for SBI account with specific interest rate
    SBI(Customer c, double initialBalance) : Account(c, initialBalance) {}

    // Overriding the function to display SBI-specific account details
    void displayAccountDetails() override 
{
        cout << "SBI Account Details:" << endl;
        Account::displayAccountDetails();
        cout << "Interest Rate: " << 4.5 << "%" << endl;
    }
};

// Derived class ICICI
class ICICI : public Account 
{
public:
    // Constructor for ICICI account with specific interest rate
    ICICI(Customer c, double initialBalance) : Account(c, initialBalance) {}

    // Overriding the function to display ICICI-specific account details
    void displayAccountDetails() override 
{
        cout << "ICICI Account Details:" << endl;
        Account::displayAccountDetails();
        cout << "Interest Rate: " << 5.0 << "%" << endl;
    }
};

// Derived class PNB
class PNB : public Account 
{
public:
    // Constructor for PNB account with specific interest rate
    PNB(Customer c, double initialBalance) : Account(c, initialBalance) {}

    // Overriding the function to display PNB-specific account details
    void displayAccountDetails() override 
{
        cout << "PNB Account Details:" << endl;
        Account::displayAccountDetails();
        cout << "Interest Rate: " << 5.2 << "%" << endl;
    }
};

int main() 
{
    // Creating Customer objects
    Customer customer1("John Doe", "123 Main St", 101);
    Customer customer2("Jane Smith", "456 Park Ave", 102);

    // Creating Account objects for each bank
    SBI sbiAccount(customer1, 100000);
    ICICI iciciAccount(customer2, 150000);

    // Displaying the details of each account
    sbiAccount.displayAccountDetails();
    cout << "\n---------\n";
    iciciAccount.displayAccountDetails();

    // Performing transactions
    sbiAccount.deposit(5000);
    iciciAccount.withdraw(20000);
    sbiAccount.checkBalance();
    iciciAccount.checkBalance();

    // Calculating interest for each account
    sbiAccount.calculateInterest();
    iciciAccount.calculateInterest();

    return 0;
}
