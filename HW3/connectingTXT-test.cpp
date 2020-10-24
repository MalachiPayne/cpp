#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
using namespace std;
bool username_exists(string username)

    int main()
{
    // ---------- CONNECTING AND EDITING THE userDetails.txt FILE ----------

    // getting and printing file data
    ifstream inFile;
    inFile.open("userDetails.txt");
    string userDetailsFile;
    //getline(inFile, userDetailsFile, '\0');
    // cout << userDetailsFile;
    inFile.close();

    // outputting edits to a file
    ofstream outFile;
    outFile.open("userDetails.txt", ofstream::app);
    outFile << endl
            << "Username: "
            << generate_user() << endl //Username
            << "Password: "
            << generate_password() << endl; //Password
    cout << userDetailsFile;
    outFile.close();
}
