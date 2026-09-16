#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string song;
    Node* prev;
    Node* next;

    Node(string value)
    {
        song = value;
        prev = nullptr;
        next = nullptr;
    }
};

// Insert at front
void insertFront(Node*& head, string song)
{
    Node* newNode = new Node(song);

    newNode->next = head;

    if (head != nullptr)
        head->prev = newNode;

    head = newNode;
}

// Insert at end
void insertEnd(Node*& head, string song)
{
    Node* newNode = new Node(song);

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// Insert after a specific song
void insertAfter(Node*& head, string oldSong, string newSong)
{
    Node* temp = head;

    while (temp != nullptr && temp->song != oldSong)
        temp = temp->next;

    if (temp == nullptr)
    {
        cout << "Song not found." << endl;
        return;
    }

    Node* newNode = new Node(newSong);

    newNode->prev = temp;
    newNode->next = temp->next;

    if (temp->next != nullptr)
        temp->next->prev = newNode;

    temp->next = newNode;
}

// Delete first song
void deleteFront(Node*& head)
{
    if (head == nullptr)
    {
        cout << "Playlist is empty." << endl;
        return;
    }

    Node* temp = head;
    head = head->next;

    if (head != nullptr)
        head->prev = nullptr;

    delete temp;
}

// Count songs
void countSongs(Node* head)
{
    int count = 0;
    Node* temp = head;

    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }

    cout << "Total songs: " << count << endl;
}

// Display playlist
void display(Node* head)
{
    if (head == nullptr)
    {
        cout << "Playlist is empty." << endl;
        return;
    }

    Node* temp = head;

    cout << "Playlist: ";

    while (temp != nullptr)
    {
        cout << temp->song;

        if (temp->next != nullptr)
            cout << " <-> ";

        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    Node* head = nullptr;

    int choice;
    string song;
    string oldSong;

    cout << "===== Music Playlist =====" << endl;

    do
    {
        cout << "\n1. Insert at Front";
        cout << "\n2. Insert at End";
        cout << "\n3. Insert After Song";
        cout << "\n4. Delete First Song";
        cout << "\n5. Count Songs";
        cout << "\n6. Display Playlist";
        cout << "\n7. Exit";

        cout << "\n\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter song name: ";
                cin >> song;

                insertFront(head, song);
                display(head);
                break;

            case 2:
                cout << "Enter song name: ";
                cin >> song;

                insertEnd(head, song);
                display(head);
                break;

            case 3:
                cout << "Enter existing song name: ";
                cin >> oldSong;

                cout << "Enter new song name: ";
                cin >> song;

                insertAfter(head, oldSong, song);
                display(head);
                break;

            case 4:
                deleteFront(head);
                display(head);
                break;

            case 5:
                countSongs(head);
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
