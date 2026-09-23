#include<iostream>
#define MAX 6
using namespace std;

int stack[MAX];
int top = -1;

void push(int value)
{
    if(top == MAX-1)
        cout << "Stack Overflow " << endl;
    else
    {
        stack[++top]=value;
        cout << value << " pushed" << endl;
    }
}

void pop()
{
    if(top == -1)
        cout << "Stack Underflow " << endl;
    else
    {
        cout << stack[top] << " popped" << endl;
        top--;
    }
}

void display()
{
    if (top == -1)
        cout << "Stack is empty" << endl;
    else
    {
        cout << "Stack elements: ";
        for (int i=top;i>=0;i--)
            cout << stack[i] << " ";
        cout << endl;
    }
}

int main()
{
    push(10);
    push(20);
    push(30);

    display();

    pop();

    display();

    return 0;
}
