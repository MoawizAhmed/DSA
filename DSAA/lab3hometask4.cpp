#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
using namespace std;

void fillRandom(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100000;
    }
}

void fillSorted(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = i;
    }
}

void fillReverseSorted(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = n - i;
    }
}

void copyArray(int src[], int dest[], int n)
{
    for (int i = 0; i < n; i++)
    {
        dest[i] = src[i];
    }
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void shellSort(int arr[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp)
            {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}

void combSort(int arr[], int n)
{
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
        for (int i = 0; i + gap < n; i++)
        {
            if (arr[i] > arr[i + gap])
            {
                int temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = temp;
                swapped = true;
            }
        }
    }
}

double timeSortAvg(void (*sortFunc)(int[], int), int source[], int n, int repeats)
{
    double total = 0;
    for (int r = 0; r < repeats; r++)
    {
        int* temp = new int[n];
        copyArray(source, temp, n);

        auto start = chrono::high_resolution_clock::now();
        sortFunc(temp, n);
        auto end = chrono::high_resolution_clock::now();

        chrono::duration<double, milli> duration = end - start;
        total += duration.count();

        delete[] temp;
    }
    return total / repeats;
}

int main()
{
    srand(time(0));

    int sizes[] = {100, 1000, 10000, 50000};
    int repeatsForSize[] = {200, 50, 10, 2};
    int numSizes = 4;

    cout << "n\tBubble\tSelection\tInsertion\tShell\tComb" << endl;

    for (int s = 0; s < numSizes; s++)
    {
        int n = sizes[s];
        int repeats = repeatsForSize[s];

        int* original = new int[n];
        fillRandom(original, n);

        double bubbleTime = timeSortAvg(bubbleSort, original, n, repeats);
        double selectionTime = timeSortAvg(selectionSort, original, n, repeats);
        double insertionTime = timeSortAvg(insertionSort, original, n, repeats);
        double shellTime = timeSortAvg(shellSort, original, n, repeats);
        double combTime = timeSortAvg(combSort, original, n, repeats);

        cout << n << "\t" << bubbleTime << "\t" << selectionTime << "\t"
             << insertionTime << "\t" << shellTime << "\t" << combTime << endl;

        delete[] original;
    }

    cout << endl;
    cout << "n = 10000 with different input orders" << endl;

    int n = 10000;
    int repeats = 10;

    int* randomArr = new int[n];
    int* sortedArr = new int[n];
    int* reverseArr = new int[n];
    fillRandom(randomArr, n);
    fillSorted(sortedArr, n);
    fillReverseSorted(reverseArr, n);

    int cases = 3;
    int* baseArrays[3] = {randomArr, sortedArr, reverseArr};
    string labels[3] = {"Random", "Sorted", "Reverse Sorted"};

    for (int c = 0; c < cases; c++)
    {
        double bubbleTime = timeSortAvg(bubbleSort, baseArrays[c], n, repeats);
        double selectionTime = timeSortAvg(selectionSort, baseArrays[c], n, repeats);
        double insertionTime = timeSortAvg(insertionSort, baseArrays[c], n, repeats);
        double shellTime = timeSortAvg(shellSort, baseArrays[c], n, repeats);
        double combTime = timeSortAvg(combSort, baseArrays[c], n, repeats);

        cout << labels[c] << ": Bubble=" << bubbleTime << "ms Selection=" << selectionTime
             << "ms Insertion=" << insertionTime << "ms Shell=" << shellTime
             << "ms Comb=" << combTime << "ms" << endl;
    }

    delete[] randomArr;
    delete[] sortedArr;
    delete[] reverseArr;

    return 0;
}