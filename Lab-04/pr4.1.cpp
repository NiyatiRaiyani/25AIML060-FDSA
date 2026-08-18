#include <iostream>
using namespace std;

struct Node {
    int token;
    Node* next;

    Node(int value) {
        token = value;
        next = nullptr;
    }
};

// Insert at front
void insertFront(Node*& head, int token) {
    Node* newNode = new Node(token);
    newNode->next = head;
    head = newNode;
}

// Insert at end
void insertEnd(Node*& head, int token) {
    Node* newNode = new Node(token);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
}

// Insert at a specific position
void insertAtPosition(Node*& head, int token, int position) {
    if (position <= 0) {
        cout << "Invalid position." << endl;
        return;
    }

    if (position == 1) {
        insertFront(head, token);
        return;
    }

    Node* temp = head;

    for (int i = 1; i < position - 1 && temp != nullptr; i++)
        temp = temp->next;

    if (temp == nullptr) {
        cout << "Position is beyond the current queue length." << endl;
        return;
    }

    Node* newNode = new Node(token);
    newNode->next = temp->next;
    temp->next = newNode;
}

// Display queue
void display(Node* head) {
    if (head == nullptr) {
        cout << "Queue is empty." << endl;
        return;
    }

    cout << "Queue: ";

    while (head != nullptr) {
        cout << head->token;

        if (head->next != nullptr)
            cout << " -> ";

        head = head->next;
    }

    cout << endl;
}

int main() {
    Node* head = nullptr;
    int choice, token, position;

    cout << "===== Hospital Patient Token Queue =====" << endl;

    do {
        cout << "\n1. Insert Critical Patient at Front";
        cout << "\n2. Insert Routine Patient at End";
        cout << "\n3. Insert Priority Patient at Position";
        cout << "\n4. Display Queue";
        cout << "\n5. Exit";

        cout << "\n\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter patient token: ";
                cin >> token;

                insertFront(head, token);
                display(head);
                break;

            case 2:
                cout << "Enter patient token: ";
                cin >> token;

                insertEnd(head, token);
                display(head);
                break;

            case 3:
                cout << "Enter patient token: ";
                cin >> token;

                cout << "Enter position: ";
                cin >> position;

                insertAtPosition(head, token, position);
                display(head);
                break;

            case 4:
                display(head);
                break;

            case 5:
                cout << "Program ended." << endl;
                break;

            default:
                cout << "Invalid choice." << endl;
        }

    } while (choice != 5);

    return 0;
}