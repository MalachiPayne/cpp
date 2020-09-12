/*
Author: Malachi Payne
Course: COMP B12
Created On: 09.04.2020
*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    string firstName, lastName, jobTitle, jobDepartment;
    int employeeID, hoursPerWeek;

    // Collecting data to complete the employee profile:
    cout << "Enter First Name and Last Name Separated by a Space: ";
    cin >> firstName >> lastName;

    cout << "Enter Employee ID: ";
    cin >> employeeID;

    cout << "Enter Department: ";
    cin >> jobDepartment;

    cout << "Enter Job Title: ";
    cin >> jobTitle;

    cout << "Enter Number of Hours Per Week: ";
    cin >> hoursPerWeek;

    // Calculating weekly pay rate for the employee:
    const double hourlyPayRate = 17.50;
    double weeklyPayRate = hoursPerWeek * hourlyPayRate;

    //Creating employee profile:

    cout << endl
         << endl
         << "NEW EMPLOYEE DETAILS:" << endl;
    cout << "Department: " << jobDepartment << endl;
    cout << " Job Title: " << jobTitle << endl;
    cout << "      Name: " << firstName << " " << lastName << endl;
    cout << "        ID: " << employeeID << endl;
    cout << fixed << setprecision(2) << "Weekly Gross Pay: $" << weeklyPayRate << endl;

    return (0);
}