#include <iostream>
using namespace std;

class stack
{
private:
    int top;
    int *arr;
    int size;

public:
    stack(int val)
    {
        size = val;
        top = -1;
        arr = new int[size];
    }

    void push(int val)
    {
        if (top == size - 1)
        {
            cout << "Overflow" << endl;
            return;
        }

        arr[++top] = val;
    }

    int pop()
    {
        if (top == -1)
        {
            cout << "Underflow" << endl;
            return -1;
        }

        return arr[top--];
    }

    bool isempty()
    {
        return top == -1;
    }
};

class queue
{
private:
    stack stackIn;
    stack stackOut;

public:
    queue(int size) : stackIn(size), stackOut(size)
    {
    }

    void enqueue(int x)
    {
        stackIn.push(x);
    }

    int dequeue()
    {
        if (stackOut.isempty())
        {
            while (!stackIn.isempty())
            {
                stackOut.push(stackIn.pop());
            }
        }

        if (stackOut.isempty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }

        return stackOut.pop();
    }
};

int main()
{
    queue q(10);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << q.dequeue() << endl;

    q.enqueue(4);

    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;

    return 0;
}