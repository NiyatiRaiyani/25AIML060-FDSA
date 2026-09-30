#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

void enqueue(int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if(rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }

    cout << value << " inserted" << endl;
}

void dequeue()
{
    if(front == NULL)
    {
        cout << "Queue Underflow" << endl;
    }
    else
    {
        Node* temp = front;

        cout << front->data << " deleted" << endl;

        front = front->next;

        if(front == NULL)
            rear = NULL;

        delete temp;
    }
}

void display()
{
    if(front == NULL)
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        Node* temp = front;

        cout << "Queue elements: ";

        while(temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    dequeue();

    display();

    return 0;
}
