#include <iostream>
using namespace std;

class Stack {
    int arr[100];
    int top;
    int capacity;

public:
    Stack(int n) {
        capacity = n;
        top = -1;
    }

    void push(int tray) {
        // Check overflow
        if (top == capacity - 1) {
            cout << "Error: Stack Overflow" << endl;
            return;
        }

        arr[++top] = tray;
        cout << "Top tray: " << arr[top] << endl;
    }

    void pop() {
        // Check underflow
        if (top == -1) {
            cout << "Error: Stack Underflow" << endl;
            return;
        }

        cout << "Removed tray: " << arr[top] << endl;
        top--;

        if (top == -1)
            cout << "Top tray: Empty" << endl;
        else
            cout << "Top tray: " << arr[top] << endl;
    }
};

int main() {
    int n, operations;

    cout << "Enter stack capacity: ";
    cin >> n;

    Stack s(n);

    cout << "Enter number of operations: ";
    cin >> operations;

    for (int i = 0; i < operations; i++) {
        int choice, tray;

        cout << "\n1. Place tray (Push)" << endl;
        cout << "2. Take tray (Pop)" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter tray number: ";
            cin >> tray;
            s.push(tray);
        }
        else if (choice == 2) {
            s.pop();
        }
        else {
            cout << "Invalid operation" << endl;
        }
    }

    return 0;
}