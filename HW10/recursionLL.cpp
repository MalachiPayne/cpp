/* 
    Program Name: Recursion Linked List (recursionLL.cpp)
    Compile: c++ recursionLL.cpp -o recursionLL
    Author: Malachi Payne
    Course: COMP B12
    Date: 11.22.2020
*/

#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

// Note: given funcitons need correct return types (not given)

/* Node for Singly Linked List */
class Node
{
private:
    /* Your code here */
    Node *next;
    int data;

public:
    /* Your code here */
};

/* Singly Linked List */
class List
{
private:
    /* Your code here */
    Node *head; // List Head Pointer
public:
    // Constructor
    List() // Default Constructor
    {
        head = nullptr;
    }
    // get/set functions
    Node *getHead()
    {
        return head;
    }

    /* Prints list */
    void printList()
    {
        if (head == nullptr)
        {
            return;
        }

        Node *p = head;
        while (p != nullptr)
        {
            cout << p->getValue() << " ";
            p = p->getNext();
        }
        cout << endl;
    }

    /****
            Recursive Insert to back
            > Inserts a node to the back of the list
        *****/
    Node *insertToBack(/* Your code here */ Node *head, int x)
    {
        /* Your code here */
        if (head == nullptr)
        {
            return newNode(x);
        }
        else
        {
            head->next = insertToBack(head->next, x);
            return head;
        }
    }

    /****
            Recursive Sum
            > Sums all value in the list starting from the tail node
        *****/
    int sumList(Node *p)
    {
        if (/* Your code here */)
        {
            /* Your code here */
        }
        /* Your code here */
    }

    /****
            Recursive Delete
            > Deletes x amount of nodes in the list, starting from the front of the list
        *****/
    void deleteList(/* Your code here */ Node *head, int x)
    {
        if (p == nullptr)
        {
            /* Your code here */
            return nullptr;
        }
        if (/* Your code here */ x == 1)
        {
            /* Your code here */
            Node *nodePtr = head->next;
            delete (head);
            return nodePtr;
        }
        head->next = deleteList(head->next, x - 1);
        return head;
    }
};

int main()
{
    /*! DO NOT MODIFY CODE BELOW !*/

    srand(time(NULL));

    List *list = new List(); // Initialize new list
    Node *newNode;

    /* Inserts node to back of list */
    for (int i = 0; i < 6; i++)
    {
        newNode = new Node(rand() % 20);
        list->insertToBack(list->getHead(), newNode);
    }

    /* Print list */
    cout << endl;
    cout << "LIST: ";
    list->printList();
    cout << endl;

    /* Calculate sum of list */
    cout << "SUM: ";
    cout << list->sumList(list->getHead()) << endl;
    cout << endl;

    /* Delete x amount of nodes in list */
    cout << "DELETE" << endl;
    cout << "----------" << endl;
    list->deleteList(list->getHead(), 4);
    cout << "New List: ";
    list->printList();
}
