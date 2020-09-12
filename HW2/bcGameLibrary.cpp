/* 
    Program Name: BC Game Library (bcGameLibrary.cpp)
    Compile: c++ bcGameLibrary.cpp -o bcGameLibrary
    Author: Malachi Payne
    Course: COMP B12
    Date: 9.11.2020
*/
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

int main()
{
    //---------- CONSTANTS AND VARRIABLES ----------
    const string username = "BCStudent", password = "Password";
    string usernameInput, passwordInput;
    int loginAttempts = 0, loginSuccess = 0, logout = 0,
        menuNumber, patternInput, randomNumber, numberGuess;

    // ---------- LOGIN HOME PAGE ----------
    cout << "BC GAME LIBRARY" << endl;
    cout << "Log in to access your library" << endl;
    do
    {
        cout << "Username: ";
        cin >> usernameInput;
        cout << "Password: ";
        cin >> passwordInput;

        if (usernameInput != username || passwordInput != password)
        {
            cout << "Login Failed! Invalid Username/Password" << endl
                 << endl;
            loginAttempts++;
        }
        else
        {
            cout << endl
                 << "SUCCESS!" << endl;
            loginSuccess = 1;
        }

        if (loginAttempts == 3)
        {
            cout << "Too many failed attemts. Goodbye ;)" << endl;
        }
    } while (loginAttempts < 3 && !loginSuccess);

    //---------- GAME MENU ----------
    do
    {
        cout << endl
             << "Welcome to Your BC Game Library" << endl
             << endl
             << "GAMES:" << endl
             << "1. Random Number Game" << endl
             << "2. Print Pattern Game" << endl
             << "3. Logout" << endl
             << "ENTER THE GAME NUMBER TO PLAY: ";
        cin >> menuNumber;

        switch (menuNumber)
        {
            // ---------- RANDOM NUMBER GAME ----------

        case 1:
            srand(time(0));
            randomNumber = (rand() % (20 - 1) + 1);

            cout << "RANDOM NUMBER GAME" << endl
                 << "Guess what number I'm thinking of? (Between 1-20)" << endl
                 << "Your Guess: ";

            while (numberGuess != randomNumber)
            {
                cin >> numberGuess;
                if (numberGuess < randomNumber)
                {
                    cout << "Nope! Your Guess is Too Low, Try Again." << endl;
                }
                else if (numberGuess > randomNumber)
                {
                    cout << "Nope! Your Guess is Too High, Try Again" << endl;
                }
                else
                {
                    cout << "You guessed it! The Random Number Was: " << randomNumber << endl;
                }
            }

            break;
            // ---------- PRINT PATTERN GAME ----------
        case 2:
            cout << endl
                 << "ENTER A PATTERN NUMBER: ";
            cin >> patternInput;
            cout << endl;
            for (int patternRow = 0; patternRow < patternInput; patternRow++)
            {
                for (int patternColumn = 0; patternColumn <= patternRow; patternColumn++)
                {
                    cout << "*";
                }
                cout << endl;
            }
            break;
            // ---------- LOGOUT ----------
        case 3:
            cout << endl
                 << "You Have Logged Out. Goodbye!" << endl;
            logout = 1;
            break;

        default:
            cout << endl
                 << "Invalid Game Number" << endl;
        }
    } while (!logout);
    return 0;
}
