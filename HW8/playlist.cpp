/* 
    Program Name: Playlist (playlist.cpp)
    Compile: c++ playlist.cpp -o playlist
    Author: Malachi Payne
    Course: COMP B12
    Date: 10.28.2020
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Node
{
private:
    string songName;
    int songYear;
    double songLength;
    Node *next;
    Node *prev;

public:
    // ----- CONSTRUCTORS ----- //
    Node() // Default Constructor
    {
        songName = "Unassigned";
        songYear = 0;
        songLength = 0.0;
        next = nullptr;
        prev = nullptr;
    }
    Node(string songName, int songYear, double songLength) // Overloaded Constructor
    {
        this->songName = songName;
        this->songYear = songYear;
        this->songLength = songLength;
        next = nullptr;
        prev = nullptr;
    }

    // ----- PRINT NODE FUNCTION ----- //
    void printNode()
    {
        cout << songName << endl
             << songYear << endl
             << songLength << endl
             << endl;
    }

    // ----- SETTER FUNCTIONS ----- //
    void setSongName(string songName)
    {
        this->songName = songName;
    }

    void setSongYear(int songYear)
    {
        this->songYear = songYear;
    }

    void setSongLength(double songLength)
    {
        this->songLength = songLength;
    }

    void setNext(Node *nextNode)
    {
        next = nextNode;
    }
    void setPrev(Node *previousNode)
    {
        prev = previousNode;
    }

    // ----- GETTER FUNCTIONS ----- //
    string getSongName()
    {
        return songName;
    }

    int getSongYear()
    {
        return songYear;
    }

    double getSongLength()
    {
        return songLength;
    }

    Node *getNext()
    {
        return next;
    }
    Node *getPrev()
    {
        return prev;
    }
};

class List
{
private:
    Node *head; // List Head Pointer
public:
    List() // Default Constructor
    {
        head = nullptr;
    }

    // ----- APPEND NODE FUNCTION ----- //
    void insertToBack(Node *newNode)
    {
        Node *nodePtr;

        if (!head)
        {
            head = newNode;
        }
        else
        {
            nodePtr = head;

            while (nodePtr->getNext() != nullptr)
            {
                nodePtr = nodePtr->getNext();
            }
            nodePtr->setNext(newNode);
            newNode->setPrev(nodePtr);
        }
    }

    // ----- DELETE FIRST NODE FUNCTION ----- //
    void deleteFront()
    {
        Node *nodePtr;

        if (!head) // if the list is empty
        {
            cout << "No nodes to delete" << endl;
        }
        else
        {
            nodePtr = head;         // Assign temp node pointer to head pointer
            head = head->getNext(); // Move head pointer to next node
            head->setPrev(nullptr); // set the previous pointer of head to null
            delete (nodePtr);       // Delete the first node
        }
    }

    // ----- FIND THE OLDEST SONG FUNCTION ----- //
    Node *findOldestSong()
    {

        if (!head) // if the list is empty
        {
            cout << "No songs in list" << endl;
            return nullptr;
        }

        Node *oldestSong = head;
        Node *nodePtr = head;

        while (nodePtr != nullptr)
        {
            if (nodePtr->getSongYear() < oldestSong->getSongYear())
            {
                oldestSong = nodePtr;
            }

            nodePtr = nodePtr->getNext();
        }

        return oldestSong;
    }

    // ----- FIND THE LONGEST SONG FUNCTION ----- //
    Node *findLongestSong()
    {
        if (!head) // if the list is empty
        {
            cout << "No songs in list" << endl;
            return nullptr;
        }

        Node *longestSong = head;
        Node *nodePtr = head;

        while (nodePtr != nullptr)
        {
            if (nodePtr->getSongLength() > longestSong->getSongLength())
            {
                longestSong = nodePtr;
            }

            nodePtr = nodePtr->getNext();
        }

        return longestSong;
    }

    // ----- DELETE DUPLICATE NODES FUNCTION ----- //
    void deleteDuplicates()
    {
        if (!head)
        {
            cout << "No nodes to delete" << endl;
            return;
        }

        Node *OGNode = head;

        while (OGNode != nullptr && OGNode->getNext() != nullptr)
        {
            Node *duplicateNode = OGNode;

            while (duplicateNode->getNext() != nullptr)
            {
                if (
                    OGNode->getSongName() == duplicateNode->getNext()->getSongName() &&
                    OGNode->getSongYear() == duplicateNode->getNext()->getSongYear() &&
                    OGNode->getSongLength() == duplicateNode->getNext()->getSongLength())
                {

                    Node *duplicate = duplicateNode->getNext();
                    Node *next = duplicate->getNext();

                    if (next != nullptr)
                    {
                        next->setPrev(duplicateNode);
                    }

                    duplicateNode->setNext(next);

                    delete (duplicate);
                }
                else
                {
                    duplicateNode = duplicateNode->getNext();
                }
            }

            OGNode = OGNode->getNext();
        }
    }

    // ----- DELETE THE LIST OF NODES FUNCTION ----- //
    void deleteList()
    {
        // used stack for this: https://www.geeksforgeeks.org/stack-in-cpp-stl/

        stack<Node *> nodeStack;

        Node *nodePtr = head;
        while (nodePtr != nullptr) // inserting the nodes into the stack
        {
            nodeStack.push(nodePtr);
            nodePtr = nodePtr->getNext();
        }

        while (not nodeStack.empty()) // deleting the nodes
        {
            Node *const topNode = nodeStack.top();
            nodeStack.pop();
            cout << "Deleting... [" << topNode->getSongName() << "]" << endl;
            delete topNode;
        }

        head = nullptr;
    }

    // ----- PRINT LIST FUNCTION ----- //
    void printList()
    {
        int songNumber = 1;
        double playListDuration = 0.0;
        Node *nodePtr = head;
        cout << "CURRENT PLAYLIST" << endl;
        while (nodePtr != nullptr)
        {
            cout << "[SONG " << songNumber << "]" << endl;
            nodePtr->printNode();

            songNumber++;
            playListDuration += nodePtr->getSongLength();

            nodePtr = nodePtr->getNext();
        }

        cout << "Total Songs: " << songNumber - 1 << endl
             << "Playlist Duration: " << playListDuration << endl;
    }
};

// ---------- MAIN ---------- //
int main()
{
    List *playlist = new List();

    ifstream input_file;
    input_file.open("playlist.txt"); // Changed songs.txt to -> playlist.txt as this was the file proivided in the assignment

    string song;
    int year;
    double length;
    Node *newNode = nullptr;

    // Creates a node for each song in the txt file and inserts it to list
    while (!input_file.eof())
    {
        input_file >> song;
        input_file >> year;
        input_file >> length;
        newNode = new Node(song, year, length);
        playlist->insertToBack(newNode);
    }
    input_file.close();

    playlist->printList();

    /* Find oldest song in list */
    cout << endl;
    cout << "------------------------------" << endl;
    Node *oldestSong = playlist->findOldestSong();
    cout << "OLDEST SONG" << endl;
    oldestSong->printNode();

    /* Find longest song in list */
    cout << endl;
    cout << "------------------------------" << endl;
    Node *longestSong = playlist->findLongestSong();
    cout << "LONGEST SONG" << endl;
    longestSong->printNode();

    /* Delete first song in list (delete front node of the list) */
    cout << endl;
    cout << "------------------------------" << endl;
    playlist->deleteFront();
    cout << "DELETE FIRST SONG" << endl // ADDED THESE LINES FOR CLARITY WHEN PRINTING
         << endl;                       // ADDED THESE LINES FOR CLARITY WHEN PRINTING
    playlist->printList();

    /* Delete all duplicates in list */
    cout << endl;
    cout << "------------------------------" << endl;
    playlist->deleteDuplicates();
    cout << "DELETED DUPLICATES" << endl // ADDED THESE LINES FOR CLARITY WHEN PRINTING
         << endl;                        // ADDED THESE LINES FOR CLARITY WHEN PRINTING
    playlist->printList();

    /* Delete all songs in list */
    cout << endl;
    cout << "------------------------------" << endl;
    cout << "DELETE SONGS" << endl;
    playlist->deleteList();

    /* Extra function calls for empty list */
    cout << endl;
    playlist->deleteList();
    playlist->findLongestSong();

    return 0;
}