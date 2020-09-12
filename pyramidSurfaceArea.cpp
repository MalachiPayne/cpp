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
    double l, w, h;

    cout << "SURFACE AREA OF A PRYAMID\n";
    cout << "Enter Length: ";
    cin >> l;

    cout << "Enter Width: ";
    cin >> w;

    cout << "Enter Height: ";
    cin >> h;

    double function1 = (l * w);                               // length * width
    double function2 = (l * sqrt(pow(w / 2, 2) + pow(h, 2))); // length * √[(width/2)^2 + height^2]
    double function3 = (w * sqrt(pow(l / 2, 2) + pow(h, 2))); // width *√[(length/2)^2 + height^2]

    float Area = function1 + function2 + function3;

    cout << fixed << setprecision(2) << "Surface Area: " << Area << endl;
    return 0;
}
