#include <iostream>

using namespace std;


class Node{

public:
    int data;
    Node* next;

private:

};


int main()
{

    Node* head = NULL;

    //Creating a new node

    int n;

    //We need to create a linked list of size n;

    cout << "Please enter a value for n: ";
    cin >> n;

    // Creating our nodes
    //////////////////////////////////////////////////////////////////////////////////
    head = new Node();
    cout << "Creating node 1" << endl;

    Node* current = head; // Start off with the current node being the head
    for(int i = 1; i < n; i++)
    {
        cout << "Creating node " << i + 1 << endl;
        Node* temp = new Node(); // Creating new node
        temp->next = NULL; //Set the newest node's NEXT to NULL (because there is no next node after the newest node)
        current->next = temp;   // Connecting newest node to our current node
        current = current->next; // Updating current to the latest node

    }
    //////////////////////////////////////////////////////////////////////////////////


    // Verify that our linked list works

    // Save sample data to our linked list
    current = head; // setting current node to HEAD
    int i = 0;
    while(current != NULL) // Continues looping until current is NULL
    {

        current->data = i; // Assigning data to current -> data
        i++;
        current = current->next; // Moving current to the next node

    }


    // Print items from our linked list
    current = head;
    while(current != NULL) // Continues looping until the current node is NULL
    {

        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;



    // Deleting a node from the middle
    //////////////////////////////////////////////////////////////////////////////////
    Node* prev = NULL; // Node that is previous to the target node
    Node* temp = NULL; // Node that we are targeting to delete

    temp = head;

    int position;

    cout << "Pick a node to delete from 0 - " << n << ": ";
    cin >> position;
    cout << endl;

    // If deleting the first node in the linked list
    if (position == 0)
    {
       head = temp->next;
       delete temp; // Deletes the node stored at temp
    }

    else {

        int i = 0;

        while(i != position) // Iterate through the linked list to the position right before the targeted node
        {
            prev = temp; // Save the node before the targeted position
            temp = temp->next; // Set temp to the target position
            i++;

        }

        prev->next = temp->next; // Link the prev node to the node succeeding the target
        delete temp; // Delete the targeted node
        cout << "Deleted node " << i + 1 << endl;
        n -- ; // Decrement the size counter of the linked list

    }


    //////////////////////////////////////////////////////////////////////////////////


    // Print items from our linked list
    current = head;
    while(current != NULL) // Continues looping until the current node is NULL
    {

        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;


    // Adding to the middle of linked list
    //////////////////////////////////////////////////////////////////////////////////
    int input;
    temp = head;

    cout << "Enter a value to be inserted: ";
    cin >> input;
    cout << "Pick a node to insert after from 0 - " << n << ": ";
    cin >> position;

    Node* newNode = new Node();
    newNode->data = input;


    if (position == 0) // If user wants to add to the beginning of the linked list
    {
       newNode->next = head; // Set head as the next node (second node now)
       head = newNode; // Set the temp node as the new head
    }

    else {

        int i = 0;

        while(i != position - 1) // Iterate through the linked list to the position right before the targeted node
        {
            temp = temp->next; // Set temp to the target position
            i++;

        }

        newNode->next = temp->next; // Set the new node to be the node after temp
        temp->next = newNode; // Set the next node after temp to be the new node

        cout << "Added value " << input << " at position " << n << endl;
        n ++ ; // Increment the size counter of the linked list

    }

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
