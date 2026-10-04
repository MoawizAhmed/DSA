#include <iostream>
#include <string>
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
            return -1;
        }

        return arr[top--];
    }

    bool isempty()
    {
        return top == -1;
    }

    int gettop()
    {
        if (top == -1)
        {
            return -1;
        }

        return arr[top];
    }

    int count()
    {
        return top + 1;
    }
};

int postfix(string exp)
{
    stack s(exp.length());

    for (int i = 0; i < exp.length(); i++)
    {
        char c = exp[i];

        if (c >= '0' && c <= '9')
        {
            s.push(c - '0');
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            if (s.count() < 2)
            {
                cout << "Error: Malformed expression" << endl;
                return -1;
            }

            int b = s.pop();
            int a = s.pop();
            int result;

            if (c == '+')
                result = a + b;
            else if (c == '-')
                result = a - b;
            else if (c == '*')
                result = a * b;
            else
            {
                if (b == 0)
                {
                    cout << "Error: Division by zero" << endl;
                    return -1;
                }

                result = a / b;
            }

            s.push(result);
        }
        else if (c != ' ')
        {
            cout << "Error: Malformed expression" << endl;
            return -1;
        }
    }

    if (s.count() != 1)
    {
        cout << "Error: Malformed expression" << endl;
        return -1;
    }

    return s.pop();
}

int main()
{
    cout << postfix("23*54*+") << endl;
    cout << postfix("62/") << endl;
    postfix("9+");

    return 0;
}