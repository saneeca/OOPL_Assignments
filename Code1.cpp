#include <iostream>
using namespace std;

class Account {
protected:
    string name;
    int acc_no;
    string acc_type;
    float balance;

public:
    void init(string n, int no, string type, float bal) {
        name = n;
        acc_no = no;
        acc_type = type;
        balance = bal;
    }

    void deposit(float amount) {
        balance += amount;
    }

    void display_balance() {
        cout << "Name: " << name << endl;
        cout << "Account No: " << acc_no << endl;
        cout << "Type: " << acc_type << endl;
        cout << "Balance: " << balance << endl;
    }

    float get_balance() {
        return balance;
    }

    void set_balance(float bal) {
        balance = bal;
    }
};

class Sav_acct : public Account {
public:
    void compute_interest(float rate, int time) {
        float interest = balance * rate * time / 100;
        balance += interest;
    }

    void withdraw(float amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            cout << "Not enough balance." << endl;
        }
    }
};

class Cur_acct : public Account {
public:
    void withdraw(float amount) {
        if (amount <= balance) {
            balance -= amount;
            check_min_balance();
        } else {
            cout << "Not enough balance." << endl;
        }
    }

    void check_min_balance() {
        if (balance < 500) {
            cout << "Below minimum balance. Service charge applied." << endl;
            balance -= 50;
        }
    }
};
int main() {
    Sav_acct s;
    Cur_acct c;

    s.init("Alice", 1001, "Savings", 1000);
    c.init("Bob", 1002, "Current", 600);

    s.deposit(200);
    s.compute_interest(5, 2);  // 5% for 2 years
    s.withdraw(300);
    s.display_balance();

    c.deposit(100);
    c.withdraw(300);
    c.display_balance();

    return 0;
}
