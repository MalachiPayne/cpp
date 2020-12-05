/* 
    Program Name: Binary Tree (binaryTree.cpp)
    Compile: c++ binaryTree.cpp -o binaryTree
    Author: Malachi Payne
    Course: COMP B12
    Date: 11.30.2020
*/

#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
    char value;
    Node *left;
    Node *right;

    Node()
    {
        value = '\0';
        left = nullptr;
        right = nullptr;
    }
    Node(char value)
    {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};

class CharTree
{
private:
    int countLeafNodes(Node *nodePtr)
    {
        if (nodePtr == nullptr)
            return 0;
        if (nodePtr)
        {
            if (nodePtr->left == nullptr && nodePtr->right == nullptr)
                return 1;
        }
        return countLeafNodes(nodePtr->left) + countLeafNodes(nodePtr->right);
    }

    void printDescending(Node *nodePtr)
    {
        if (nodePtr)
        {
            printDescending(nodePtr->right);
            cout << (nodePtr->value) << " ";
            printDescending(nodePtr->left);
        }
    }

public:
    Node *root; // Root Pointer
    CharTree()
    {
        root = nullptr;
    }

    // ---------- FUNCTIONS ---------- //
    void insert(Node *&nodePtr, Node *newNode)
    {
        if (nodePtr == nullptr)
        {
            nodePtr = newNode;
        }
        else if (newNode->value < nodePtr->value)
        {
            insert(nodePtr->left, newNode);
        }
        else
        {
            insert(nodePtr->right, newNode);
        }
    }
    void insertNode(char value)
    {
        Node *newNode = nullptr;
        newNode = new Node;
        newNode->value = value;
        newNode->left = newNode->right = nullptr;

        insert(root, newNode);
    }

    bool searchValue(char value)
    {

        Node *nodePtr = root;

        while (nodePtr)
        {
            if (nodePtr->value == value)
            {
                cout << "TRUE" << endl
                     << endl;
                return true;
            }
            else if (value < nodePtr->value)
            {
                nodePtr = nodePtr->left;
            }
            else
            {
                nodePtr = nodePtr->right;
            }
        }
        cout << "FALSE" << endl
             << endl;
        return false;
    }

    char findMax()
    {
        Node *nodePtr = root;

        while (nodePtr->right != nullptr)
        {
            nodePtr = nodePtr->right;
        }
        return nodePtr->value;
    }

    int countLeafNodes()
    {
        return countLeafNodes(root);
    }

    void printDescending()
    {
        printDescending(root);
    }

    void displayInOrder(Node *nodePtr)
    {
        if (nodePtr)
        {
            displayInOrder(nodePtr->left);
            cout << (nodePtr->value) << " ";
            displayInOrder(nodePtr->right);
            return;
        }
    }

    void printSubtree(char value)
    {
        Node *nodePtr = root;
        while (nodePtr)
        {
            if (nodePtr->value == value)
            {
                if (nodePtr->left)
                {
                    displayInOrder(nodePtr->left);
                }
                cout << (nodePtr->value) << " ";
                if (nodePtr->right)
                {
                    displayInOrder(nodePtr->right);
                }
                return;
            }
            else if (value < nodePtr->value)
                nodePtr = nodePtr->left;
            else
                nodePtr = nodePtr->right;
        }
    }
};

// ---------- MAIN ---------- //
int main()
{
    CharTree tree;
    int option;
    string userInput;

    do
    {
        cout << "--------------------" << endl
             << "    Binary Tree" << endl
             << "--------------------" << endl
             << "1. Create Tree" << endl
             << "2. Search Value" << endl
             << "3. Find Max" << endl
             << "4. Count Leaf Nodes" << endl
             << "5. Print Descending Order" << endl
             << "6. Print Subtree" << endl
             << "7. Quit" << endl
             << "--------------------" << endl
             << "Enter Option: ";

        Node *newNode = new Node();

        cin >> option;

        switch (option)
        {
            // ----- CREATE TREE ----- //
        case 1:
        {
            cin.ignore();
            cout << "Enter Value: ";
            getline(cin, userInput);
            for (int i = 0; i < int(userInput.length()); i++)
            {
                char value = userInput[i];
                tree.insertNode(userInput[i]);
            }

            break;
        }

            // ----- SEARCH VALUE ----- //
        case 2:
        {
            char value;
            cout << "Enter Character to Search for: ";
            cin >> value;
            tree.searchValue(value);
            break;
        }

            // ----- FIND MAX ----- //
        case 3:
        {
            cout << "Max Value: " << tree.findMax() << endl
                 << endl;
            break;
        }

            // ----- COUNT LEAF NODES ----- //
        case 4:
        {
            cout << "Leaf Nodes: " << tree.countLeafNodes() << endl;
            break;
        }

            // ----- PRINT DESCENDING ORDER ----- //
        case 5:
        {
            cout << "Descending: ";
            tree.printDescending();
            cout << endl;
            break;
        }

            // ----- PRINT SUBTREE ----- //
        case 6:
        {
            char value;
            cout << "Enter Value To Print Subtree: ";
            cin >> value;
            cout << "Subtree: [ ";
            tree.printSubtree(value);
            cout << "]" << endl;
            break;
        }

            // ----- LOGOUT ----- //
        case 7:
        {
            cout << "--------------------" << endl
                 << "      Goodbye!" << endl
                 << "--------------------" << endl;
            break;
        }

            // ----- DEFAULT ----- //
        default:
        {
            cout << "Please Enter a Valid Option" << endl;
            return 0;
        }
        }
    } while (option != 7);

    return 0;
}