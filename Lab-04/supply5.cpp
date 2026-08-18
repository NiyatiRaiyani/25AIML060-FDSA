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

void checkPalindrome(Node* head, int n) {
    if (head == nullptr) {
        cout << "Yes" << endl;
        return;
    }

    // Compare first and last characters
    for (int i = 0; i < n / 2; i++) {

        Node* left = head;
        Node* right = head;

        for (int j = 0; j < i; j++)
            left = left->next;

        for (int j = 0; j < n - i - 1; j++)
            right = right->next;

        if (left->data != right->data) {
            cout << "No" << endl;
            return;
        }
    }

    cout << "Yes" << endl;
}

int main() {
    Node* head = nullptr;
    int n;
    char ch;

    cout << "===== Palindrome Message =====" << endl;

    cout << "Enter number of characters: ";
    cin >> n;

    cout << "Enter characters: ";

    for (int i = 0; i < n; i++) {
        cin >> ch;
        insertEnd(head, ch);
    }

    cout << "Palindrome: ";
    checkPalindrome(head, n);

    return 0;
}