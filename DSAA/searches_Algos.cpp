#include <iostream>
using namespace std;
int main()
{
int key=5;
const int n=6;
int arr[n]={1,2,3,4,5,6};
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
return 0;
}