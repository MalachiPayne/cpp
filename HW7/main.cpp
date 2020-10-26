/*
Program Name: main (main.cpp)
Compile: c++ main.cpp Account.cpp SavingsAccount.cpp -o main
Author: Malachi Payne
Date: 10.25.2020
*/

#include <iostream>
#include <iomanip>
#include "Account.h"
#include "SavingsAccount.h"

using namespace std;

int main()
{
    int option;
    double amount;
    SavingsAccount *savings;
    savings = new SavingsAccount(1234, 322.75, 2, 3, 0.06, 2.50);

    // ----- OPENING MENU ----- //

    while (option != 3)
    {
        cout << endl
             << "Savings Account" << endl
             << "1. Deposit" << endl
             << "2. Withdraw" << endl
             << "3. Logout" << endl
             << "Enter Option: ";
        cin >> option;
        switch (option)
        {
            // ----- DEPOSIT ----- //
        case 1:
            cout << endl
                 << "Current Balance: $" << fixed << setprecision(2) << savings->getAccountBalance() << endl
                 << "Enter Amount to Deposit: $";
            cin >> amount;
            savings->deposit(amount);
            savings->display();
            break;

            // ----- WITHDRAW ----- //
        case 2:
            cout << endl
                 << "Current Balance: $" << fixed << setprecision(2) << savings->getAccountBalance() << endl
                 << "Enter Amount to Withdraw: $";
            cin >> amount;
            savings->withdraw(amount);
            savings->display();
            break;

            // ----- LOGOUT ----- //
        case 3:
            break;
        }
    }

    return 0;
}
