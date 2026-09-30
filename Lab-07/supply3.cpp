#include<iostream>
#include<stack>
using namespace std;

stack<int> s1;
stack<int> s2;

void add(int ticket)
{
    s1.push(ticket);

    cout << "Ticket " << ticket << " added." << endl;
}

void issue()
{
    if(s2.empty())
    {
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
    }

    if(s2.empty())
    {
        cout << "No ticket available." << endl;
    }
    else
    {
        cout << "Ticket " << s2.top() << " issued." << endl;
        s2.pop();
    }
}

void display()
{
    if(s1.empty() && s2.empty())
    {
        cout << "No tickets available." << endl;
    }
    else
    {
        cout << "Tickets are available." << endl;
    }
}

int main()
{
    int choice, ticket;

    while(true)
    {
        cout << "\n1. Add Ticket" << endl;
        cout << "2. Issue Ticket" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "Enter ticket number: ";
                cin >> ticket;
                add(ticket);
                break;

            case 2:
                issue();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
