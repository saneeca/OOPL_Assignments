#include <iostream>
using namespace std;

// RBI base class
class RBI 
{
protected:
    float minInterestRate;
    float minBalance;
    float maxWithdrawalLimit;

public:
    RBI() 
{
        minInterestRate = 4.0;       // Minimum 4% interest
        minBalance = 1000.0;         // Minimum balance allowed
        maxWithdrawalLimit = 25000;  // Max per transaction
    }

    virtual void showGuidelines() 
{
        cout << "\n--- RBI Guidelines ---" << endl;
        cout << "Minimum Interest Rate: " << minInterestRate << "%" << endl;
        cout << "Minimum Balance: ₹" << minBalance << endl;
        cout << "Maximum Withdrawal Limit: ₹" << maxWithdrawalLimit << " per transaction" << endl;
    }
};

// SBI Bank (inherits from RBI)
class SBI : public RBI 
{
private:
    float sbiInterestRate;
    float sbiMinBalance;
    float sbiWithdrawalLimit;

public:
    SBI() 
{
        sbiInterestRate = 4.5;
        sbiMinBalance = 1000;
        sbiWithdrawalLimit = 20000;
    }

    void showGuidelines() override 
{
        cout << "\n--- SBI Bank Rules ---" << endl;
        cout << "Interest Rate: " << sbiInterestRate << "%" << endl;
        cout << "Minimum Balance: ₹" << sbiMinBalance << endl;
        cout << "Max Withdrawal Limit: ₹" << sbiWithdrawalLimit << " per transaction" << endl;
    }
};

// HDFC Bank (inherits from RBI)
class HDFC : public RBI 
{
private:
    float hdfcInterestRate;
    float hdfcMinBalance;
    float hdfcWithdrawalLimit;

public:
    HDFC() 
{
        hdfcInterestRate = 5.0;
        hdfcMinBalance = 5000;
        hdfcWithdrawalLimit = 30000;
    }

    void showGuidelines() override 
{
        cout << "\n--- HDFC Bank Rules ---" << endl;
        cout << "Interest Rate: " << hdfcInterestRate << "%" << endl;
        cout << "Minimum Balance: ₹" << hdfcMinBalance << endl;
        cout << "Max Withdrawal Limit: ₹" << hdfcWithdrawalLimit << " per transaction" << endl;
    }
};

// Main function
int main() 
{
    RBI* rbi;         // Base class pointer

    RBI rbiObj;
    SBI sbiObj;
    HDFC hdfcObj;

    // Display RBI guidelines
    rbi = &rbiObj;
    rbi->showGuidelines();

    // Display SBI rules
    rbi = &sbiObj;
    rbi->showGuidelines();

    // Display HDFC rules
    rbi = &hdfcObj;
    rbi->showGuidelines();

    return 0;
}
