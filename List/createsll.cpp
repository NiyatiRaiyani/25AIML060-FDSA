#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
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

    cout << "NULL";
}

void insertAtBeginning(struct Node **head, int data)
{
    struct Node *newNode = new Node;

    newNode->data = data;
    newNode->next = *head;

    *head = newNode;
}

void insertAtEnd(struct Node **head, int data)
{
    struct Node *newNode = new Node;
    struct Node *temp;

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
int main()
{
    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    createList(n);
    insertAtBeginning(&header, 10);
    insertAtEnd(&header, 50);
    display();

    return 0;
}
