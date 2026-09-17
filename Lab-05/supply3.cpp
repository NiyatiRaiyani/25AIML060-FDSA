#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string stop;
    Node* next;

    Node(string value)
    {
        stop = value;
        next = nullptr;
    }
};

// Insert at end
void insertEnd(Node*& head, string stop)
{
    Node* newNode = new Node(stop);

    if (head == nullptr)
    {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* temp = head;

    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}

// Display route from given starting stop
void displayRoute(Node* head, string start)
{
    if (head == nullptr)
    {
        cout << "Route is empty." << endl;
        return;
    }

    Node* temp = head;

    // Find starting stop
    while (temp->stop != start)
    {
        temp = temp->next;

        if (temp == head)
        {
            cout << "Starting stop not found." << endl;
            return;
        }
    }

    Node* startNode = temp;
    int count = 0;

    cout << "\nRoute: ";

    do
    {
        cout << temp->stop;
        count++;

        temp = temp->next;

        if (temp != startNode)
            cout << " -> ";

    } while (temp != startNode);

    cout << " -> " << startNode->stop << endl;
    cout << "Total stops: " << count << endl;
}

int main()
{
    Node* head = nullptr;

    int n;
    string stop;
    string start;

    cout << "===== Circular Bus Route =====" << endl;

    cout << "\nEnter number of stops: ";
    cin >> n;

    cout << "Enter stop names: ";

    for (int i = 0; i < n; i++)
    {
        cin >> stop;
        insertEnd(head, stop);
    }

    cout << "Enter starting stop: ";
    cin >> start;

    displayRoute(head, start);

    return 0;
}
