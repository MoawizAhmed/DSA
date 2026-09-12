#include <iostream>
using namespace std;

class Product
{
public:
    int id;
    string name;
    string category;
    float price;

    Product(int id, string name, string category, float price)
    {
        this->id = id;
        this->name = name;
        this->category = category;
        this->price = price;
    }
    Product(){}
};

class Node
{
public:
    Product data;
    Node* next;

    Node(Product p)
    {
        data = p;
        next = nullptr;
    }
};

class List
{
public:
    Node* head;

    List()
    {
        head = nullptr;
    }

    void insert(Product p)
    {
        Node* n = new Node(p);

        if (head == nullptr || p.id < head->data.id)
        {
            n->next = head;
            head = n;
            return;
        }

        Node* temp = head;

        while (temp->next != nullptr && temp->next->data.id < p.id)
            temp = temp->next;

        n->next = temp->next;
        temp->next = n;
    }

    void display()
    {
        Node* temp = head;

        while (temp != nullptr)
        {
            cout << temp->data.id << " "
                 << temp->data.name << " "
                 << temp->data.category << " "
                 << temp->data.price << endl;

            temp = temp->next;
        }
    }
};

Node* mergeLists(Node* a, Node* b)
{
    Node* head = nullptr;
    Node* tail = nullptr;

    while (a != nullptr && b != nullptr)
    {
        Node* selected;

        if (a->data.id < b->data.id)
        {
            selected = a;
            a = a->next;
        }
        else if (b->data.id < a->data.id)
        {
            selected = b;
            b = b->next;
        }
        else
        {
            if (a->data.price <= b->data.price)
                selected = a;
            else
                selected = b;

            a = a->next;
            b = b->next;
        }

        selected->next = nullptr;

        if (head == nullptr)
        {
            head = selected;
            tail = selected;
        }
        else
        {
            tail->next = selected;
            tail = selected;
        }
    }

    while (a != nullptr)
    {
        Node* temp = a;
        a = a->next;
        temp->next = nullptr;

        if (head == nullptr)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

    while (b != nullptr)
    {
        Node* temp = b;
        b = b->next;
        temp->next = nullptr;

        if (head == nullptr)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

    return head;
}

void display(Node* head)
{
    Node* temp = head;

    while (temp != nullptr)
    {
        cout << temp->data.id << " "
             << temp->data.name << " "
             << temp->data.category << " "
             << temp->data.price << endl;

        temp = temp->next;
    }
}

int countProducts(Node* head)
{
    int count = 0;

    while (head != nullptr)
    {
        count++;
        head = head->next;
    }

    return count;
}

float inventoryValue(Node* head)
{
    float total = 0;

    while (head != nullptr)
    {
        total += head->data.price;
        head = head->next;
    }

    return total;
}

int main()
{
    List glowcare, beautyhub;

    int n;

    cout << "Enter number of GlowCare products: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int id, orders;
        string name, category;
        float price;

        cin >> id >> name >> category >> price;

        glowcare.insert(Product(id, name, category, price));
    }

    cout << "Enter number of BeautyHub products: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int id;
        string name, category;
        float price;

        cin >> id >> name >> category >> price;

        beautyhub.insert(Product(id, name, category, price));
    }

    cout << "\nGlowCare:\n";
    glowcare.display();

    cout << "\nBeautyHub:\n";
    beautyhub.display();

    Node* master = mergeLists(glowcare.head, beautyhub.head);

    cout << "\nMaster List:\n";
    display(master);

    cout << "\nTotal products: "
         << countProducts(master) << endl;

    cout << "Total inventory value: "
         << inventoryValue(master) << endl;

    return 0;
}

