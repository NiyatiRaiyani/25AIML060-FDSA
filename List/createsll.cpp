#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
}*header = NULL;

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
void deleteAtFirst(Node **head)
{
    if(*head == NULL)
    {
        cout<<"List is empty";
        return;
    }

     Node *temp = *head;

    *head = (*head)->next;

    delete temp;
}

int main()
{
    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    createList(n);

    cout << "\nOriginal List: ";
    display();

    insertAtBeginning(&header, 10);

    cout << "After Insert at Beginning: ";
    display();

    insertAtEnd(&header, 50);

    cout << "After Insert at End: ";
    display();

    deleteAtFirst(&header);

    cout<<"After delete at first: ";
    display();

    return 0;
}
