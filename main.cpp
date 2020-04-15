/* Header for Account class (Account.h) */
#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {
private:
    int accountNumber;
    double balance;

public:
    Account(int accountNumber, double balance = 0.0);
    int getAccountNumber() const;
    double getBalance() const;
    void setBalance(double balance);
    void credit(double amount);
    void debit(double amount);
    void print() const;
};

#endif

#include <iostream>
#include <iomanip>

using namespace std;

// Constructor
Account::Account(int no, double b) : accountNumber(no), balance(b) { }

// Public getter for private data member accountNumber
int Account::getAccountNumber() const {
    return accountNumber;
}

// Public getter for private data member balance
double Account::getBalance() const {
    return balance;
}

// Public setter for private data member balance
void Account::setBalance(double b) {
    balance = b;
    cout<<"\nInput balance";
    cin>>b;
}

// Adds the given amount to the balance
void Account::credit(double amount) {
    balance += amount;
}

// Subtract the given amount from the balance
void Account::debit(double amount) {
    if (amount <= balance) {
        balance -= amount;
    } else {
        cout << "Amount withdrawn exceeds the current balance!" << endl;
    }
}

// Print description for this Account instance
void Account::print() const {
    cout << fixed << setprecision(2);
    cout << "A/C no: " << accountNumber << " Balance=$" << balance << endl;
}
/* Test Driver for Account class (TestAccount.cpp) */
#include <iostream>


using namespace std;

int main() {
    Account a1(8111, 99.99);
    a1.print();     // A/C no: 8111 Balance=$99.99
    a1.credit(20);
    a1.debit(10);
    a1.print();     // A/C no: 8111 Balance=$109.99

    Account a2(8222);  // default balance
    a2.print();        // A/C no: 8222 Balance=$0.00
    a2.setBalance(100);
    a2.credit(20);
    a2.debit(200);  // Amount withdrawn exceeds the current balance!
    a2.print();     // A/C no: 8222 Balance=$120.00
    return 0;
}