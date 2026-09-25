/*
Given the head of a singly linked list, reverse the list, and return the reversed list.

image

Input Format

First line contain the total number of nodes in linked list N:
Second line contain the values of all nodes in linked list
Constraints

0< N <=30
Output Format

The output line prints the reverse linked list
Sample Input 0

5
1 2 3 4 5
Sample Output 0

5 4 3 2 1 
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
    Node* next;
};

void insert(Node*& head, int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void reverseList(Node*& head)
{
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
}

void display(Node* head)
{
    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    int n;
    cin >> n;

    Node* head = NULL;

    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        insert(head, value);
    }

    reverseList(head);

    display(head);
   
    return 0;
}
