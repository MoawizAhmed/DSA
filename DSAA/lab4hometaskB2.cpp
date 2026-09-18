//B TASK 7
#include <iostream>
#include <string>
using namespace std;

class player
{
public:
    string name;
    player* next;

    player(string n)
    {
        name = n;
        next = nullptr;
    }
};

class roundrobin
{
private:
    player* head;
    player* current;

public:

    roundrobin()
    {
        head = nullptr;
        current = nullptr;
    }

    void addPlayer(string name)
    {
        player* newplayer = new player(name);

        if(head == nullptr)
        {
            head = newplayer;
            newplayer->next = head;
            current = head;
            return;
        }

        player* temp = head;

        while(temp->next != head)
        {
            temp = temp->next;
        }

        temp->next = newplayer;
        newplayer->next = head;
    }

    void nextTurn()
    {
        if(current == nullptr)
            return;

        current = current->next;

        cout << current->name << endl;
    }

    void removePlayer(string name)
    {
        if(head == nullptr)
            return;

        // Removing head
        if(head->name == name)
        {
            if(head->next == head)
            {
                delete head;
                head = nullptr;
                current = nullptr;
                return;
            }

            player* last = head;

            while(last->next != head)
            {
                last = last->next;
            }

            player* temp = head;

            head = head->next;
            last->next = head;

            if(current == temp)
                current = head;

            delete temp;
            return;
        }

        player* temp = head;

        while(temp->next != head &&
              temp->next->name != name)
        {
            temp = temp->next;
        }

        if(temp->next == head)
            return;

        player* todelete = temp->next;

        if(current == todelete)
            current = todelete->next;

        temp->next = todelete->next;

        delete todelete;
    }
};

int main()
{
    roundrobin game;

    game.addPlayer("Ali");
    game.addPlayer("Beena");
    game.addPlayer("Cara");

    game.nextTurn();
    game.nextTurn();
    game.nextTurn();
    game.nextTurn();

    return 0;
}