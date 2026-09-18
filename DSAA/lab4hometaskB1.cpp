//B TASK 5 AND 6
#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node* next;

    node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class circularlinkedlist
{
private:
    node* head;

public:

    circularlinkedlist()
    {
        head = nullptr;
    }

    // Task 5
    void display()
    {
        if(head == nullptr)
            return;

        node* temp = head;

        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        while(temp != head);

        cout << endl;
    }

    // Task 6.1
    void append(int val)
    {
        node* newnode = new node(val);

        if(head == nullptr)
        {
            head = newnode;
            newnode->next = head;
            return;
        }

        node* temp = head;

        while(temp->next != head)
        {
            temp = temp->next;
        }

        temp->next = newnode;
        newnode->next = head;
    }

    // Task 6.2
    void insert(int pos, int val)
    {
        if(pos < 0)
            return;

        if(pos == 0)
        {
            node* newnode = new node(val);

            if(head == nullptr)
            {
                head = newnode;
                newnode->next = head;
                return;
            }

            node* temp = head;

            while(temp->next != head)
            {
                temp = temp->next;
            }

            newnode->next = head;
            temp->next = newnode;
            head = newnode;

            return;
        }

        if(head == nullptr)
            return;

        node* temp = head;

        for(int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;

            if(temp == head)
                return;
        }

        node* newnode = new node(val);

        newnode->next = temp->next;
        temp->next = newnode;
    }

    // Task 6.3
    void deleteValue(int val)
    {
        if(head == nullptr)
            return;

        // Deleting head
        if(head->data == val)
        {
            // Only one node
            if(head->next == head)
            {
                delete head;
                head = nullptr;
                return;
            }

            node* last = head;

            while(last->next != head)
            {
                last = last->next;
            }

            node* temp = head;

            head = head->next;
            last->next = head;

            delete temp;
            return;
        }

        // Deleting any other node
        node* temp = head;

        while(temp->next != head &&
              temp->next->data != val)
        {
            temp = temp->next;
        }

        if(temp->next == head)
            return;

        node* todelete = temp->next;

        temp->next = todelete->next;

        delete todelete;
    }

    // Task 6.4
    bool search(int key)
    {
        if(head == nullptr)
            return false;

        node* temp = head;

        do
        {
            if(temp->data == key)
                return true;

            temp = temp->next;
        }
        while(temp != head);

        return false;
    }
};

int main()
{
    circularlinkedlist c;

    c.append(10);
    c.append(20);
    c.append(30);

    c.display();

    c.insert(1, 15);
    c.display();

    c.deleteValue(15);
    c.display();

    cout << c.search(20) << endl;
    cout << c.search(50) << endl;

    return 0;
}