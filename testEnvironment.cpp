/*
This is a test environment used to run sections of code that can be placed into a larger program
Program Name: Test Environment (testEnvironment.cpp)
Compile: c++ testEnvironment.cpp -o testEnvironment
Author: Malachi Payne
~~~~~~~~~~~~~~~~~~~~~~~~
*/

#include <iostream>

using namespace std;

class First
{
protected:
    int a;

public:
    First(int x = 1)
    {
        a = x;
    }
    virtual void multiply() { a *= 3; }
    int getVal()
    {
        multiply();
        return a;
    }
};

class Second : public First
{
private:
    int b;

public:
    Second(int y = 4)
    {
        b = y;
    }
    virtual void multiply()
    {
        b *= 5;
    }
};

int main()
{
    First object1;
    Second object2;

    cout << "obj1: " << object1.getVal() << endl;
    cout << "obj2: " << object2.getVal() << endl;

    return 0;
}