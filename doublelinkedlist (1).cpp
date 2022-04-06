#include <iostream>

using namespace std;

// Doubly linked list node
class Node{

public:
    int data;
    Node* next; // Node coming next
    Node* prev; // The previous node

private:

};


int main()
{

    Node* head = NULL;

    int n; // Size of the doubly linked list
    int input;

    cout << "Specify size of the doubly linked list: ";
    cin >> n;

    head = new Node(); // Create a new node

    cout << "Input data for the head node: ";
    cin >> head->data;
    head->prev = NULL;
    head->next = NULL;


    //////////////////////////////////////////////////////////////////////////////////
    // Insertion from the beginning
    for (int i = 1; i < n; i ++)
    {

        Node* temp = new Node(); // Create a brand new node
        cout << "Created new node at beginning, input data for new node: ";
        cin >> input;
        cout << endl;
        temp->data = input; // Inputting data into our new node

        temp->next = head; // Setting the next value as the original head
        temp->prev = NULL; // Set the previous node to NULL

        head->prev = temp; // Set the previous of the original head to the new head

        head = temp; // Set the new head

    }
    //////////////////////////////////////////////////////////////////////////////////


    // Print items from our linked list
    Node* current = head;
    while(current != NULL) // Continues looping until the current node is NULL
    {

        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;


    cout << "\nDeleting the end node" << endl;
    //////////////////////////////////////////////////////////////////////////////////
    // Deletion from the end
    Node* temp = head;
    Node* tempPrev = NULL;

    // Iterate to the end of the linked list
    for (int i = 1; i < n; i ++ )
    {
        temp = temp->next;
    }

    // At this point, temp is at the last node
    tempPrev = temp->prev; // Saves second-to-last node
    tempPrev->next = NULL; // Sets second-to-last node NEXT to NULL

    delete temp; // Deletes the last node

    //////////////////////////////////////////////////////////////////////////////////


    // Print items from our linked list
    current = head;
    while(current != NULL) // Continues looping until the current node is NULL
    {

        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;


    // Insert from the beginning
    //////////////////////////////////////////////////////////////////////////////////
    cout << "\nInput a value to insert from the beginning: ";
    cin >> input;

    temp = new Node();
    temp->data = input; // Assign data for new node
    temp->prev = NULL; // Set prev of new node to NULL
    temp->next = head; // Set next of new node to HEAD

    head->prev = temp; // Set prev of HEAD to new node
    head = temp; // Set the new node as the HEAD
    //////////////////////////////////////////////////////////////////////////////////


    // Print items from our linked list
    current = head;
    while(current != NULL) // Continues looping until the current node is NULL
    {

        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;


    return 0;
}
