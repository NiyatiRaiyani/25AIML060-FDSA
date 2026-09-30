#include<iostream>
using namespace std;

struct Node
{
    int patient;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

void arrive(int patient)
{
    Node* newNode = new Node;

    newNode->patient = patient;
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

    cout << "Patient " << patient << " arrived." << endl;
    cout << "Current Front Patient: " << front->patient << endl;
}

void attend()
{
    // Queue is empty
    if(front == NULL)
    {
        cout << "Ward is Empty. No patient to attend." << endl;
    }
    else
    {
        Node* temp = front;

        cout << "Patient " << front->patient << " attended." << endl;

        front = front->next;

        // If queue becomes empty
        if(front == NULL)
            rear = NULL;

        delete temp;

        if(front != NULL)
            cout << "Current Front Patient: " << front->patient << endl;
        else
            cout << "Ward is Empty." << endl;
    }
}

void display()
{
    if(front == NULL)
    {
        cout << "Ward is Empty." << endl;
    }
    else
    {
        Node* temp = front;

        cout << "Patients in Queue: ";

        while(temp != NULL)
        {
            cout << temp->patient << " ";
            temp = temp->next;
        }

        cout << endl;
        cout << "Current Front Patient: " << front->patient << endl;
    }
}

int main()
{
    int choice, patient;

    while(true)
    {
        cout << "\n1. Arrive Patient" << endl;
        cout << "2. Attend Patient" << endl;
        cout << "3. Display Queue" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "Enter patient number: ";
                cin >> patient;
                arrive(patient);
                break;

            case 2:
                attend();
                break;

            case 3:
                display();
                break;

            case 4:
                cout << "Program ended.";
                return 0;

            default:
                cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
