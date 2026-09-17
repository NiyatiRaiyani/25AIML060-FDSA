#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string id;
    Node* next;

    Node(string value)
    {
        id = value;
        next = nullptr;
    }
};

// Insert at end
void insertEnd(Node*& head, string id)
{
    Node* newNode = new Node(id);

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

// Delete all occurrences
void deleteAll(Node*& head, string target)
{
    while (head != nullptr && head->id == target)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    Node* temp = head;

    while (temp != nullptr && temp->next != nullptr)
    {
        if (temp->next->id == target)
        {
            Node* deleteNode = temp->next;
            temp->next = deleteNode->next;
            delete deleteNode;
        }
        else
        {
            temp = temp->next;
        }
    }
}

// Display list
void display(Node* head)
{
    if (head == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;

    cout << "Customer IDs: ";

    while (temp != nullptr)
    {
        cout << temp->id;

        if (temp->next != nullptr)
            cout << " -> ";

        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    Node* head = nullptr;

    int n;
    string id, target;

    cout << "===== Supermarket Loyalty System =====" << endl;

    cout << "\nEnter number of customers: ";
    cin >> n;

    cout << "Enter customer IDs: ";

    for (int i = 0; i < n; i++)
    {
        cin >> id;
        insertEnd(head, id);
    }

    cout << "\nOriginal ";
    display(head);

    cout << "Enter ID to remove: ";
    cin >> target;

    deleteAll(head, target);

    cout << "Updated ";
    display(head);

    return 0;
}
