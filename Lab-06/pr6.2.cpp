#include <iostream>
using namespace std;

struct Node
{
    string page;
    Node* next;
};

Node* top = NULL;

void visit(string page)
{
    Node* newNode = new Node;

    newNode->page = page;
    newNode->next = top;
    top = newNode;

    cout << "Visited: " << page << endl;
    cout << "Current Page: " << top->page << endl;
}

void back()
{
    if (top == NULL || top->next == NULL)
    {
        cout << "No history left. Cannot go back." << endl;
        cout << "Current Page: " << top->page << endl;
    }
    else
    {
        Node* temp = top;

        top = top->next;
        delete temp;

        cout << "Back pressed." << endl;
        cout << "Current Page: " << top->page << endl;
    }
}

void display()
{
    Node* temp = top;

    cout << "Page History: ";

    while (temp != NULL)
    {
        cout << temp->page << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    int choice;
    string page;

    while (true)
    {
        cout << "\n1. Visit Page" << endl;
        cout << "2. Back" << endl;
        cout << "3. Display History" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter page: ";
                cin >> page;
                visit(page);
                break;

            case 2:
                back();
                break;

            case 3:
                display();
                break;

            case 4:
                cout << "Program ended." << endl;
                return 0;

            default:
                cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
