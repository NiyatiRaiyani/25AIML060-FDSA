/*
Implement Insert and Delete functions of a Doubly linked list.

Input Format

Input lines contain choices for insertion and deletions.
For example, 1. insert at front, 2. delete front, 3.display and 0 for exit.
For insertion functions, value must be given along with choice 1.
0 must be given at end of input.
Constraints

-

Output Format

Output will be data of linked list according to choice in input.
If no node in linked list, it must display a message "List is Empty"
Sample Input 0

1
25
1
36
1
89
3
0
Sample Output 0

89 36 25
Sample Input 1

1
23
1
34
1
56
1
67
3
2
3
0
Sample Output 1

67 56 34 23
56 34 23
Sample Input 2

3
0
Sample Output 2

List is Empty
Sample Input 3

1
23
1
67
2
3
0
Sample Output 3

23
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;

void insertFront(int value)
{
    Node* newNode = new Node;

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
    {
        head->prev = newNode;
    }

    head = newNode;
}

void deleteFront()
{
    if (head == NULL)
    {
        return;
    }

    Node* temp = head;

    head = head->next;

    if (head != NULL)
    {
        head->prev = NULL;
    }

    delete temp;
}

void display()
{
    if (head == NULL)
    {
        cout << "List is Empty" << endl;
        return;
    }

    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main() {
    int choice;

    while (cin >> choice)
    {
        if (choice == 0)
        {
            break;
        }

        if (choice == 1)
        {
            int value;
            cin >> value;

            insertFront(value);
        }
        else if (choice == 2)
        {
            deleteFront();
        }
        else if (choice == 3)
        {
            display();
        }
    }
    return 0;
}

/*
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;

// Insert at front
void insertFront(int value)
{
    Node* newNode = new Node;

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
    {
        head->prev = newNode;
    }

    head = newNode;
}

// Delete from front
void deleteFront()
{
    if (head == NULL)
    {
        return;
    }

    Node* temp = head;
    head = head->next;

    if (head != NULL)
    {
        head->prev = NULL;
    }

    delete temp;
}

// Display
void display()
{
    if (head == NULL)
    {
        cout << "List is Empty" << endl;
        return;
    }

    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main() {
     int choice;

    while (cin >> choice)
    {
        if (choice == 0)
        {
            break;
        }

        if (choice == 1)
        {
            int value;
            cin >> value;
            insertFront(value);
        }
        else if (choice == 2)
        {
            deleteFront();
        }
        else if (choice == 3)
        {
            display();
        }
    }

    return 0;
}

*/
