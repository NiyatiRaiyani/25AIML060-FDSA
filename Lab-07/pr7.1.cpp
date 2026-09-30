#include<iostream>
#define MAX 5
using namespace std;

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int value)
{
    if(rear == MAX-1)
    {
        cout << "Queue Overflow. Cannot issue token." << endl;
    }
    else
    {
        if(front == -1)
            front = 0;

        queue[++rear] = value;

        cout << "Token " << value << " issued." << endl;
        cout << "Current Front: " << queue[front] << endl;
    }
}

void dequeue()
{
    if(front == -1 || front > rear)
    {
        cout << "Queue Underflow. Cannot serve visitor." << endl;
    }
    else
    {
        cout << "Token " << queue[front] << " served." << endl;

        front++;

        if(front > rear)
        {
            front = -1;
            rear = -1;
            cout << "Queue is Empty!" << endl;
        }
        else
        {
            cout << "Current Front: " << queue[front] << endl;
        }
    }
}

void display()
{
    if(front == -1)
    {
        cout << "Queue is Empty!" << endl;
    }
    else
    {
        cout << "Queue elements: ";

        for(int i = front; i <= rear; i++)
        {
            cout << queue[i] << " ";
        }

        cout << endl;
        cout << "Current Front: " << queue[front] << endl;
    }
}

int main()
{
    int choice, value;

    while(true)
    {
        cout << "\n1. Enqueue (Join Queue)" << endl;
        cout << "2. Dequeue (Serve Visitor)" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "Enter token number: ";
                cin >> value;
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                cout << "Program ended.";
                return 0;

            default:
                cout << "Invalid choice!";
        }
    }

    return 0;
}
