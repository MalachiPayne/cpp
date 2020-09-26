/* 
    Program Name: Inventory Manager (inventory.cpp)
    Compile: c++ inventory.cpp -o inventory
    Author: Malachi Payne
    Course: COMP B12
    Date: 9.25.2020
*/

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// ---------- GLOBAL VARIABLES ---------- //
vector<string> productNameVector;
vector<int> productIDVector;
vector<double> priceVector;
vector<int> quantityVector;

// ---------- FUNCTIONS ---------- //

void addItem(string name, int ID, float price, int quantity)
{
    productNameVector.push_back(name);
    productIDVector.push_back(ID);
    priceVector.push_back(price);
    quantityVector.push_back(quantity);
}

void removeItem(int ID)
{
    for (size_t i = 0; i < productIDVector.size(); ++i)
    {
        if (ID == productIDVector[i])
        {
            if (productIDVector[i] == productIDVector.back())
            {
                productNameVector.pop_back();
                productIDVector.pop_back();
                priceVector.pop_back();
                quantityVector.pop_back();
                return;
            }
            else if (productIDVector[i] != productIDVector.back())
            {
                swap(productNameVector[i], productNameVector.back());
                swap(productIDVector[i], productIDVector.back());
                swap(priceVector[i], priceVector.back());
                swap(quantityVector[i], quantityVector.back());
                productNameVector.pop_back();
                productIDVector.pop_back();
                priceVector.pop_back();
                quantityVector.pop_back();
                return;
            }
        }
    }
    cout << "error: not a valid ID" << endl
         << endl;
    return;
}

// -------------------- MAIN -------------------- //
int main()
{

    // ---------- MENU ---------- //
    while (true)
    {
        int menuSelection = 0;
        string productNameInput;
        int productIDInput;
        double priceInput;
        int quantityInput;

        cout
            << "INVENTORY" << endl
            << "1. Add an item" << endl
            << "2. Remove an item" << endl
            << "3. View all items" << endl
            << "4. Logout" << endl
            << "Enter Option: ";
        cin >> menuSelection;

        switch (menuSelection)
        {
            // ---------- ADD AN ITEM FUNCTION ---------- //
        case 1:
        {
            cout << endl
                 << "ADD ITEM" << endl
                 << "Product Name: ";
            cin >> productNameInput;
            cout << "Product ID: ";
            cin >> productIDInput;
            cout << "Price: ";
            cin >> priceInput;
            cout << "Qty: ";
            cin >> quantityInput;
            cout << endl;

            addItem(productNameInput, productIDInput, priceInput, quantityInput);
            break;
        }
            // ---------- REMOVE AN ITEM FUNCTION ---------- //
        case 2:
        {
            cout << "Item ID: ";
            cin >> productIDInput;
            removeItem(productIDInput);
            cout << endl;
            break;
        }
            // ---------- VIEW ALL ITEMS FUNCTION ---------- //
        case 3:
        {
            cout << "----------------------------" << endl;
            cout << setw(4) << "ID" << setw(10) << "Name" << setw(7) << "Price" << setw(5) << "Qty" << endl;
            for (size_t i = 0; i < productIDVector.size(); i++)
            {
                cout << setw(4) << productIDVector[i]
                     << setw(10) << productNameVector[i]
                     << setw(7) << priceVector[i]
                     << setw(5) << quantityVector[i] << endl;
            }
            cout << "----------------------------" << endl;
            break;
        }
            // ---------- LOGOUT FUNCTION ---------- //
        case 4:
        {
            cout << "You Have Logged Out Successfuly" << endl
                 << endl;
            return 0;
            break;
        default:
            cout << "error: please choose a valid menu option" << endl;
        }
        }
    }
    return (0);
}