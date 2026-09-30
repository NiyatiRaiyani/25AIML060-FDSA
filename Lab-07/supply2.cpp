#include<iostream>
#include<queue>
using namespace std;

queue<int> q1;
queue<int> q2;

void add(int dish)
{
    q2.push(dish);

    while(!q1.empty())
    {
        q2.push(q1.front());
        q1.pop();
    }

    swap(q1, q2);

    cout << "Dish " << dish << " added." << endl;
}

void serve()
{
    if(q1.empty())
    {
        cout << "No dish available." << endl;
    }
    else
    {
        cout << "Dish " << q1.front() << " served." << endl;
        q1.pop();
    }
}

void display()
{
    if(q1.empty())
    {
        cout << "No dishes available." << endl;
    }
    else
    {
        cout << "Dishes: ";

        queue<int> temp = q1;

        while(!temp.empty())
        {
            cout << temp.front() << " ";
            temp.pop();
        }

        cout << endl;
    }
}

int main()
{
    int choice, dish;

    while(true)
    {
        cout << "\n1. Add Dish" << endl;
        cout << "2. Serve Dish" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "Enter dish number: ";
                cin >> dish;
                add(dish);
                break;

            case 2:
                serve();
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
