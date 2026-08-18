#include <iostream>
using namespace std;

struct Node {
    int id;
    Node* next;

    Node(int value) {
        id = value;
        next = nullptr;
    }
};

void insertEnd(Node*& head, int id) {
    Node* newNode = new Node(id);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
}

void displayMiddle(Node* head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    cout << "Middle Runner ID: " << slow->id << endl;
}

int main() {
    Node* head = nullptr;
    int n, id;

    cout << "===== Relay Race =====" << endl;

    cout << "Enter number of runners: ";
    cin >> n;

    cout << "Enter runner IDs: ";

    for (int i = 0; i < n; i++) {
        cin >> id;
        insertEnd(head, id);
    }

    displayMiddle(head);

    return 0;
}