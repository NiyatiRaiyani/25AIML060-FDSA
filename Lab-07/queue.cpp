#include<iostream>
#define MAX 6
using namespace std;

int queue[MAX];
int front=-1;
int rear=-1;

void enqueue(int value)
{
    if(rear == MAX-1)
        cout << "Queue Overflow " << endl;
    else
    {
        if(front == -1)
            front = 0;

        queue[++rear] = value;
        cout << value << " inserted" << endl;
    }
}

void dequeue()
{
    if(front == -1 || front > rear)
        cout << "Queue Underflow " << endl;
    else
    {
        cout << queue[front] << " deleted" << endl;
        front++;

        if(front > rear)
        {
            front = -1;
            rear = -1;
        }
    }
}

void display()
{
    if(front == -1)
        cout << "Queue is empty" << endl;
    else
    {
        cout << "Queue elements: ";

        for(int i = front; i <= rear; i++)
            cout << queue[i] << " ";

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
