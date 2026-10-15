#include <iostream>
using namespace std;

int factorial(int x, int acc)
{
    if (x == 0)
    {
        return acc;
    }

    return factorial(x - 1, x * acc);
}

int main()
{
    cout << factorial(5, 1);
    return 0;
}