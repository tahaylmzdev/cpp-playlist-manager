#include <iostream>
#include <string>
using namespace std;

struct Song
{
    string title;
    string artist;
    int durationSec;
};

struct Node
{
    Song song;
    Node* next;
};

class Playlist
{
private:
    Node* head;

public:
    Playlist()
    {
        head = nullptr;
    }

    void addToEnd(const Song& song)
    {
        Node* newNode = new Node{song, nullptr};

        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        Node* current = head;

        while (current->next != nullptr)
            current = current->next;

        current->next = newNode;
    }

    void print() const
    {
        const Node* current = head;
        int counter = 0;

        while (current != nullptr)
        {
            counter++;

            cout << counter << ". "
                 << current->song.title << " - "
                 << current->song.artist << " "
                 << current->song.durationSec << endl;

            current = current->next;
        }
        cout << endl;
    }

    int size() const
    {
        const Node* current = head;
        int counter = 0;

        while (current != nullptr)
        {
            counter++;
            current = current->next;
        }

        return counter;
    }

    Song* findByTitle(const string& title)
    {
        Node* current = head;

        while (current != nullptr)
        {
            if (current->song.title == title)
            {
                return &current->song;
            }

            current = current->next;
        }

        return nullptr;
    }

    bool removeByTitle(const string& title)
    {
        Node* current = head;
        Node* previous = nullptr;

        while (current != nullptr)
        {
            if (current->song.title == title)
            {
                if (current == head)
                {
                    Node* temp = current;
                    current = current->next;
                    head = head->next;
                    delete temp;
                    previous = nullptr;
                }
                else
                {
                    Node* temp = current;
                    current = current->next;
                    delete temp;
                    previous->next = current;
                }

                return true;
            }

            previous = current;
            current = current->next;
        }

        return false;
    }

    ~Playlist()
    {
        Node* current = head;

        while (current != nullptr)
        {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
    void insertAt(int index, const Song& song)
    {
        if (index < 0 || index > size())
        {
            cout << "Invalid index!\n";
            return;
        }

        Node* insertNode = new Node{song, nullptr};

        if (index == 0)
        {
            insertNode->next = head;
            head = insertNode;
        }
        else
        {
            Node* current = head;

            for (int i = 0; i < index - 1; i++)
            {
                current = current->next;
            }

            insertNode->next = current->next;
            current->next = insertNode;
        }
    }
};
int main()
{
    Playlist playlist;

    playlist.addToEnd({"Bohemian Rhapsody", "Queen", 355});
    playlist.addToEnd({"Numb", "Linkin Park", 187});
    playlist.addToEnd({"Yesterday", "The Beatles", 160});

    return 0;
}
