/*
Input Format

The first line contains an integer n, the number of elements in the linked list.
The next n lines contain an integer each, the value that needs to be inserted at tail.
The last line contains an integer, X, the data of the node to be deleted.
If that node with the value X is not available then return the DLL
Constraints

1 ≤ n ≤ 1000
1 ≤ list ≤ 1000
Output Format

n contains of Doubly Linked list

Sample Input 0

5
12
13
14
15
16
15
Sample Output 0

12 13 14 16
Explanation 0

Deleted the node with value 15

Sample Input 1

5
12
13
14
15
16
13
Sample Output 1

12 14 15 16
Explanation 1

Deleted the node with value 13

Sample Input 2

5
12
13
14
15
16
17
Sample Output 2

12 13 14 15 16
Explanation 2

Node with value 17 not found in DLL
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;

void insertAtEnd(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void deleteNode(int x) {
    if (head == NULL) {
        return;
    }

    Node* temp = head;

    while (temp != NULL && temp->data != x) {
        temp = temp->next;
    }

    if (temp == NULL) {
        return;
    }

    if (temp == head) {
        head = temp->next;

        if (head != NULL) {
            head->prev = NULL;
        }

        delete temp;
        return;
    }

    temp->prev->next = temp->next;

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    delete temp;
}

void display() {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main() {
    int n, value, x;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> value;
        insertAtEnd(value);
    }

    cin >> x;

    deleteNode(x);

    display();      
    return 0;
}
