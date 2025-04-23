#include <iostream>
#include <string>
using namespace std;

class Account 
{
protected:
    string customerName;
    int accountNumber;
    string accountType;
    double balance;

public:
    void initialize(string name, int accNo, string type) 
{
        customerName = name;
        accountNumber = accNo;
        accountType = type;
        balance = 0.0;
    }

    void deposit(double amount) 
{
        balance += amount;
        cout << "Amount deposited: " << amount << endl;
    }

    void displayBalance() const 
{
        cout << "Current balance: " << balance << endl;
    }

    virtual void withdraw(double amount) = 0; 
};

class sav_acc : public Account 
{
public:
    void computeAndDepositInterest(double rate, int time) 
{
        double amount = balance;
        for (int i = 0; i < time; ++i) 
        {
            amount += amount * (rate / 100);
        }
        double interest = amount - balance;
        balance = amount;
        cout << "Interest of " << interest << " added to account." << endl;
    }

    void withdraw(double amount) override 
{
        if (amount <= balance) 
        {
            balance -= amount;
            cout << "Amount withdrawn: " << amount << endl;
        } else {
            cout << "Insufficient balance." << endl;
        }
    }
};

class cur_acc : public Account 
{
    const double minBalance = 500.0;
    const double serviceCharge = 50.0;

public:
    void checkAndImposePenalty() 
{
        if (balance < minBalance) {
            balance -= serviceCharge;
            cout << "Balance below minimum. Service charge of " << serviceCharge << " imposed." << endl;
        } else {
            cout << "Balance is above minimum. No penalty imposed." << endl;
        }
    }

    void withdraw(double amount) override 
{
        if (amount <= balance) {
            balance -= amount;
            cout << "Amount withdrawn: " << amount << endl;
            checkAndImposePenalty();
        } else {
            cout << "Insufficient balance." << endl;
        }
    }
};

int main() 
{
    sav_acc s;
    cur_acc c;

    s.initialize("Alice", 101, "Savings");
    c.initialize("Bob", 102, "Current");

    cout << "\n--- Savings Account ---" << endl;
    s.deposit(1000);
    s.displayBalance();
    s.computeAndDepositInterest(5, 2); 
    s.displayBalance();
    s.withdraw(300);
    s.displayBalance();

    cout << "\n--- Current Account ---" << endl;
    c.deposit(400); 
    c.displayBalance();
    c.withdraw(100);
    c.displayBalance();

    return 0;
}
