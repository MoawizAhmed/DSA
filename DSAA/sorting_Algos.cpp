#include <iostream>
using namespace std;
int main()
{
   const int n=6;
   int arr[n]={6,5,4,3,2,1};
   //bubble sort

//    for (int i = 0; i < n-1; i++)
//    {
//     for (int j = 0; j <n-i-1; j++)
//     {
//         if (arr[j]>arr[j+1])
//         {
//             int temp=arr[j];
//             arr[j]=arr[j+1];
//             arr[j+1]=temp;
//         }
//     }
//    }

       //selection sort

    // for (int i = 0; i < n-1; i++)
    // {
    //     int minindex=i;
    //     for (int j = i+1; j < n ; j++)
    //     {
    //         if (arr[j]<arr[minindex])
    //         {
    //             minindex=j;
    //         }
    //     }
    //     int temp=arr[i];
    //     arr[i]=arr[minindex];
    //     arr[minindex]=temp;
    // }
    
    //insertion sort

    // for (int i = 1; i < n; i++)
    // {
    //     int key=arr[i];
    //     int j=i-1;
    //     while (j>=0 && arr[j]>key)
    //     {
    //         int temp=arr[j];
    //         arr[j]=arr[key];
    //         arr[key]=temp;
    //         j--;
    //     }
    // }
    
    //shell sort

    //  for (int i = n/2; i >0 ; i/=2)
    //  {
    //    for (int j = i; j < n; j++)
    //    {
    //   int temp=arr[j];
    //   int res=j;
    //   while (res >= i && arr[res-i]> temp)
    //   {
    //     arr[res]=arr[res-i];
    //     res-=i;
    //   }
    //   arr[res]=temp;
    //    }
    //  }
     
    //comb sort

    for (int i = n; i >= 1; i /= 1.3)
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


   for (int i = 0; i < n; i++)
   {
    cout<<arr[i];
   }
   
    return 0;
}