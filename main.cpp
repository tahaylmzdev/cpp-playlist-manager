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
    Song song; //Data stored in this node
    Node* next; //Connect the song's node with other's node
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
    }
};
int main()
{
    Playlist playlist;

    playlist.addToEnd({"Bohemian Rhapsody", "Queen", 355});
    playlist.addToEnd({"Numb", "Linkin Park", 187});
    playlist.addToEnd({"Yesterday", "The Beatles", 160});

    playlist.print();
    return 0;
}
