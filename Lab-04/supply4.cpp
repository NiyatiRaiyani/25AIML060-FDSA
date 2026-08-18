#include <iostream>
using namespace std;

struct Node {
    int frame;
    Node* next;

    Node(int value) {
        frame = value;
        next = nullptr;
    }
};

void insertEnd(Node*& head, int frame) {
    Node* newNode = new Node(frame);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
}

void display(Node* head) {
    while (head != nullptr) {
        cout << head->frame;

        if (head->next != nullptr)
            cout << " -> ";

        head = head->next;
    }

    cout << endl;
}

void reverseList(Node*& head) {
    Node* previous = nullptr;
    Node* current = head;

    while (current != nullptr) {
        Node* nextNode = current->next;

        current->next = previous;
        previous = current;
        current = nextNode;
    }

    head = previous;
}

int main() {
    Node* head = nullptr;

    int n, frame;

    cout << " Film Frame Sequence " << endl;

    cout << "Enter number of frames: ";
    cin >> n;

    cout << "Enter frame numbers: ";

    for (int i = 0; i < n; i++) {
        cin >> frame;
        insertEnd(head, frame);
    }

    cout << "\nOriginal sequence: ";
    display(head);

    reverseList(head);

    cout << "Reversed sequence: ";
    display(head);

    return 0;
}