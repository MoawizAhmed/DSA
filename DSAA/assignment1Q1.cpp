/*
Fiber-optic company is installing cables at different locations and has recorded the required cable
lengths as 85, 42, 120, 35, 67, 50. The installation team needs these lengths arranged in ascending
order before preparing the final installation plan. The process starts by considering the first value
as arranged, then takes the next value and stores it temporarily. Compare this value with the
previously arranged values, shift larger values one position to the right, and place the stored
value into its correct position. Your program must take input from the user, display the original
array, display the array after each iteration, and display the final sorted array. Do not use sort (),
another array, or repeated swapping; use a temporary variable and shifting as described.
Your task is to identify the sorting algorithm represented by this scenario and then implement
the identified algorithm in C++.
*/
#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"ENTER THE SIZE OF ARRAY: "<<endl;
    cin>>n;
    int *arr=new int[n];
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter the "<<i+1<<"th element: "<<endl;
        cin>>arr[i];
    }
    cout<<"Unsorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for (int i = 1; i < n; i++)
    {
        int key=arr[i];
        int j=i-1;
        while (j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
        cout<<"array during "<<i<<"th iteration ";
    for (int k = 0; k < n; k++)
    {
        cout<<arr[k]<<" ";
    }  
    cout<<endl;
    }
    cout<<"Sorted array: ";
       for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    delete[] arr;
    return 0;
}