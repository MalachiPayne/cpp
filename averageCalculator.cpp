/*
Author: Malachi Payne
Course: COMP B12
Created On: 09.04.2020
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand(time(0));
    // Creating the random numbers and assigning them to variables
    int r1 = (rand() % 10) + 1;
    int r2 = (rand() % 10) + 1;
    int r3 = (rand() % 10) + 1;
    int r4 = (rand() % 10) + 1;
    int r5 = (rand() % 10) + 1;

    // Calculation of the average from the numbers
    int rcalculation = (r1 + r2 + r3 + r4 + r5) / 5;

    // Output the random numbers and ascociated calculation
    cout << "AVERAGE CALCULATOR";
    cout << "\nRandom #1: " << r1;
    cout << "\nRandom #2: " << r2;
    cout << "\nRandom #3: " << r3;
    cout << "\nRandom #4: " << r4;
    cout << "\nRandom #5: " << r5;
    cout << "\nAverage of 5 random numbers is: " << rcalculation << endl;

    return 0;
}