#include <iostream>
using namespace std;
void bubbleSort(int arr[], int n, int &comparisons, int &swaps)
{
    comparisons = 0;
    swaps = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            comparisons++;

            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swaps++;
        }
     }
    }
    }

void combSort(int arr[], int n, int &comparisons, int &swaps)
{
    comparisons = 0;
    swaps = 0;

    int gap = n;
    bool swapped = true;

    while (gap != 1 || swapped)
    {
        gap = gap / 1.3;

        if (gap < 1)
            gap = 1;

        swapped = false;

        for (int j = 0; j + gap < n; j++)
        {
            comparisons++;

            if (arr[j] > arr[j + gap])
            {
                int temp = arr[j];
                arr[j] = arr[j + gap];
                arr[j + gap] = temp;

                swaps++;
                swapped = true;
            }
        }
    }
}

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main()
{
    const int n = 20;
    int original[n] = {
        20, 19, 18, 17, 16,
        15, 14, 13, 12, 11,
        10, 9, 8, 7, 6,
        5, 4, 3, 2, 1
    };
    int bubbleArray[n];
    int combArray[n];

    for (int i = 0; i < n; i++)
    {
        bubbleArray[i] = original[i];
        combArray[i] = original[i];
    }

    int bubbleComparisons, bubbleSwaps;
    int combComparisons, combSwaps;

    bubbleSort(bubbleArray,n,bubbleComparisons,bubbleSwaps);

    combSort(combArray,n,combComparisons,combSwaps);
    cout << "Original array: ";
    display(original, n);

    cout << endl;

    cout << "Bubble Sort:" << endl;
    cout << "Sorted array: ";
    display(bubbleArray, n);
    cout << "Comparisons: " << bubbleComparisons << endl;
    cout << "Swaps: " << bubbleSwaps << endl;

    cout << endl;

    cout << "Comb Sort:" << endl;
    cout << "Sorted array: ";
    display(combArray, n);
    cout << "Comparisons: " << combComparisons << endl;
    cout << "Swaps: " << combSwaps << endl;

    return 0;
}