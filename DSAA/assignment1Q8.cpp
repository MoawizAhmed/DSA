/*You are developing a game called Undo Battle in which a player moves along a one-dimensional
path starting from position 0. The player can perform four types of commands: R moves the player
one position to the right, L moves the player one position to the left, J moves the player two
positions to the right, and B performs an Undo operation. Every valid movement (R, L, or J) must
be stored in a stack so that the most recent movement can be undone. When the player performs
B, the most recent valid movement must be removed from the stack and the player must return to
the position before that movement. An Undo operation itself must not be stored in the stack. A
movement that would take the player to a position less than 0 is considered invalid and must not
be stored in the stack. If the player requests an Undo when the stack is empty, nothing should
happen. You are required to implement the stack using a linked list and process n commands given
as input. At the end, display the player's final position, the total number of successful movements,
the total number of successful Undo operations, and the remaining elements in the stack. Do not
use STL stack or any other built-in stack data structure.*/
#include <iostream>

using namespace std;

class Node
{
public:
    char command;
    Node* next;

    Node(char c)
    {
        command = c;
        next = NULL;
    }
};

class Stack
{
private:
    Node* top;

public:
    Stack()
    {
        top = NULL;
    }

    ~Stack()
    {
        while (top != NULL)
        {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void push(char c)
    {
        Node* newNode = new Node(c);
        newNode->next = top;
        top = newNode;
    }

    char pop()
    {
        if (top == NULL)
            return '\0';

        Node* temp = top;
        char c = temp->command;

        top = top->next;
        delete temp;

        return c;
    }

    bool isEmpty()
    {
        return top == NULL;
    }

    void display()
    {
        Node* temp = top;

        if (temp == NULL)
        {
            cout << "Stack is empty";
            return;
        }

        while (temp != NULL)
        {
            cout << temp->command << " ";
            temp = temp->next;
        }
    }
};

int main()
{
    Stack movements;

    int n;
    cout << "Enter number of commands: ";
    cin >> n;

    int position = 0;
    int successfulMovements = 0;
    int successfulUndo = 0;

    cout << "Enter commands: ";

    for (int i = 0; i < n; i++)
    {
        char command;
        cin >> command;

        if (command == 'R')
        {
            if (position + 1 >= 0)
            {
                position++;
                movements.push('R');
                successfulMovements++;
            }
        }
        else if (command == 'L')
        {
            if (position - 1 >= 0)
            {
                position--;
                movements.push('L');
                successfulMovements++;
            }
        }
        else if (command == 'J')
        {
            if (position + 2 >= 0)
            {
                position += 2;
                movements.push('J');
                successfulMovements++;
            }
        }
        else if (command == 'B')
        {
            if (!movements.isEmpty())
            {
                char lastMove = movements.pop();

                if (lastMove == 'R')
                    position--;

                else if (lastMove == 'L')
                    position++;

                else if (lastMove == 'J')
                    position -= 2;

                successfulUndo++;
            }
        }
    }

    cout << "\nFinal Position: " << position << endl;
    cout << "Successful Movements: " << successfulMovements << endl;
    cout << "Successful Undo Operations: " << successfulUndo << endl;

    cout << "Remaining Stack: ";
    movements.display();

    cout << endl;

    return 0;
}