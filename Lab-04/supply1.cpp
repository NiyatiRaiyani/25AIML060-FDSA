#include <iostream>
using namespace std;

struct Node {
    int coach;
    Node* next;

    Node(int value) {
        coach = value;
        next = nullptr;
    }
};

void insertEnd(Node*& head, int coach) {
    Node* newNode = new Node(coach);

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
    cout << "Train: ";

    while (head != nullptr) {
        cout << head->coach;

        if (head->next != nullptr)
            cout << " -> ";

        head = head->next;
    }

    cout << endl;
}

void removeKthFromEnd(Node*& head, int k) {
    if (head == nullptr || k <= 0) {
        cout << "Invalid value of k." << endl;
        return;
    }

    Node* fast = head;
    Node* slow = head;

    // Move fast pointer k positions ahead
    for (int i = 0; i < k; i++) {
        if (fast == nullptr) {
            cout << "k is greater than the number of coaches." << endl;
            return;
        }

        fast = fast->next;
    }

    // k equals total number of coaches
    if (fast == nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    // Move both pointers until fast reaches the last node
    while (fast->next != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }

    Node* deleteNode = slow->next;
    slow->next = deleteNode->next;
    delete deleteNode;
}

int main() {
    Node* head = nullptr;

    int n, coach, k;

    cout << "      Train Coach Management " << endl;

    cout << "Enter number of coaches: ";
    cin >> n;

    cout << "Enter coach numbers: ";

    for (int i = 0; i < n; i++) {
        cin >> coach;
        insertEnd(head, coach);
    }

    cout << "\nOriginal train: ";
    display(head);

    cout << "Enter k (position from rear): ";
    cin >> k;

    removeKthFromEnd(head, k);

    cout << "After removing coach: ";
    display(head);

    return 0;
}