/* 
    Program Name: Recursion (recursion.cpp)
    Compile: c++ recursion.cpp -o recursion
    Author: Malachi Payne
    Course: COMP B12
    Date: 11.22.2020
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Note: given funcitons need correct return types (not given)

/****
   Recursive backwards print
   > Prints a string starting from last index to first
*****/
void printReverse(string s, int i)
{
    if (i < s.size())
    {
        /* Your code here */
        printReverse(s, i + 1);
        cout << s[i];
    }
    else
    {
        /* Your code here */
        return;
    }
}

/****
   Recursive power function
   > Computes a^b, where b can be positive or negative
*****/
double recPower(double a, int b)
{
    /* Your code here */
    if (b == 0) // IF THE EXPONENT IS ZERO
    {
        return 1;
    }
    else if (b > 0) // IF THE EXPONENT IS POSITIVE
    {
        return (a * recPower(a, b - 1));
    }
    else if (b < 0) // IF THE EXPONENT IS NEGATIVE
    {
        return ((1 / a) * recPower(a, b + 1));
    }
    return 0;
}

/****
   Recursive string replace
   > Replaces all instances of a character in a string with another character
*****/

void recReplace(/* Your code here */ string &str, int i, char oldChar, char newChar)
{
    /* Your code here */
    if (i == str.size())
    {
        return;
    }
    else if (str.at(i) == oldChar)
    {
        str.at(i) = newChar;
    }
    return recReplace(str, i + 1, oldChar, newChar);
}

/****
   Recursive list find
   > Searches if x exists in list, returns true if found, false otherwise
*****/
bool recListFind(/* Your code here */ vector<int> v, int i, int x)
{
    if (/* Your code here */ v[i] == x)
    {
        /* Your code here */
        return true;
    }
    return /* Your code here */ recListFind(v, i + 1, x);
}

int main()
{
    /*! DO NOT MODIFY CODE BELOW */

    /* Prints a string in reverse */
    cout << "PRINT REVERSE" << endl;
    cout << "----------" << endl;
    string s1 = "hello world";
    cout << "String: " << s1 << endl;
    cout << "Reversed: ";
    printReverse(s1, 0);
    cout << endl;

    /* Computes a^b (power function) */
    cout << "POWER" << endl;
    cout << "----------" << endl;
    int a = 2, b = -3;
    cout << a << "^" << b << " = ";
    cout << recPower(a, b) << endl;
    cout << endl;

    /* Replaces a character in a string with a new one */
    cout << "REPLACE" << endl;
    cout << "----------" << endl;
    string s2 = "-h-e-l-l-o-";
    char oldChar = '-';
    char newChar = ' ';
    cout << "String: " << s2 << endl;
    cout << "> Replace '" << oldChar << "' with '" << newChar << endl;
    recReplace(s2, 0, oldChar, newChar);
    cout << "String: " << s2 << endl;
    cout << endl;

    /* Searches for value in vector */
    cout << "FIND" << endl;
    cout << "----------" << endl;
    int x = 7;
    cout << "Does " << x << " exist in the vector? ";
    vector<int> v = {5, 1, 6, 7, 9};
    cout << recListFind(v, 0, 7) << endl;
    cout << endl;

    return 0;
}