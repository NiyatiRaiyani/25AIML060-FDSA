6/*Implement a queue data structure using a singly linked list with the following operations:

enqueue(x): Adds element x to the rear of the queue.
dequeue(): Removes and returns the front element of the queue. If the queue is empty, return -1.
peek(): Returns the front element of the queue without removing it. If the queue is empty, return -1.
isEmpty(): Returns 1 if the queue is empty, otherwise returns 0.
Input Format

The first line of input contains an integer n, the number of operations.
Each of the next n lines contains an integer representing the operation:
1 x for enqueue operation where x is the element to be added.
2 for dequeue operation.
3 for peek operation.
4 for isEmpty operation.
Constraints

-

Output Format

For each dequeue(), peek(), and isEmpty() operation, print the result on a new line:
dequeue(): Print the dequeued value or -1 if the queue is empty.
peek(): Print the front value or -1 if the queue is empty.
isEmpty(): Print 1 if the queue is empty, otherwise print 0.
For the enqueue(x) operation, no output is produced.
Sample Input 0

12
1 5
1 15
1 25
3
2
2
3
2
2
4
2
1 35
Sample Output 0

5
5
15
25
25
-1
1
-1*/
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

Node* front = NULL;
Node* rear = NULL;

void enqueue(int x) {
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

int dequeue() {
    if (front == NULL)
        return -1;

    Node* temp = front;
    int value = temp->data;

    front = front->next;

    if (front == NULL)
        rear = NULL;

    delete temp;
    return value;
}

int peek() {
    if (front == NULL)
        return -1;

    return front->data;
}

int isEmpty() {
    return (front == NULL) ? 1 : 0;
}

int main() {
    int n, operation, x;
    cin >> n;

    while (n--) {
        cin >> operation;

        if (operation == 1) {
            cin >> x;
            enqueue(x);
        }
        else if (operation == 2) {
            cout << dequeue() << endl;
        }
        else if (operation == 3) {
            cout << peek() << endl;
        }
        else if (operation == 4) {
            cout << isEmpty() << endl;
        }
    }

    return 0;
}
