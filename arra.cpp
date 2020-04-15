
#include <iostream>
#include <cassert>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include "Account.h"

using namespace std;

int id; double bal; double interest;
float mInterestRate; double yInterestRate; double mInterest;

Account accnt[10];

void setAccountId(int x)
{
    cout << "\nPlease enter an account number from 0 - 9" << endl;
    cin >> id;
    id = x;
}

int getAccountId()
{
    cout << "Account ID: " << id;
    return id;
}

void setBalance(double x)
{
    x = rand() % 20000 + 10000.00;
    bal = x;
}

void deposit(double amount)
{
    cout << "Enter amount to be deposited: " << endl;
    cin >> amount;
    bal += amount;
}

double getBalance()
{
    cout << "\nCurrent Balance: $" << bal << endl;
    return bal;
}

void setInterest(double x)
{
    x = rand() % 5 + 1.5;
    interest = x;
}

double getInterest()
{
    cout << "Yearly interest rate: " << interest << "%" << endl;
    return interest;
}

double getMonthlyInterestRate()
{
    mInterestRate = interest / 12;
    cout << "Monthly interest rate: " << mInterestRate << "%" << endl;
    return mInterestRate;
}

double getMonthlyInterest()
{
    mInterest = mInterestRate*bal;
    cout << "Monthly interest: $" << mInterest << endl;
    return mInterest;
}

bool withdraw(double amount)
{
    if (bal >= amount)
    {
        bal -= amount;
        return true;
    }
    else
    {
        return false;
    }
}

void start()
{
    cout << "\nPlease enter an account number from 0 - 9" << endl;
    cin >> id;


}

void options(Account accnt[], int id, double bal, double interest)
{
    int option;
    cout << "\nEnter 1 to make a deposit";
    cout << "Enter 2 to make a withdraw";
    cout << "Enter 3 to check balance";
    cout << "Enter 4 to check interest rate";
    cout << "Enter 5 to display account summary";
    cout << "Enter -1 to return to the main menu";
    cin >> option;

    if (option == 1)
    {
        deposit(bal);
        options(accnt, id, bal, interest);
    }
    else if (option == 2)
    {
        withdraw(bal);
        options(accnt, id, bal, interest);
    }
    else if (option == 3)
    {
        getBalance();
        options(accnt, id, bal, interest);
    }
    else if (option == 4)
    {
        cout << "\nMonthly interest rate: " << mInterestRate;
        cout << "Yearly interest rate: " << yInterestRate;
        options(accnt, id, bal, interest);
    }
    else if (option == 5)
    {
        cout << "\nAccount ID: " << id;
        cout << "Current Balance: " << bal;
        cout << "Monthly interest rate: " << mInterestRate;
        cout << "Monthly interest amount: " << mInterest;
        options(accnt, id, bal, interest);
    }
    else if (option == -1)
    {
        start();
        options(accnt, id, bal, interest);
    }
    else
    {
        cout << "\nInvalid Selection." << endl;
        options(accnt, id, bal, interest);
    }
}
int main()
{
    Account accnt[10]; 	//Create an array of 10 Account objects

    start(); 	//start program
    options(accnt, id, bal, interest); //display options


    system("pause");
    return 0;

}
