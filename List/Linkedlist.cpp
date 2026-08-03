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
            cout << "List is empty. Cannot pop from front." << endl;
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

    void pop_back()
    {
        if (tail == NULL)
        {
            cout << "List is empty. Cannot pop from back." << endl;
            return;
        }
        if (head == tail)
        {
            delete head;
            head = NULL;
            tail = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = NULL;
    }
    
    void insert(int val, int pos)
    {
        if (pos < 0)
        {
            cout << "Invalid position. Cannot insert." << endl;
            return;
        }
        if (pos == 0)
        {
            push_front(val);
            return;
        }
        Node* newNode = new Node(val);
        Node* temp = head;
        for (int i = 0; i < pos - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "Position out of bounds. Cannot insert." << endl;
            delete newNode;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        if (newNode->next == NULL)
        {
            tail = newNode;
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

    int search(int val)
    {
        Node* temp = head;
        int pos = 0;
        while (temp != NULL)
        {
            if (temp->data == val)
            {
                return pos;
            }
            temp = temp->next;
            pos++;
        }
        return -1; // Value not found
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

    lst.pop_front();
    lst.printList();

    lst.pop_back();

    lst.printList();

    cout<< "Position of 40: " << lst.search(40) << endl;
    
    return 0;
}
