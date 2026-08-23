#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
} *header = NULL;

void createList(int n)
{
    Node *newNode, *temp;

    for(int i = 1; i <= n; i++)
    {
        newNode = new Node;

        cout << "Enter data: ";
        cin >> newNode->data;

        newNode->next = NULL;

        if(header == NULL)
        {
            header = newNode;
        }
        else
        {
            temp = header;

            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }
}

void display()
{
    Node *temp = header;

    while(temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

void insertAtBeginning(Node **head, int data)
{
    Node *newNode = new Node;

    newNode->data = data;
    newNode->next = *head;

    *head = newNode;
}

void insertAtEnd(Node **head, int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;

    if(*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        Node *temp = *head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

void insertAtK(Node **head, int data, int k)
{
    if(k <= 0)
    {
        cout << "Invalid position!\n";
        return;
    }

    Node *newNode = new Node;
    newNode->data = data;

    if(k == 1)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node *temp = *head;

    for(int i = 1; i < k - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if(temp == NULL)
    {
        cout << "Invalid position!\n";
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtFirst(Node **head)
{
    if(*head == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    Node *temp = *head;
    *head = (*head)->next;

    delete temp;
}

void deleteAtK(Node **head, int k)
{
    if(*head == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    if(k <= 0)
    {
        cout << "Invalid position!\n";
        return;
    }

    if(k == 1)
    {
        Node *temp = *head;
        *head = (*head)->next;

        delete temp;
        return;
    }

    Node *temp = *head;

    for(int i = 1; i < k - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if(temp == NULL || temp->next == NULL)
    {
        cout << "Invalid position!\n";
        return;
    }

    Node *deleteNode = temp->next;

    temp->next = deleteNode->next;

    delete deleteNode;
}

void deleteAtEnd(Node **head)
{
    if(*head == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    if((*head)->next == NULL)
    {
        delete *head;
        *head = NULL;
        return;
    }

    Node *temp = *head;

    while(temp->next->next != NULL)
    {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;
}

int main()
{
    int n, data, k;

    cout << "Enter number of nodes: ";
    cin >> n;

    if(n <= 0)
    {
        cout << "Invalid number of nodes!";
        return 0;
    }

    createList(n);

    cout << "\nOriginal List: ";
    display();

    cout << "\nEnter data for Insert at Beginning: ";
    cin >> data;

    insertAtBeginning(&header, data);

    cout << "After Insert at Beginning: ";
    display();

    cout << "\nEnter data for Insert at End: ";
    cin >> data;

    insertAtEnd(&header, data);

    cout << "After Insert at End: ";
    display();

    cout << "\nEnter data for Insert at K: ";
    cin >> data;

    cout << "Enter position K: ";
    cin >> k;

    insertAtK(&header, data, k);

    cout << "After Insert at K: ";
    display();

    deleteAtFirst(&header);

    cout << "\nAfter Delete at First: ";
    display();

    deleteAtEnd(&header);

    cout << "After Delete at End: ";
    display();

    cout << "\nEnter position K to delete: ";
    cin >> k;

    deleteAtK(&header, k);

    cout << "After Delete at K: ";
    display();

    return 0;
}