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

void insertFront(Node*& head, int token) {
    Node* newNode = new Node(token);
    newNode->next = head;
    head = newNode;
}

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

void insertAtPosition(Node*& head, int token, int pos) {
    if (pos <= 0) {
        cout << "Invalid position." << endl;
        return;
    }

    if (pos == 1) {
        insertFront(head, token);
        return;
    }

    Node* temp = head;

    for (int i = 1; i < pos - 1 && temp != nullptr; i++)
        temp = temp->next;

    if (temp == nullptr) {
        cout << "Position is beyond the queue length." << endl;
        return;
    }

    Node* newNode = new Node(token);
    newNode->next = temp->next;
    temp->next = newNode;
}

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
    int choice, token, pos;

    cout << "      Hospital Patient Queue " << endl;

    do {
        cout << "\n1. Insert at Front";
        cout << "\n2. Insert at End";
        cout << "\n3. Insert at Position";
        cout << "\n4. Display Queue";
        cout << "\n5. Exit";

        cout << "\n\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter token: ";
                cin >> token;
                insertFront(head, token);
                display(head);
                break;

            case 2:
                cout << "Enter token: ";
                cin >> token;
                insertEnd(head, token);
                display(head);
                break;

            case 3:
                cout << "Enter token: ";
                cin >> token;
                cout << "Enter position: ";
                cin >> pos;
                insertAtPosition(head, token, pos);
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