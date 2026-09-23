#include<iostream>
#define MAX 5
using namespace std;

int stack[MAX];
int top = -1;

void push(int value)
{
    if(top == MAX-1)
        cout << "Stack Overflow. Cannot push." << endl;
    else
    {
        stack[++top]=value;
        cout << "Tray " << value << " placed." << endl;
        cout << "Current Top: " << stack[top] << endl;
    }
}

void pop()
{
    if(top == -1)
    {
        cout << "Stack Underflow. Cannot take tray." << endl;
    }
    else
    {
        cout << "Tray " << stack[top] << " taken." << endl;
        top--;

        if(top == -1)
        {
            cout << "Stack is Empty!" << endl;
        }
        else
        {
            cout << "Current Top: " << stack[top] << endl;
        }
    }
}

void display()
{
    if (top == -1)
    {
        cout << "Stack is Empty!" << endl;
    }
    else
    {
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--)
        {
            cout << stack[i] << " ";
        }
        cout << endl;
        cout << "Current Top: " << stack[top] << endl;
    }
}

int main()
{
    int choice, value;
    while(true)
    {
        cout << "\n1. Push (Place Tray)" << endl;
        cout << "2. Pop (Take Tray)" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                push(value);
                break;
            case 2:
                pop();
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
