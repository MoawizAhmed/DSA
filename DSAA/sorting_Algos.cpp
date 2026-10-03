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
    
    //insertion sort using temp variable

        // for (int i = 1; i < n; i++)
        // {
        //     int key = arr[i];
        //     int j = i - 1;
        
        //     while (j >= 0 && arr[j] > key)
        //     {
        //         arr[j + 1] = arr[j];
        //         j--;
        //     }
        
        //     arr[j + 1] = key;
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

  bool swapped=true;
  int gap=n;
  while (gap > 1 || swapped)
  {
    gap/=1.3;
    if (gap<1)
    {
        gap=1;
    }
    swapped=false;
    for (int i = 0; i+gap < n; i++)
    {
        if (arr[i]>arr[i+gap])
        {
            int temp=arr[i];
            arr[i]=arr[i+gap];
            arr[i+gap]=temp;
            swapped=true;
        }
    }
  }
  

   for (int i = 0; i < n; i++)
   {
    cout<<arr[i];
   }
   
    return 0;
}