/* 
    Program Name: programName (programName.cpp)
    Compile: c++ programName.cpp -o programName
    Author: Malachi Payne
    Course: COMP B12
    Date: date
*/

#include <iostream>
using namespace std;

// ---------- FUNCTION PROTOTYPES ---------- //
int linearSearch(const int[], int, int);
int binarySearch(const int[], int, int);

void bubbleSort(int[], int);
void selectionSort(int[], int);
void swap(int &, int &);

int main()
{
    // ----- LINEAR SEARCH ----- //
    { // Curly brace was placed To organize code
        const int LINEARSIZE = 5;
        int tests[LINEARSIZE] = {87, 75, 98, 100, 82};
        int linearResults;

        linearResults = linearSearch(tests, LINEARSIZE, 100);
        if (linearResults == -1)
            cout << "you did not earn 100 points on any test" << endl;
        else
        {
            cout << "you earned 100 points on test " << linearResults + 1 << endl;
        }
    }
    // ----- BINARY SEARCH ----- //
    { // Curly brace was placed To organize code
        const int BINARYSIZE = 20;
        int idNums[BINARYSIZE] = {101, 142, 147, 189, 199, 207, 222, 234, 289, 296, 310, 319, 388, 394, 417, 429, 447, 521, 563, 600};
        int binaryResults;
        int empID;

        cout << "Enter employee ID you wish to search for: ";
        cin >> empID;

        binaryResults = binarySearch(idNums, BINARYSIZE, empID);

        if (binaryResults == -1)
            cout << "that number does not exist in the array. \n";
        else
        {
            cout << "that ID is found at element: " << binaryResults << "in the array." << endl;
        }
    }
    // ----- BUBBLE SORT ----- //
    { // Curly brace was placed To organize code
        const int BUBBLESIZE = 6;
        int values[BUBBLESIZE] = {6, 1, 5, 2, 4, 3}; // array of unsorted array

        cout << "The unsorted values: " << endl; // display unsorted values
        for (auto bubbleElement : values)
            cout << bubbleElement << " ";
        cout << endl;

        bubbleSort(values, BUBBLESIZE); // sort the array

        cout << "The sorted values: " << endl; // display the sorted array
        for (auto bubbleElement : values)
            cout << bubbleElement << " ";
        cout << endl;
    }
    // ----- SELECTION SORT ----- //
    { // Curly brace was placed To organize code
        const int SELECTIONSIZE = 6;
        int selectionValues[SELECTIONSIZE] = {6, 1, 5, 2, 4, 3}; // array of unsorted array

        cout << "The unsorted values: " << endl; // display unsorted values
        for (auto selectionElement : selectionValues)
            cout << selectionElement << " ";
        cout << endl;

        selectionSort(selectionValues, SELECTIONSIZE); // sort the array

        cout << "The sorted values: " << endl; // display the sorted array
        for (auto selectionElement : selectionValues)
            cout << selectionElement << " ";
        cout << endl;
    }
    return 0;
}

// ---------- LINEAR SEARCH FUNCTION ---------- //
int linearSearch(const int arr[], int linearSize, int linearValue)
{

    int index = 0;      // Used as a subscript to search the array
    int position = -1;  // Records the position of the search value
    bool found = false; // Flag to indicate if the value was found

    while (index < linearSize && !found)
    {
        if (arr[index] == linearValue)
        {                     // If the value is found
            found = true;     // Set the flag
            position = index; // record the value's subscript
        }
        index++; // Moves to the next element
    }
    return position; // Return the positon or -1
}

// ---------- BINARY SEARCH FUNCTION ---------- //

int binarySearch(const int array[], int binarySize, int binaryValue)
{

    int first = 0,      // First array element
        last = -1,      // Last array element
        middle,         // Midpoint of the search
        position = -1;  // Position of the search value
    bool found = false; // Flag

    while (!found && first <= last)
    {
        middle = (first + last) / 2;      // Calculate the midpoint
        if (array[middle] == binaryValue) // If the value is found at the midpoint
        {
            found = true;
            position = middle;
        }
        else if (array[middle] > binaryValue) // If value is in the lower half

            last = middle - 1;
        else
            first = middle + 1; // If value is in the upper half
    }

    return position; // Return the position or -1
}

// ---------- BUBBLE SORT FUNCTION ---------- //
void bubbleSort(int array[], int size)
{
    int maxElement;
    int index;

    for (maxElement = size - 1; maxElement > 0; maxElement--)
    {
        for (index = 0; index < maxElement; index++)
        {
            if (array[index] > array[index + 1])
            {
                swap(array[index], array[index + 1]);
            }
        }
    }
}

// ---------- SELECTION SORT FUNCTION ---------- //
void selectionSort(int array[], int size)
{
    int minIndex, minValue;
    for (int start = 0; start < (size - 1); start++)
    {
        minIndex = start;
        minValue = array[start];
        for (int index = start + 1; index < size; index++)
        {
            if (array[index] < minValue)
            {
                minValue = array[index];
                minIndex = index;
            }
        }
        swap(array[minIndex], array[start]);
    }
}

// ---------- SWAP FUNCTION ---------- //
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}