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

// Insert patient at the end
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

// Delete patient by token value
void deleteByValue(Node*& head, int token) {
    if (head == nullptr) {
        cout << "Queue is empty." << endl;
        return;
    }

    // Delete first node
    if (head->token == token) {
        Node* temp = head;
        head = head->next;
        delete temp;

        cout << "Patient token deleted." << endl;
        return;
    }

    Node* temp = head;

    while (temp->next != nullptr && temp->next->token != token)
        temp = temp->next;

    if (temp->next == nullptr) {
        cout << "Patient token not found." << endl;
        return;
    }

    Node* deleteNode = temp->next;
    temp->next = deleteNode->next;
    delete deleteNode;

    cout << "Patient token deleted." << endl;
}

// Display queue from front to back
void displayForward(Node* head) {
    if (head == nullptr) {
        cout << "Queue is empty." << endl;
        return;
    }

    cout << "Front to Back: ";

    while (head != nullptr) {
        cout << head->token;

        if (head->next != nullptr)
            cout << " -> ";

        head = head->next;
    }

    cout << endl;
}

// Print queue from last to first
void displayReverse(Node* head) {
    if (head == nullptr)
        return;

    displayReverse(head->next);
    cout << head->token << " ";
}

int main() {
    Node* head = nullptr;
    int n, token, choice;

    cout << "      Hospital Patient Token Queue " << endl;

    cout << "Enter number of patients: ";
    cin >> n;

    cout << "Enter patient tokens: ";

    for (int i = 0; i < n; i++) {
        cin >> token;
        insertEnd(head, token);
    }

    do {
        cout << "\n1. Delete Patient by Token";
        cout << "\n2. Display Queue from Last to First";
        cout << "\n3. Display Queue from Front to Back";
        cout << "\n4. Exit";

        cout << "\n\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter token to delete: ";
                cin >> token;

                deleteByValue(head, token);
                displayForward(head);
                break;

            case 2:
                if (head == nullptr) {
                    cout << "Queue is empty." << endl;
                } else {
                    cout << "Last to First: ";
                    displayReverse(head);
                    cout << endl;
                }
                break;

            case 3:
                displayForward(head);
                break;

            case 4:
                cout << "Program ended." << endl;
                break;

            default:
                cout << "Invalid choice." << endl;
        }

    } while (choice != 4);

    return 0;
}