/* 
    Program Name: User Management (userManagement.cpp)
    Compile: c++ userManagement.cpp -o userManagement
    Author: Malachi Payne
    Course: COMP B12
    Date: 9.18.2020
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
using namespace std;

// ---------- GLOBAL VARIABLES ---------- //
ifstream inFile;
ofstream outFile;
string userDetailsFile, username, password;
// ---------- DEFINING / DECLARING FUNCTIONS ---------- //
// ---------- GENERATE USER ---------- //
void generate_user()
{
    srand(time(0));
    int randomNumberUser = (rand() % 900);
    string userNameTitle = "Username: ";
    username = "user";
    username += to_string(randomNumberUser);
    //cout << userNameTitle << username << endl;
}
// ---------- USERNAME EXISTS ---------- //
void username_exists()
{

    inFile.open("userDetails.txt");
    string userValue;
    while (inFile >> userValue)
    {
        if (userValue == username)
        {
            cout << "FOUND" << endl;
        }
    }
    inFile.close();
}
// ---------- GENERATE PASSWORD ---------- //
void generate_password()
{
    // --- PASSWORD VARIABLES --- //
    char x;
    int passwordLength = 10;
    char *pw = new char[passwordLength];
    srand(time(0));
    // --- PASSWORD FOR LOOP --- //
    for (int i = 0; i < passwordLength; i++)
    {
        x = (rand() % (126 - 48 + 1)) + 48;
        pw[i] = x;
        //        cout << pw[i]; // TEST CONSOLE OUT
    }
    // --- PASSWORD ASSIGNMENT --- //
    password = pw;
}
// ---------- ADD USER ---------- //
void add_user()
{

    outFile.open("userDetails.txt", ofstream::app);
    outFile << endl
            << "Username: "
            << username << endl //Username
            << "Password: "
            << password << endl; //Password
    cout << userDetailsFile;
    outFile.close();
}

// ---------- RESET PASSWORD ---------- //
void reset_password()
{
    //reset password fuction
}

// -------------------- MAIN -------------------- //
int main()
{
    int option;
    string username, password;
    // ---------- MENU ---------- //
    cout << "USER MANAGEMENT" << endl
         << "1. Create New User" << endl
         << "2. Reset Password" << endl
         << "Enter Option: ";
    cin >> option;

    // ---------- OPTION 1 ---------- //
    if (option == 1)
    {
        generate_user();
        generate_password();
        add_user();
        cout << "New user has been added" << endl;
    }
    // ---------- OPTION 2 ---------- //
    else
    {
        cout << "Enter the username to reset password." << endl;
        cin >> username;
        username_exists(username);
        generate_password();
        reset_password(username, password);
        cout << "Password has been reset" << endl;
    }

    return (0);
}