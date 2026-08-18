#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;

    Node(char value) {
        data = value;
        next = nullptr;
    }
};

void insertEnd(Node*& head, char value) {
    Node* newNode = new Node(value);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
}

bool isPalindrome(Node* head) {
    if (head == nullptr || head->next == nullptr)
        return true;

    Node* slow = head;
    Node* fast = head;

    // Find the middle of the list
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half
    Node* previous = nullptr;
    Node* current = slow;

    while (current != nullptr) {
        Node* nextNode = current->next;
        current->next = previous;
        previous = current;
        current = nextNode;
    }

    // Compare both halves
    Node* first = head;
    Node* second = previous;

    bool result = true;

    while (second != nullptr) {
        if (first->data != second->data) {
            result = false;
            break;
        }

        first = first->next;
        second = second->next;
    }

    return result;
}

int main() {
    Node* head = nullptr;

    int n;
    char ch;

    cout << "Palindrome Message " << endl;

    cout << "Enter number of characters: ";
    cin >> n;

    cout << "Enter characters: ";

    for (int i = 0; i < n; i++) {
        cin >> ch;
        insertEnd(head, ch);
    }

    if (isPalindrome(head))
        cout << "\nYes" << endl;
    else
        cout << "\nNo" << endl;

    return 0;
}