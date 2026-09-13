/*
You are developing an Emergency Room Game in which patients arrive at a hospital and wait to
be treated. Each patient has a unique Patient ID and a severity level, where 1 represents Critical,
2 represents Serious, and 3 represents Normal. Patients normally arrive and wait in the order in
which they enter the hospital; however, when the doctor is ready to treat a patient, a Critical patient
must always be treated before a Serious or Normal patient, and a Serious patient must always be
treated before a Normal patient. If two or more patients have the same severity level, the patient
who arrived first must be treated first.
The input consists of a sequence of ARRIVE ID SEVERITY and TREAT operations. When an
ARRIVE operation is encountered, the patient must be added to the appropriate queue, and when
a TREAT operation is encountered, the patient with the highest severity must be removed
according to the above rules. You are not allowed to use a priority queue; instead, implement
the solution using normal queues implemented with an array. You may use multiple queues to
maintain the required priority and FIFO order.

At the end, display the treatment order, the total number of patients treated, the total number of
patients remaining, and the number of Critical, Serious, and Normal patients still waiting. Do not
use STL queue, priority_queue, vector, deque, or any other built-in data structure.*/
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