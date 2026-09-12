   for (int i = n; i > 1; i = i * 10 / 13)
{
    for (int j = 0; j + i < n; j++)
    {
        if (arr[j] > arr[j + i])
        {
            int temp = arr[j];
            arr[j] = arr[j + i];
            arr[j + i] = temp;
        }
    }
}
