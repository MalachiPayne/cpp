#ifndef ACCOUNT_HEADER
#define ACCOUNT_HEADER

#include <iostream>
using namespace std;
//Account class declaration
class Account
{
    // ----- PRIVATE MEMBERS ----- //
protected:
    int accountNum;
    double accountBalance;
    int numberOfWithdrawals;
    int numberOfDeposits;
    double annualInterstRate;
    double monthlyServiceCharges;

    // ----- PUBLIC MEMBERS ----- //
public:
    Account(int, double, int, int, double, double); // Overloaded constructor

    void deposit(double); // A virtual function that accepts an argument for the amount of the deposit

    void withdraw(double); // A virtual function that accepts an argument for the amount of the withdrawal

    void calcInt(); // A virtual function that updates the balance by calculating the monthly interest earned by the account and adding the interest to the balance
                    /*
    // ----- SETTER FUNCTIONS ----- //
    void setAccountNum(int);

    void setAccountBalance(double);

    void setNumberOfWithdrawals(int);

    void setNumberOfDeposits(int);

    void setAnnualInterstRate(double);

    void setMonthlyServiceCharges(double);

    // ----- GETTER FUNCTIONS ----- //
    int getAccountNum();

    double getAccountBalance();

    int getNumberOfWithdrawals();

    int getNumberOfDeposits();

    double getAnnualInterestRate();

    double getMonthlyServiceCharges();
    */
    double getAccountBalance();
};

#endif