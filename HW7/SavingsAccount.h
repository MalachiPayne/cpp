#ifndef SAVINGSACCOUNT_HEADER
#define SAVINGSACCOUNT_HEADER

#include <iostream>
#include "Account.h"

class SavingsAccount : public Account
{
    // ----- PRIVATE MEMBERS ----- //
protected:
    bool status; // REPRESENTS AN ACTIVE OR INACTIVE ACCOUNT

    // ----- PUBLIC MEMBERS ----- //
public:
    SavingsAccount(int, double, int, int, double, double);

    void deposit(double);

    void withdraw(double);

    void display();
};

#endif