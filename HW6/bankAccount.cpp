/* 
    Program Name: Bank Account (bankAccount.cpp)
    Compile: c++ bankAccount.cpp -o bankAccount
    Author: Malachi Payne
    Course: COMP B12
    Date: 10.14.2020
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// ----- FUNCTION PROTOTYPES ----- //
void displayMenu();

class Account
{
    // ----- PRIVATE MEMBERS ----- //
private:
    int accountNum;
    string accountPIN;
    double accountBalance;

    void setPin(string accountPIN) // SETTER FUNCTION FOR ACCOUNT PIN
    {
        this->accountPIN = accountPIN;
    }
    void setAccountNum(int accountNum) // SETTER FUNCTION FOR ACCOUNT NUMBER
    {
        this->accountNum = accountNum;
    }

    // ----- PUBLIC MEMBERS ----- //
public:
    int userInputNum;
    string userInputPIN;
    double userInputBalance;
    Account() // DEFAULT CONSTRUCTOR
    {
        accountNum = -1;
        accountPIN = "-1";
        accountBalance = 0.0;
    }

    Account(int accountNum, string accountPIN, double accountBalance) // OVERLOADED CONSTRUCTOR
    {
        this->accountNum = accountNum;
        this->accountPIN = accountPIN;
        this->accountBalance = accountBalance;
        //cout << this->accountNum << endl;
        //cout << this->accountPIN << endl;
    }

    void setAccountBalance(int accountBalance) // SETTER FUNCTION FOR ACCOUNT BALANCE
    {
        this->accountBalance = accountBalance;
    }

    // ----- GETTER FUNCTIONS ----- //
    int getAccountNum() const // GETTER FUNCTION FOR ACCOUNT NUM
    {
        return accountNum;
    }

    double getAccountBalance() const // GETTER FUNCTION FOR ACCOUNT BALANCE
    {
        return accountBalance;
    }

    bool confirmPIN(string userInputPIN) const // CONFIRMS PASSED PIN MATCHES OBJECTS PIN
    {
        if (userInputPIN == accountPIN)
        {
            return true;
        }
        else
        {
            cout << endl
                 << "Incorrect Credentials" << endl;
            return false;
        }
    }

    void updateBalance(double accountBalance) // UPDATES ACCOUNT BALANCE
    {
        this->accountBalance += accountBalance;
    }
};

// ----- CLASS OBJECTS ----- //
Account accountObj; // ACCOUNT OBJECT

//// --------------- MAIN --------------- ////
int main()
{
    // ----- VARIABLES ----- //
    int userInputNum, option;
    string userInputPIN;
    double userInputAmount;
    int accountNum = 0;

    // ----- ARRAY OF ACCOUNTS ----- //
    const int ARRAY_SIZE = 3;
    Account accountArray[ARRAY_SIZE] = {
        Account(123, "abc123", 100.00), // ACCOUNT 1
        Account(456, "def456", 50.00),  // ACCOUNT 2
        Account(789, "ghi789", 500.63)  // ACCOUNT 3
    };

    // ---------- LOGIN VARIFICATION ---------- //
    cout << "LOGIN" << endl
         << "Enter Account #: ";
    scanf("%d", &userInputNum);
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        if (userInputNum == accountArray[i].getAccountNum())
        {
            cout << "Enter Account PIN: ";
            cin >> userInputPIN;
            while (accountArray[i].confirmPIN(userInputPIN) == true && option != 3)
            {
                displayMenu();
                cin >> option;
                switch (option)
                {
                    /* CHECK BALANCE */
                case 1:
                    cout << endl
                         << "Account #: " << accountArray[i].getAccountNum() << endl

                         << "Balance: $" << fixed << setprecision(2) << accountArray[i].getAccountBalance() << endl;
                    cout << endl;
                    break;

                    /* MAKE A DEPOSIT */
                case 2:
                    cout << "Enter Amount to Deposit: ";
                    scanf("%lf", &userInputAmount);
                    accountArray[i].updateBalance(userInputAmount);
                    cout << "Account #: " << accountArray[i].getAccountNum() << endl
                         << "New Balance: $" << fixed << setprecision(2) << accountArray[i].getAccountBalance() << endl;
                    break;

                    /* LOGOUT */
                case 3:
                    cout << endl
                         << "Goodbye!" << endl;
                    break;

                default:
                    cout << "Please Enter a Valid Option" << endl;
                    break;
                }
            }
            accountNum++;
        }
    }
    return 0;
}
// ---------- FUNCTIONS ---------- //
void displayMenu()
{
    cout << endl
         << "------ MENU ------" << endl
         << "1. Check Balance" << endl
         << "2. Make a Deposit" << endl
         << "3. Logout" << endl
         << "------------------" << endl
         << "Enter Option: ";
}