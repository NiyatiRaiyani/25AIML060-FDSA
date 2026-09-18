/*
A group of students is sitting in a circle and playing a passing game. A token starts with the first student and can be passed from one student to the next around the circle.

Students may join the circle at any position and may leave the circle at any time. After every operation, the students must still form a valid circular linked list, meaning the last student must always point back to the first student.

You are given a sequence of operations to perform on the circle.

Your task is to implement the operations using:

Singly Circular Linked List Doubly Circular Linked List

After every operation, display the current students in clockwise order starting from the first student.

Input Format

The first line contains an integer N, the initial number of students.

The second line contains N space-separated integers representing the initial students in clockwise order.

The third line contains an integer Q, the number of operations.

The next Q lines contain one operation in one of the following formats:

JOIN student position LEAVE student DISPLAY

Constraints

1 ≤ N ≤ 1000 1 ≤ Q ≤ 1000 1 ≤ student ≤ 10^5 1 ≤ position ≤ 10^5

Output Format

For every DISPLAY operation, print the students in clockwise order starting from the first student.

For an empty circle, print:

Sample Input 0

5
10 20 30 40 50
7
DISPLAY
JOIN 25 3
DISPLAY
LEAVE 30
DISPLAY
LEAVE 10
DISPLAY
Sample Output 0

10 20 30 40 50
10 20 25 30 40 50
10 20 25 40 50
20 25 40 50
Sample Input 1

5
10 20 30 40 50
7
DISPLAY
JOIN 5 1
DISPLAY
JOIN 25 4
DISPLAY
JOIN 60 100
DISPLAY
Sample Output 1

10 20 30 40 50
5 10 20 30 40 50
5 10 20 25 30 40 50
5 10 20 25 30 40 50 60
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void joinStudent(int value, int position) {
    Node* newNode = new Node;
    newNode->data = value;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    int count = 1;
    Node* temp = head;

    while (temp->next != head) {
        count++;
        temp = temp->next;
    }

    if (position > count + 1) {
        position = count + 1;
    }

    if (position == 1) {
        newNode->next = head;

        temp->next = newNode;
        head = newNode;
        return;
    }

    temp = head;

    for (int i = 1; i < position - 1; i++) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void leaveStudent(int value) {
    if (head == NULL) {
        return;
    }

    Node* current = head;
    Node* previous = NULL;

    if (head->data == value) {

        if (head->next == head) {
            delete head;
            head = NULL;
            return;
        }

        Node* last = head;

        while (last->next != head) {
            last = last->next;
        }

        head = head->next;
        last->next = head;

        delete current;
        return;
    }

    previous = head;
    current = head->next;

    while (current != head && current->data != value) {
        previous = current;
        current = current->next;
    }

    if (current == head) {
        return;
    }

    previous->next = current->next;
    delete current;
}

void display() {
    if (head == NULL) {
        cout << "EMPTY" << endl;
        return;
    }

    Node* temp = head;

    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    cout << endl;
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int value;
        cin >> value;
        joinStudent(value, i + 1);
    }

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        string operation;
        cin >> operation;

        if (operation == "JOIN") {
            int student, position;
            cin >> student >> position;

            joinStudent(student, position);
        }
        else if (operation == "LEAVE") {
            int student;
            cin >> student;

            leaveStudent(student);
        }
        else if (operation == "DISPLAY") {
            display();
        }
    }

    return 0;
}