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
void push(Node** top, int input);
void pop(Node* top);
void display(Node* top);

void push(Node** top, int input)
{

    if ((*top) == NULL) // Check if the stack is empty
    { // If the stack is empty, assign values to TOP


        Node* newNode = new Node();

        newNode->next = NULL;
        newNode->prev = NULL;
        newNode->data = input;

        (*top) = newNode;

        cout << "Pushing first node data " << (*top)->data << endl;

    }

    else { // If the stack is not empty, then add a new node

        Node *newNode = new Node();

        newNode->next = NULL;
        (*top)->next = newNode;
        newNode->prev = (*top);
        newNode->data = input;

        (*top) = newNode;

        cout << "Pushing data " << (*top)->data << endl;

    }

}


void pop(Node** top)
{

    cout << "Popping from top" << endl;

    Node* temp = (*top);

    (*top) = (*top)->prev;
    (*top)->next = NULL;

    delete temp;

}


void display(Node* top)
{

    Node* current = top;

    while (current != NULL)
    {

        cout << current->data << " ";
        current = current->prev;


    }

    cout << endl;

}


int main()
{

    Node* top = NULL; // Create the first node


    // Insert
    /////////////////////////////////////////////////////////////

    push(&top, 3);
    push(&top, 9);
    push(&top, 7);

    display(top);


    /////////////////////////////////////////////////////////////


    // Delete
    /////////////////////////////////////////////////////////////

    pop(&top);
    pop(&top);

    display(top);
    //cout << endl;

    /////////////////////////////////////////////////////////////


    // Display
    /////////////////////////////////////////////////////////////

    display(top);

    /////////////////////////////////////////////////////////////


    return 0;
}
