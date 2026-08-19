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
        cout << temp->data<<"  ";
        temp = temp->next;
    }

    cout << " \n";
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
    Node *temp;

    newNode->data = data;
    newNode->next = NULL;

    if(*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        temp = *head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

void insertAtK(Node **head, int data, int k)
{
    Node *newNode = new Node;
    newNode->data = data;

    // Insert at first position
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
    int data;

    cout << "\nEnter data at first for delete: ";
    cin >> data;

    if(*head == NULL)
    {
        cout << "List is empty";
        return;
    }

    if((*head)->data == data)
    {
        Node *temp = *head;
        *head = (*head)->next;
        delete temp;
    }
    else
    {
        cout << "Data is not at first position";
    }
}

void deleteAtEnd(Node **head)
{
    int data;

    cout << "\n Enter data at last for delete: ";
    cin >> data;

    if(*head == NULL)
    {
        cout << "List is empty";
        return;
    }

    if((*head)->next == NULL)
    {
        if((*head)->data == data)
        {
            delete *head;
            *head = NULL;
        }
        else
        {
            cout << "Data not found";
        }
        return;
    }

    Node *temp = *head;

    while(temp->next->next != NULL)
    {
        temp = temp->next;
    }

    if(temp->next->data == data)
    {
        delete temp->next;
        temp->next = NULL;
    }
    else
    {
        cout << "Data is not at the end";
    }
}

int main()
{
    int n;
    int data;
    int k;

    cout << "Enter number of nodes: ";
    cin >> n;

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

    return 0;
}
