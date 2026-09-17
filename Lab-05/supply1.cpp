#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

// Insert at end
void insertEnd(Node*& head, int data)
{
    Node* newNode = new Node(data);

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
}

// Merge two sorted lists
Node* mergeLists(Node* head1, Node* head2)
{
    Node* result = nullptr;
    Node* temp = nullptr;

    while (head1 != nullptr && head2 != nullptr)
    {
        Node* newNode;

        if (head1->data <= head2->data)
        {
            newNode = new Node(head1->data);
            head1 = head1->next;
        }
        else
        {
            newNode = new Node(head2->data);
            head2 = head2->next;
        }

        if (result == nullptr)
        {
            result = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = temp->next;
        }
    }

    while (head1 != nullptr)
    {
        Node* newNode = new Node(head1->data);
        temp->next = newNode;
        temp = temp->next;
        head1 = head1->next;
    }

    while (head2 != nullptr)
    {
        Node* newNode = new Node(head2->data);
        temp->next = newNode;
        temp = temp->next;
        head2 = head2->next;
    }

    return result;
}

// Display list
void display(Node* head)
{
    Node* temp = head;

    while (temp != nullptr)
    {
        cout << temp->data;

        if (temp->next != nullptr)
            cout << " -> ";

        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    Node* head1 = nullptr;
    Node* head2 = nullptr;
    Node* merged = nullptr;

    int n1, n2, data;

    cout << "===== Merge Two Sorted Linked Lists =====" << endl;

    cout << "\nEnter number of elements in List 1: ";
    cin >> n1;

    cout << "Enter sorted elements: ";
    for (int i = 0; i < n1; i++)
    {
        cin >> data;
        insertEnd(head1, data);
    }

    cout << "\nEnter number of elements in List 2: ";
    cin >> n2;

    cout << "Enter sorted elements: ";
    for (int i = 0; i < n2; i++)
    {
        cin >> data;
        insertEnd(head2, data);
    }

    cout << "\nList 1: ";
    display(head1);

    cout << "List 2: ";
    display(head2);

    merged = mergeLists(head1, head2);

    cout << "Merged List: ";
    display(merged);

    return 0;
}
