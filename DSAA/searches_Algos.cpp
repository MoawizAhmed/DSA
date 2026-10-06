#include <iostream>
using namespace std;
// int main()
// {
// int key=5;
// const int n=6;
// int arr[n]={1,2,3,4,5,6};
// int low=0;
// int high=n-1;

   //interpolation search
// while(low<=high && key>=arr[low] && key <= arr[high])
// {
//     if (arr[low]==arr[high])
//     {
//         cout<<"index is: "<<low<<endl;
//         return 0;
//     }
//     if (arr[low]==key)
//     {
//         cout<<"index is: "<<low<<endl;
//         return 0;
//     }
//    int pos = low + ((key - arr[low]) * (high - low) / (arr[high] - arr[low]));
//    if (arr[pos]==key)
//    {
//     cout<<"index is : "<<pos<<endl;
//     return 0;
//    }
//    else if (arr[pos] < key)
//     {
//     low = pos + 1;
//     }
//     else
//     {
//     high = pos - 1;
//     }
// }

  // binary search

//   int left=0;
//   int right=n-1;
//   while(left<=right)
//   {
//     int mid=left+(right-left)/2;
//    if (arr[mid]==key)
//    {
//     cout<<mid<<endl;
//     return 0;
//    }
//    else if(arr[mid]<key)
//    {
//     left=mid+1;
//    }
//    else
//    {
//     right=mid-1;
//    }
//   }
// return 0;
// }
int binarysearchcount(int n, int arr[], int key)
{
    int left = 0;
    int right = n - 1;
    int first = -1;
    int last = -1;

    // Find first occurrence
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key)
        {
            first = mid;
            right = mid - 1;
        }
        else if (arr[mid] < key)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    // Find last occurrence
    left = 0;
    right = n - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key)
        {
            last = mid;
            left = mid + 1;
        }
        else if (arr[mid] < key)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    if (first == -1)
        return 0;

    return last - first + 1;
}
int interpolationsearchcount(int n, int arr[], int key)
{
    int low = 0;
    int high = n - 1;
    int first = -1;
    int last = -1;

    // Find first occurrence
    while (low <= high && key >= arr[low] && key <= arr[high])
    {
        if (arr[low] == arr[high])
        {
            if (arr[low] == key)
                first = low;

            break;
        }

        int pos = low + (key - arr[low]) * (high - low)
                       / (arr[high] - arr[low]);

        if (arr[pos] == key)
        {
            first = pos;
            high = pos - 1;
        }
        else if (arr[pos] < key)
        {
            low = pos + 1;
        }
        else
        {
            high = pos - 1;
        }
    }

    // Find last occurrence
    low = 0;
    high = n - 1;

    while (low <= high && key >= arr[low] && key <= arr[high])
    {
        if (arr[low] == arr[high])
        {
            if (arr[low] == key)
                last = high;

            break;
        }

        int pos = low + (key - arr[low]) * (high - low)
                       / (arr[high] - arr[low]);

        if (arr[pos] == key)
        {
            last = pos;
            low = pos + 1;
        }
        else if (arr[pos] < key)
        {
            low = pos + 1;
        }
        else
        {
            high = pos - 1;
        }
    }

    if (first == -1)
        return 0;

    return last - first + 1;
}
int binarysearch(int n, int arr[], int key)
{
    int left = 0;
    int right = n - 1;
    int ans = -1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key)
        {
            ans = mid;
            right = mid - 1;   // keep searching left
        }
        else if (arr[mid] < key)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return ans;
}
int interpolationsearch(int n, int arr[], int key)
{
    int low = 0;
    int high = n - 1;
    int ans = -1;

    while (low <= high && key >= arr[low] && key <= arr[high])
    {
        if (arr[low] == arr[high])
        {
            if (arr[low] == key)
                ans = low;

            break;
        }

        int pos = low + (key - arr[low]) * (high - low)
                       / (arr[high] - arr[low]);

        if (arr[pos] == key)
        {
            ans = pos;
            high = pos - 1;    // keep searching left
        }
        else if (arr[pos] < key)
        {
            low = pos + 1;
        }
        else
        {
            high = pos - 1;
        }
    }

    return ans;
}