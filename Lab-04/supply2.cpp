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

void display(Node* head) {
    while (head != nullptr) {
        cout << head->id;

        if (head->next != nullptr)
            cout << " -> ";

        head = head->next;
    }

    cout << endl;
}

void swapPairs(Node* head) {
    while (head != nullptr && head->next != nullptr) {

        int temp = head->id;
        head->id = head->next->id;
        head->next->id = temp;

        head = head->next->next;
    }
}

int main() {
    Node* head = nullptr;
    int n, id;

    cout << "===== Student Pair Swapping =====" << endl;

    cout << "Enter number of students: ";
    cin >> n;

    cout << "Enter student IDs: ";

    for (int i = 0; i < n; i++) {
        cin >> id;
        insertEnd(head, id);
    }

    cout << "\nOriginal order: ";
    display(head);

    swapPairs(head);

    cout << "After swapping pairs: ";
    display(head);

    return 0;
}