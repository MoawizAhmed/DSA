#include <iostream>

using namespace std;

class Player
{
public:
    int id;
    int energy;
    char history[100];
    int top;

    Player()
    {
        id = 0;
        energy = 100;
        top = -1;
    }

    Player(int i)
    {
        id = i;
        energy = 100;
        top = -1;
    }

    void addAction(char action)
    {
        if (top < 99)
        {
            top++;
            history[top] = action;
        }
    }

    bool hasAction()
    {
        return top >= 0;
    }

    char undoAction()
    {
        if (top == -1)
            return '\0';

        char action = history[top];
        top--;

        return action;
    }

    int remainingActions()
    {
        return top + 1;
    }
};

class Queue
{
private:
    Player players[100];
    int front;
    int rear;

public:
    Queue()
    {
        front = 0;
        rear = -1;
    }

    bool isEmpty()
    {
        return front > rear;
    }

    void enqueue(Player p)
    {
        if (rear < 99)
        {
            rear++;
            players[rear] = p;
        }
    }

    Player dequeue()
    {
        Player p;

        if (!isEmpty())
        {
            p = players[front];
            front++;
        }

        return p;
    }

    int size()
    {
        if (isEmpty())
            return 0;

        return rear - front + 1;
    }
};

int main()
{
    Queue waitingLine;

    int numberOfPlayers;

    cout << "Enter number of players: ";
    cin >> numberOfPlayers;

    for (int i = 0; i < numberOfPlayers; i++)
    {
        int id;

        cout << "Enter player ID: ";
        cin >> id;

        Player p(id);
        waitingLine.enqueue(p);
    }

    int numberOfCommands;

    cout << "Enter number of commands: ";
    cin >> numberOfCommands;

    int eliminated[100];
    int eliminatedCount = 0;

    for (int i = 0; i < numberOfCommands; i++)
    {
        if (waitingLine.isEmpty())
            break;

        Player current = waitingLine.dequeue();

        char command;
        cin >> command;

        if (command == 'F')
        {
            current.energy -= 10;
            current.addAction('F');
        }
        else if (command == 'B')
        {
            current.addAction('B');
        }
        else if (command == 'T')
        {
            current.energy += 20;
            current.addAction('T');
        }
        else if (command == 'U')
        {
            if (current.hasAction())
            {
                char action = current.undoAction();

                if (action == 'F')
                {
                    current.energy += 10;
                }
                else if (action == 'B')
                {
                }
                else if (action == 'T')
                {
                    current.energy -= 20;
                }
            }
        }

        if (current.energy <= 0)
        {
            eliminated[eliminatedCount] = current.id;
            eliminatedCount++;
        }
        else
        {
            waitingLine.enqueue(current);
        }
    }

    cout << "\nElimination Order: ";

    if (eliminatedCount == 0)
    {
        cout << "None";
    }
    else
    {
        for (int i = 0; i < eliminatedCount; i++)
        {
            cout << eliminated[i];

            if (i != eliminatedCount - 1)
                cout << " ";
        }
    }

    cout << endl;

    cout << "Active Players:\n";

    int activePlayers = waitingLine.size();

    for (int i = 0; i < activePlayers; i++)
    {
        Player current = waitingLine.dequeue();

        cout << "Player ID: " << current.id << endl;
        cout << "Energy: " << current.energy << endl;
        cout << "Actions that can be undone: "
             << current.remainingActions() << endl;

        waitingLine.enqueue(current);
    }

    return 0;
}