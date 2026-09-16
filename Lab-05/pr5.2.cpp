#include <iostream>
using namespace std;

struct Node
{
    int token;
    Node* next;

    Node(int value)
    {
        token = value;
        next = nullptr;
    }
};

// Insert at front
void insertFront(Node*& head, int token)
{
    Node* newNode = new Node(token);

    if (head == nullptr)
    {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* last = head;

    while (last->next != head)
        last = last->next;

    newNode->next = head;
    last->next = newNode;
    head = newNode;
}

// Insert at end
void insertEnd(Node*& head, int token)
{
    Node* newNode = new Node(token);

    if (head == nullptr)
    {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* last = head;

    while (last->next != head)
        last = last->next;

    last->next = newNode;
    newNode->next = head;
}

// Insert at position
void insertAtPosition(Node*& head, int token, int position)
{
    if (position <= 0)
    {
        cout << "Invalid position." << endl;
        return;
    }

    if (position == 1)
    {
        insertFront(head, token);
        return;
    }

    if (head == nullptr)
    {
        cout << "Position not found." << endl;
        return;
    }

    Node* temp = head;

    for (int i = 1; i < position - 1; i++)
    {
        temp = temp->next;

        if (temp == head)
        {
            cout << "Position not found." << endl;
            return;
        }
    }

    Node* newNode = new Node(token);

    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete first student
void deleteFront(Node*& head)
{
    if (head == nullptr)
    {
        cout << "Circle is empty." << endl;
        return;
    }

    if (head->next == head)
    {
        delete head;
        head = nullptr;
        return;
    }

    Node* last = head;

    while (last->next != head)
        last = last->next;

    Node* temp = head;

    head = head->next;
    last->next = head;

    delete temp;
}

// Count students
void countStudents(Node* head)
{
    if (head == nullptr)
    {
        cout << "Total students: 0" << endl;
        return;
    }

    int count = 0;
    Node* temp = head;

    do
    {
        count++;
        temp = temp->next;
    } while (temp != head);

    cout << "Total students: " << count << endl;
}

// Display circular list
void display(Node* head)
{
    if (head == nullptr)
    {
        cout << "Circle is empty." << endl;
        return;
    }

    Node* temp = head;

    cout << "Students: ";

    do
    {
        cout << temp->token;

        temp = temp->next;

        if (temp != head)
            cout << " -> ";

    } while (temp != head);

    cout << " -> " << head->token << endl;
}

int main()
{
    Node* head = nullptr;

    int choice;
    int token;
    int position;

    cout << "===== Student Token Passing Circle =====" << endl;

    do
    {
        cout << "\n1. Join at Front";
        cout << "\n2. Join at End";
        cout << "\n3. Join at Position";
        cout << "\n4. Leave from Front";
        cout << "\n5. Count Students";
        cout << "\n6. Display Circle";
        cout << "\n7. Exit";

        cout << "\n\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter student token: ";
                cin >> token;

                insertFront(head, token);
                display(head);
                break;

            case 2:
                cout << "Enter student token: ";
                cin >> token;

                insertEnd(head, token);
                display(head);
                break;

            case 3:
                cout << "Enter student token: ";
                cin >> token;

                cout << "Enter position: ";
                cin >> position;

                insertAtPosition(head, token, position);
                display(head);
                break;

            case 4:
                deleteFront(head);
                display(head);
                break;

            case 5:
                countStudents(head);
                break;

            case 6:
                display(head);
                break;

            case 7:
                cout << "Program ended." << endl;
                break;

            default:
                cout << "Invalid choice." << endl;
        }

    } while (choice != 7);

    return 0;
}
