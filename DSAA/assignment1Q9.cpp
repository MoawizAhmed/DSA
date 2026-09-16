#include <iostream>
#include <string>

using namespace std;

class Patient
{
public:
    int id;
    int severity;

    Patient()
    {
        id = 0;
        severity = 0;
    }

    Patient(int i, int s)
    {
        id = i;
        severity = s;
    }
};

class Queue
{
private:
    Patient patients[100];
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

    bool isFull()
    {
        return rear == 99;
    }

    void enqueue(Patient p)
    {
        if (!isFull())
        {
            rear++;
            patients[rear] = p;
        }
    }

    Patient dequeue()
    {
        Patient p;

        if (!isEmpty())
        {
            p = patients[front];
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
    Queue critical;
    Queue serious;
    Queue normal;

    int n;

    cout << "Enter number of operations: ";
    cin >> n;

    int treated[100];
    int treatedCount = 0;

    for (int i = 0; i < n; i++)
    {
        string operation;
        cin >> operation;

        if (operation == "ARRIVE")
        {
            int id;
            int severity;

            cin >> id >> severity;

            Patient p(id, severity);

            if (severity == 1)
            {
                critical.enqueue(p);
            }
            else if (severity == 2)
            {
                serious.enqueue(p);
            }
            else if (severity == 3)
            {
                normal.enqueue(p);
            }
        }
        else if (operation == "TREAT")
        {
            Patient p;

            if (!critical.isEmpty())
            {
                p = critical.dequeue();
            }
            else if (!serious.isEmpty())
            {
                p = serious.dequeue();
            }
            else if (!normal.isEmpty())
            {
                p = normal.dequeue();
            }
            else
            {
                continue;
            }

            treated[treatedCount] = p.id;
            treatedCount++;
        }
    }

    int remainingCritical = critical.size();
    int remainingSerious = serious.size();
    int remainingNormal = normal.size();

    int totalRemaining =
        remainingCritical +
        remainingSerious +
        remainingNormal;

    cout << "\nTreatment Order: ";

    if (treatedCount == 0)
    {
        cout << "None";
    }
    else
    {
        for (int i = 0; i < treatedCount; i++)
        {
            cout << treated[i];

            if (i != treatedCount - 1)
                cout << " ";
        }
    }

    cout << endl;

    cout << "Total Patients Treated: "
         << treatedCount << endl;

    cout << "Total Patients Remaining: "
         << totalRemaining << endl;

    cout << "Critical Patients Remaining: "
         << remainingCritical << endl;

    cout << "Serious Patients Remaining: "
         << remainingSerious << endl;

    cout << "Normal Patients Remaining: "
         << remainingNormal << endl;

    return 0;
}