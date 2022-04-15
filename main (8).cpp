#include <iostream>

using namespace std;



class Node {
public:
    int data;
    Node* next;
    Node* prev;
private:

};

// We can make three different functions for pop, push, and display
void Insert(Node** queueFront, Node** queueBack, int input);
void Delete(Node** queueFront);
void Display(Node* queueFront);

void Insert(Node** queueFront, Node** queueBack, int input)
{

    if ( (*queueFront) == NULL) // Check if the queue is empty
    { // If the queue is empty, assign values to TOP

        //top = new Node*();

        Node *newNode = new Node(); // Creating a new node
        newNode->next = NULL; // Setting new node next to NULL
        newNode->prev = NULL; // Setting new node prev to NULL
        newNode->data = input; // Adding data

        (*queueFront) = newNode; // The new node is the FRONT and BACK of the queue since it is the only node there
        (*queueBack) = newNode;

        cout << "Inputting first node data " << (*queueFront)->data << endl;


    }

    else { // If the queue is not empty, then add a new node

        Node *newNode = new Node(); // New node

        newNode->next = NULL; // New node NEXT is NULL
        (*queueBack)->next = newNode; // Link previous node to new node
        newNode->prev = (*queueBack); // Link new node backwards to previous node
        newNode->data = input; // Add data

        (*queueBack) = newNode; // Add new the node to the back of the queue

        cout << "Inputting data " << (*queueBack)->data << endl;


    }

}


void Delete(Node** queueFront)
{

    Node *temp = (*queueFront);
    (*queueFront) = (*queueFront)->next;
    (*queueFront)->prev = NULL;

    cout << "Deleting from the front of the queue" << endl;

    delete temp;

}


void Display(Node* queueFront)
{
    Node *current = queueFront;

    while(current != NULL)
    {

        cout << current->data << " "; // Printing out the data at current node

        current = current->next; // Moving through the linked list

    }

    cout << endl;
}


int main()
{

    Node *queueFront = NULL; // Create the first node
    Node *queueBack = NULL;


    // Insert
    /////////////////////////////////////////////////////////////

    Insert(&queueFront, &queueBack, 3);

    Insert(&queueFront, &queueBack, 9);

    Insert(&queueFront, &queueBack, 20);

    Insert(&queueFront, &queueBack, 13);

    Insert(&queueFront, &queueBack, 42);

    Insert(&queueFront, &queueBack, 26);

    Insert(&queueFront, &queueBack, 23);

    Display(queueFront);

    /////////////////////////////////////////////////////////////


    // Delete
    /////////////////////////////////////////////////////////////

    Delete(&queueFront);

    Display(queueFront);

    Delete(&queueFront);

    Display(queueFront);

    Delete(&queueFront);

    Display(queueFront);

    /////////////////////////////////////////////////////////////


    // Display
    /////////////////////////////////////////////////////////////

    Display(queueFront);

    /////////////////////////////////////////////////////////////


    return 0;
}
