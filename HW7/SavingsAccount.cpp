#include "SavingsAccount.h"

bool ACTIVE = true;
bool INACTIVE = false;

SavingsAccount::SavingsAccount(int accountNum, double accountBalance, int numberOfWithdrawals, int numberOfDeposits, double annualInterestRate, double monthlyServiceCharges) : Account(accountNum, accountBalance, numberOfWithdrawals, numberOfDeposits, annualInterestRate, monthlyServiceCharges)
{
    this->accountNum = accountNum;
    this->numberOfWithdrawals = numberOfWithdrawals;
    this->numberOfDeposits = numberOfDeposits;
    this->monthlyServiceCharges = monthlyServiceCharges;
    status = false;
}

void SavingsAccount::deposit(double deposit)
{
    if (status == INACTIVE)
    {
        if (deposit + accountBalance >= 25)
        {
            Account::deposit(deposit);
            cout << "Deposit Successful!" << endl;
        }
    }
    else
    {
        cout << "Account is Inactive. Deposit at least: $" << 25 - accountBalance << endl;
    }
}

void SavingsAccount::withdraw(double withdraw)
{
    if (status == ACTIVE)
    {
        Account::withdraw(withdraw);
    }
    else if (withdraw > accountBalance)
    {
        cout << "Insufficient Balance" << endl;
    }
    else
    {
        Account::withdraw(withdraw);
        if (accountBalance < 25.0)
        {
            cout << "Account has fallen below $25 and will become inactive." << endl;
            status = INACTIVE;
            annualInterstRate += 0.01;
        }
        if (numberOfWithdrawals > 4)
        {
            monthlyServiceCharges += 1.0;
        }
    }
}

void SavingsAccount::display()
{
    string statusString = (status == ACTIVE) ? "Active" : "Inactive";
    cout << endl
         << "Account Number: " << accountNum << endl
         << "Status: " << statusString << endl
         << "Total Deposits: " << numberOfDeposits << endl
         << "Total Withdrawals: " << numberOfWithdrawals << endl
         << "Service Charges: " << monthlyServiceCharges << endl
         << "Balance: " << accountBalance << endl;
}