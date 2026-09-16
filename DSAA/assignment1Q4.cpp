#include <iostream>
using namespace std;

class Rider
{
public:
    int id;
    string name;
    int orders;

    Rider(int id, string name, int orders)
    {
        this->id = id;
        this->name = name;
        this->orders = orders;
    }
    Rider()
{
}
};

class Node
{
public:
    Rider data;
    Node* next;

    Node(Rider r)
    {
        data = r;
        next = nullptr;
    }
};

class CircularList
{
private:
    Node* head;

public:
    CircularList()
    {
        head = nullptr;
    }

    void insertBeginning(Rider r)
    {
        Node* n = new Node(r);

        if (head == nullptr)
        {
            head = n;
            n->next = head;
            return;
        }

        Node* temp = head;

        while (temp->next != head)
            temp = temp->next;

        n->next = head;
        temp->next = n;
        head = n;
    }

    void insertEnd(Rider r)
    {
        Node* n = new Node(r);

        if (head == nullptr)
        {
            head = n;
            n->next = head;
            return;
        }

        Node* temp = head;

        while (temp->next != head)
            temp = temp->next;

        temp->next = n;
        n->next = head;
    }

    void insertAt(Rider r, int pos)
    {
        if (pos < 0)
            return;

        if (pos == 0)
        {
            insertBeginning(r);
            return;
        }

        if (head == nullptr)
            return;

        Node* temp = head;

        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;

            if (temp == head)
                return;
        }

        Node* n = new Node(r);
        n->next = temp->next;
        temp->next = n;
    }

    void deleteBeginning()
    {
        if (head == nullptr)
            return;

        if (head->next == head)
        {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        Node* last = head;

        while (last->next != head)
            last = last->next;

        head = head->next;
        last->next = head;

        delete temp;
    }

    void deleteEnd()
    {
        if (head == nullptr)
            return;

        if (head->next == head)
        {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;

        while (temp->next->next != head)
            temp = temp->next;

        delete temp->next;
        temp->next = head;
    }

    void deleteAt(int pos)
    {
        if (head == nullptr || pos < 0)
            return;

        if (pos == 0)
        {
            deleteBeginning();
            return;
        }

        Node* temp = head;

        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;

            if (temp == head)
                return;
        }

        if (temp->next == head)
            return;

        Node* del = temp->next;
        temp->next = del->next;

        delete del;
    }

    Node* search(int id)
    {
        if (head == nullptr)
            return nullptr;

        Node* temp = head;

        do
        {
            if (temp->data.id == id)
                return temp;

            temp = temp->next;
        }
        while (temp != head);

        return nullptr;
    }

    void update(int id, string name, int orders)
    {
        Node* temp = search(id);

        if (temp != nullptr)
        {
            temp->data.name = name;
            temp->data.orders = orders;
        }
    }

    void display()
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = head;

        do
        {
            cout << temp->data.id << " "
                 << temp->data.name << " "
                 << temp->data.orders << endl;

            temp = temp->next;
        }
        while (temp != head);
    }

    int count()
    {
        if (head == nullptr)
            return 0;

        int total = 0;
        Node* temp = head;

        do
        {
            total++;
            temp = temp->next;
        }
        while (temp != head);

        return total;
    }

    void traverseFrom(int id)
    {
        Node* start = search(id);

        if (start == nullptr)
            return;

        Node* temp = start;

        do
        {
            cout << temp->data.name << " ";
            temp = temp->next;
        }
        while (temp != start);

        cout << endl;
    }
};

int main()
{
    CircularList riders;

    riders.insertEnd(Rider(1, "Ali", 5));
    riders.insertEnd(Rider(2, "Ahmed", 8));
    riders.insertBeginning(Rider(3, "Usman", 4));
    riders.insertAt(Rider(4, "Hamza", 6), 2);

    riders.display();

    cout << "Total riders: " << riders.count() << endl;

    cout << "Traversal: ";
    riders.traverseFrom(2);

    riders.update(2, "Ahmed Khan", 10);

    riders.deleteBeginning();
    riders.deleteEnd();
    riders.deleteAt(1);

    cout << "After deletion:" << endl;
    riders.display();

    return 0;
}
