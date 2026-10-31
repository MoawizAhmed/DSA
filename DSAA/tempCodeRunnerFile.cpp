bool validpassword(char temp[], int N)
{
    int digitcount = 0;
    int specialsymbol = 0;
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (temp[i] == temp[j])
            {
                return false;
            }
        }
    }
    for (int i = 0; i < N - 1; i++)
    {
        if (temp[i] >= '0' && temp[i] <= '9' && temp[i + 1] >= '0' && temp[i + 1] <= '9')
        {
            return false;
        }

    }
    for (int i = 0; i < N; i++)
    {
        if (temp[i] >= '0' && temp[i] <= '9')
        {
            digitcount++;
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (temp[i] == '!' || temp[i] == '@' || temp[i] == '#' || temp[i] == '$' || temp[i] == '%' || temp[i] == '^' || temp[i] == '&' || temp[i] == '*')
        {
            specialsymbol++;
        }
    }
    if (digitcount < 2)
    {
        return false;
    }
    if (specialsymbol == 0)
    {
        return false;
    }
    return true;
}
void password(char arr[], char temp[], int n, int N, int index)
{
    if (index == N)
    {
        if (validpassword(temp, N))
        {
            for (int i = 0; i < N; i++)
            {
                cout << temp[i] << " ";
            }
            cout << endl;
        }
        return;
    }
    for (int i = index; i < n; i++)
    {
        temp[index] = arr[i];
        password(arr, temp, n, N, i + 1);
    }

}
int main()
{
    int n = 5;
    int N = 4;
    char* arr = new char[n];
    char* temp = new char[N];
    arr[0] = '0';
    arr[1] = '2';
    arr[2] = 'v';
    arr[3] = '^';
    arr[4] = 'm';
    password(arr, temp, n, N, 0);
    return 0;
}