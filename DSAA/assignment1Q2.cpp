#include <iostream>
using namespace std;
int main()
{
   int n;
   cout<<"Enter the size of array: "<<endl;
   cin>>n;
   int *arr=new int[n];
   for (int i = 0; i < n; i++)
   {
    cout<<"Enter the "<<i+1<<"th element of the array "<<endl;
    cin>>arr[i];
   }
   int *newarr=new int[n+1];
   int pos,value;
   cout<<"Enter the new shelf position: "<<endl;
   cin>>pos;
   cout<<"Enter the value of the new shelf: "<<endl;
   cin>>value;
   n+=1;
   
   for (int i = 0; i <n ; i++)
   {
    if (i==pos)
    {
      newarr[i]=value;
      for (int k = pos+1; k < n ; k++)
      {
        newarr[k]=arr[k-1];
      }
      break;
    }
    else
    {
        newarr[i]=arr[i];
    }
   }
   cout<<"Unsorted array"<<endl;
   for (int i = 0; i < n; i++)
   {
    cout<<newarr[i]<<" ";
   }
   cout<<endl;
   delete[] arr;

     for (int i = 1; i < n; i++)
    {
        int key = newarr[i];
        int j = i - 1;
    
        while (j >= 0 && newarr[j] > key)
        {
            newarr[j + 1] = newarr[j];
            j--;
        }
    
        newarr[j + 1] = key;
    }
   cout<<"Sorted array"<<endl;
   for (int i = 0; i < n; i++)
   {
    cout<<newarr[i]<<" ";
   }
   
   
    return 0;
}