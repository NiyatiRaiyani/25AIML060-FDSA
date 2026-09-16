#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
} *header = NULL;


// Create Doubly Linked List
void createList(int n)
{
    Node *newNode, *temp;

    for(int i = 1; i <= n; i++)
    {
        newNode = new Node;

        cout << "Enter data: ";
        cin >> newNode->data;

        newNode->prev = NULL;
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
            newNode->prev = temp;
        }
    }
}


// Display List
void display()
{
    Node *temp = header;

    while(temp != NULL)
    {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}


// Insert at Beginning
void insertAtBeginning(Node **head, int data)
{
    Node *newNode = new Node;

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = *head;

    if(*head != NULL)
    {
        (*head)->prev = newNode;
    }

    *head = newNode;
}


// Insert at End
void insertAtEnd(Node **head, int data)
{
    Node *newNode = new Node;

    newNode->data = data;
    newNode->next = NULL;

    if(*head == NULL)
    {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    Node *temp = *head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}


// Insert at K Position
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
        newNode->prev = NULL;
        newNode->next = *head;

        if(*head != NULL)
        {
            (*head)->prev = newNode;
        }

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
    newNode->prev = temp;

    if(temp->next != NULL)
    {
        temp->next->prev = newNode;
    }

    temp->next = newNode;
}


// Delete at First
void deleteAtFirst(Node **head)
{
    if(*head == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    Node *temp = *head;

    *head = (*head)->next;

    if(*head != NULL)
    {
        (*head)->prev = NULL;
    }

    delete temp;
}


// Delete at K Position
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

    Node *temp = *head;

    for(int i = 1; i < k && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if(temp == NULL)
    {
        cout << "Invalid position!\n";
        return;
    }

    if(temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }
    else
    {
        *head = temp->next;
    }

    if(temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }

    delete temp;
}


// Delete at End
void deleteAtEnd(Node **head)
{
    if(*head == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    Node *temp = *head;

    if(temp->next == NULL)
    {
        delete temp;
        *head = NULL;
        return;
    }

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->prev->next = NULL;

    delete temp;
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


    // Insert at Beginning
    cout << "\nEnter data for Insert at Beginning: ";
    cin >> data;

    insertAtBeginning(&header, data);

    cout << "After Insert at Beginning: ";
    display();


    // Insert at End
    cout << "\nEnter data for Insert at End: ";
    cin >> data;

    insertAtEnd(&header, data);

    cout << "After Insert at End: ";
    display();


    // Insert at K
    cout << "\nEnter data for Insert at K: ";
    cin >> data;

    cout << "Enter position K: ";
    cin >> k;

    insertAtK(&header, data, k);

    cout << "After Insert at K: ";
    display();


    // Delete at First
    deleteAtFirst(&header);

    cout << "\nAfter Delete at First: ";
    display();


    // Delete at End
    deleteAtEnd(&header);

    cout << "After Delete at End: ";
    display();


    // Delete at K
    cout << "\nEnter position K to delete: ";
    cin >> k;

    deleteAtK(&header, k);

    cout << "After Delete at K: ";
    display();


    return 0;
}
