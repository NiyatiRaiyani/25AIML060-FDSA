#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(Node* &head, int value) {
    Node* newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void deleteKthFromEnd(Node* &head, int k) {
    if (head == NULL)
        return;

    Node *fast = head, *slow = head;

    // Move fast pointer k steps ahead
    for (int i = 0; i < k; i++) {
        if (fast == NULL) {
            cout << "Invalid value of k!" << endl;
            return;
        }
        fast = fast->next;
    }

    // If k == length, delete first node
    if (fast == NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    while (fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    Node* temp = slow->next;
    slow->next = temp->next;
    delete temp;
}

void display(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    int n, value, k;

    cout << "Enter number of coaches: ";
    cin >> n;

    cout << "Enter coach numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        insertEnd(head, value);
    }

    cout << "Enter k: ";
    cin >> k;

    deleteKthFromEnd(head, k);

    cout << "Remaining coaches: ";
    display(head);

    return 0;
}
