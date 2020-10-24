/* 
    Program Name: programName (programName.cpp)
    Compile: c++ programName.cpp -o programName
    Author: Malachi Payne
    Course: COMP B12
    Date: date
*/

#include <iostream>
using namespace std;

// ---------- CLASS ---------- //
class User // creates a data type "User"
{
private:
    string status = "Gold"; // data members

public:
    string first_name;
    string last_name;
    string get_status() // accesses the private status data which can be called in main
    {
        return status;
    }
};

int main()
{
    User user;
    user.first_name = "Malachi";
    user.last_name = "Payne";

    cout << "First name: " << user.first_name << endl;
    cout << "Status: " << user.get_status() << endl;

    return 0;
}