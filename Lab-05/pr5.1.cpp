#include <iostream>
using namespace std;

struct Node
{
    string song;
    Node *prev;
    Node *next;
};

Node *head = NULL;

// Insert a song at the beginning
void insertBeginning(string song)
{
    Node *newNode = new Node;

    newNode->song = song;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    head = newNode;
}

// Insert a song at the end
void insertEnd(string song)
{
    Node *newNode = new Node;

    newNode->song = song;
    newNode->next = NULL;

    if (head == NULL)
    {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    Node *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// Insert a song after a given song
void insertAfter(string oldSong, string newSong)
{
    Node *temp = head;

    while (temp != NULL && temp->song != oldSong)
        temp = temp->next;

    if (temp == NULL)
    {
        cout << "Song not found." << endl;
        return;
    }

    Node *newNode = new Node;

    newNode->song = newSong;
    newNode->prev = temp;
    newNode->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}

// Delete the first song
void deleteFirst()
{
    if (head == NULL)
    {
        cout << "Playlist is empty." << endl;
        return;
    }

    Node *temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    delete temp;
}

// Count total songs
void countSongs()
{
    int count = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    cout << "Total songs: " << count << endl;
}

// Display playlist
void display()
{
    if (head == NULL)
    {
        cout << "Playlist is empty." << endl;
        return;
    }

    Node *temp = head;

    cout << "Playlist: ";

    while (temp != NULL)
    {
        cout << temp->song;

        if (temp->next != NULL)
            cout << " <-> ";

        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    int n;

    cout << "Enter number of operations: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int choice;
        string song, oldSong;

        cout << "\n1. Add at Beginning";
        cout << "\n2. Add at End";
        cout << "\n3. Insert After Song";
        cout << "\n4. Delete First Song";
        cout << "\n5. Count Songs";
        cout << "\n6. Display Playlist";

        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter song: ";
            cin >> song;

            insertBeginning(song);
            display();
        }
        else if (choice == 2)
        {
            cout << "Enter song: ";
            cin >> song;

            insertEnd(song);
            display();
        }
        else if (choice == 3)
        {
            cout << "Enter existing song: ";
            cin >> oldSong;

            cout << "Enter new song: ";
            cin >> song;

            insertAfter(oldSong, song);
            display();
        }
        else if (choice == 4)
        {
            deleteFirst();
            display();
        }
        else if (choice == 5)
        {
            countSongs();
        }
        else if (choice == 6)
        {
            display();
        }
        else
        {
            cout << "Invalid choice." << endl;
        }
    }

    return 0;
}
