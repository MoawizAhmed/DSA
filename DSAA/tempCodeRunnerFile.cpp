bool valid(char temp[], int N)
{
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
        if ((temp[i] == 'a' || temp[i] == 'e' || temp[i] == 'i' || temp[i] == 'o' || temp[i] == 'u') &&
            (temp[i + 1] == 'a' || temp[i + 1] == 'e' || temp[i + 1] == 'i' || temp[i + 1] == 'o' || temp[i + 1] == 'u'))
        {
            return false;
        }
    }
    int vowelcount = 0;
    for (int i = 0; i < N; i++)
    {
        if (temp[i] == 'a' || temp[i] == 'e' || temp[i] == 'i' || temp[i] == 'o' || temp[i] == 'u')
        {
            vowelcount++;
        }
    }
    if (vowelcount < 2)
    {
        return false;
    }
    if (temp[0] == 'a' || temp[0] == 'e' || temp[0] == 'i' || temp[0] == 'o' || temp[0] == 'u' ||
        temp[N - 1] == 'a' || temp[N - 1] == 'e' || temp[N - 1] == 'i' || temp[N - 1] == 'o' || temp[N - 1] == 'u')
    {
        return false;
    }

    return true;

}
void randomkid(char arr[], char temp[], bool visited[], int n, int N, int index)
{
    if (index == N)
    {
        if (valid(temp, N))
        {
            for (int i = 0; i < N; i++)
            {
                cout << temp[i] << " ";
            }
            cout << endl;
        }
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            temp[index] = arr[i];
            randomkid(arr, temp, visited, n, N, index + 1);
            visited[i] = false;
        }

    }

}
int main()
{
    int n = 5;
    int N = 4;
    char* arr = new char[n];
    char* temp = new char[N];
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    arr[0] = 'a';
    arr[1] = 'b';
    arr[2] = 'c';
    arr[3] = 'd';
    arr[4] = 'e';
    randomkid(arr, temp, visited, n, N, 0);
    return 0;
}