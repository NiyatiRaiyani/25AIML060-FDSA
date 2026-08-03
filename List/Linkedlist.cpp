#include<iostream>
using namespace std;

class Node 
{
public:
    int data;
    Node* next;

    Node(int val) 
    {
        data = val;
        next = NULL;
    }
};

class List 
{
    Node* head;
    Node* tail;
public:
    List() 
    {
        head = NULL;
        tail = NULL;

    }
    void push_front(int val) 
    {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        if (tail == NULL) 
        {
            tail = newNode;
        }
    }

    void push_back(int val) 
    {
        Node* newNode = new Node(val);
        if (tail != NULL) 
        {
            tail->next = newNode;
        }
        tail = newNode;
        if (head == NULL) 
        {
            head = newNode;
        }
    }
 
    void pop_front() 
    {
        if (head == NULL) 
        {
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        if (head == NULL) 
        {
            tail = NULL;
        }
    }
    
    void printList() 
    {
        Node* temp = head;
        while (temp != NULL) 
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() 
{
    List lst;
    lst.push_front(10);
    lst.push_front(20);
    lst.push_front(30);
    lst.push_back(40);
    lst.push_back(50);
    lst.printList();
    return 0;
}