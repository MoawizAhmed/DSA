#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter the size of array: " << endl;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter the " << i + 1 << "th element of the array: " << endl;
        cin >> arr[i];
    }

    cout << "Original array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    int gap = n;
    bool swapped = true;

    while (gap != 1 || swapped)
    {
        gap = gap / 1.3;

        if (gap < 1)
        {
            gap = 1;
        }

        swapped = false;

        cout << "Gap: " << gap << endl;

        for (int j = 0; j + gap < n; j++)
        {
            if (arr[j] > arr[j + gap])
            {
                int temp = arr[j];
                arr[j] = arr[j + gap];
                arr[j + gap] = temp;

                swapped = true;
            }
        }

        cout << "Array after pass: ";
        for (int k = 0; k < n; k++)
        {
            cout << arr[k] << " ";
        }
        cout << endl;
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;

    return 0;
}