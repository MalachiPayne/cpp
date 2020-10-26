#include "Account.h"
//Account class function definitions

Account::Account(int accountNum, double accountBalance, int numberOfWithdrawals, int numberOfDeposits, double annualInterestRate, double monthlyServiceCharges) // Overloaded constructor
{
    this->accountBalance = accountBalance;
    this->annualInterstRate = annualInterestRate;
}

void Account::deposit(double amount) // A virtual function that accepts an argument for the amount of the deposit
{
    this->accountBalance += amount;
    numberOfDeposits++;
}

void Account::withdraw(double amount) // A virtual function that accepts an argument for the amount of the withdrawal
{
    if (accountBalance >= amount)
    {
        this->accountBalance -= amount;
        numberOfWithdrawals++;
    }
    else
    {
        cout << "Insufficient Funds" << endl;
    }
}

void Account::calcInt() // A virtual function that updates the balance by calculating the monthly interest earned by the account and adding the interest to the balance
{
    accountBalance += (annualInterstRate / 12) * accountBalance;
}
/*
// ----- SETTER FUNCTIONS ----- //
void Account::setAccountNum(int accountNum)
{
    this->accountNum = accountNum;
}

void Account::setAccountBalance(double accountBalance)
{
    this->accountBalance = accountBalance;
}

void Account::setNumberOfWithdrawals(int numberOfWithdrawals)
{
    this->numberOfWithdrawals = numberOfWithdrawals;
}

void Account::setNumberOfDeposits(int numberOfDeposits)
{
    this->numberOfDeposits = numberOfDeposits;
}

void Account::setAnnualInterstRate(double annualInterstRate)
{
    this->annualInterstRate = annualInterstRate;
}

void Account::setMonthlyServiceCharges(double monthlyServiceCharges)
{
    this->monthlyServiceCharges = monthlyServiceCharges;
}

// ----- GETTER FUNCTIONS ----- //
int Account::getAccountNum() const
{
    return accountNum;
}

double Account::getAccountBalance() const
{
    return accountBalance;
}

int Account::getNumberOfWithdrawls() const
{
    return numberOfWithdrawals;
}

int Account::getNumberOfDeposits() const
{
    return numberOfDeposits;
}

double Account::getAnnualInterestRate() const
{
    return annualInterstRate;
}

double Account::getMonthlyServiceCharges() const
{
    return monthlyServiceCharges;
}
*/
double Account::getAccountBalance()
{
    return accountBalance;
}