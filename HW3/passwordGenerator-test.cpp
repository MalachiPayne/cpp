#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    // ---------- PASSWORD VARIABLES ---------- //
    char x;
    int passwordLength = 10;
    char *pw = new char[passwordLength];
    srand(time(0));
    // ---------- PASSWORD FOR LOOP ---------- //
    for (int i = 0; i < passwordLength; i++)
    {
        x = (rand() % (126 - 48 + 1)) + 48;
        pw[i] = x;
        // cout << pw[i]; // TEST CONSOLE OUT
    }
    // ---------- PASSWORD ASSIGNMENT ---------- //
    string password = pw;
    cout << password << endl;
}
