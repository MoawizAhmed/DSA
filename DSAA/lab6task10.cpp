
#include <iostream>
using namespace std;

bool issafe(int **board, int x, int y, int n)
{
   
    int i = x - 1;

    while (i >= 0)
    {
        if (board[i][y] == 1)
            return false;

        i--;
    }


    i = x - 1;
    int j = y - 1;

    while (i >= 0 && j >= 0)
    {
        if (board[i][j] == 1)
            return false;

        i--;
        j--;
    }

    i = x - 1;
    j = y + 1;

    while (i >= 0 && j < n)
    {
        if (board[i][j] == 1)
            return false;

        i--;
        j++;
    }

    return true;
}

void queens(int **board, int x, int n, int &counter)
{
    if (x == n)
    {
        counter++;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (issafe(board, x, i, n))
        {
            board[x][i] = 1;

            queens(board, x + 1, n, counter);

            board[x][i] = 0;
        }
    }
}

int main()
{
    int **board;
    int n = 8;

    board = new int*[n];

    for (int i = 0; i < n; i++)
    {
        board[i] = new int[n];
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i][j] = 0;
        }
    }

    int counter = 0;

    queens(board, 0, n, counter);

    cout << "Total solutions: " << counter << endl;

    for (int i = 0; i < n; i++)
    {
        delete[] board[i];
    }

    delete[] board;

    return 0;
}
