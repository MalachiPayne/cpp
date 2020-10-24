/* 
    Program Name: programName (programName.cpp)
    Compile: c++ programName.cpp -o programName
    Author: Malachi Payne
    Course: COMP B12
    Date: date
*/

#include <iostream>
using namespace std;

// ---------- STRUCTURES ---------- //
struct User
{
public:
    string first_name;
    string last_name;
    string get_status() //not usually included in structures as methods are typically used in classes
    {
        return status;
    }

private:
    string status = "Gold";
};

int main()
{
    User me;
    me.first_name = "Malachi";
    me.last_name = "Payne";

    cout << "First name: " << me.first_name << endl;
    cout << "Status: " << me.get_status() << endl;

    return 0;
}