#include <iostream>
using namespace std;
void selectionsort(int arr[],int n)
{
  for (int i = 0; i < n-1; i++)
  {
    int minindex=i;
    for (int j = i+1; j < n; j++)
    {
        if (arr[j]<arr[minindex])
        {
            minindex=j;
        }
    }
    int temp=arr[i];
        arr[i]=arr[minindex];
        arr[minindex]=temp;
  }
   for (int i = 0; i < n; i++)
   {
       cout<<arr[i]<<" "<<endl;
   }
}
void insertionsort(int arr[],int n)
{
  for (int i =1; i < n; i++)
  {
    int key=arr[i];
    int j=i-1;
    while (j>=0 && arr[j]>key)
    {
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]=key;
  }
  for (int i = 0; i < n; i++)
   {
       cout<<arr[i]<<" "<<endl;
   }
}
void shellsort(int arr[],int n)
{
 for (int i =n/2; i >0 ; i/=2)
 {
    for (int j = i; j < n ; j++)
    {
     int temp=arr[j];
     int res=j;
     while (res>=i && arr[res-i]>temp)
     {
         arr[res]=arr[res-i];
         res-=i;
     }
     arr[res]=temp;
    }
 }
  for (int i = 0; i < n; i++)
   {
       cout<<arr[i]<<" "<<endl;
   }
}
void combsort(int arr[],int n)
{
 int gap=n;
 bool swapped=true;
  while (gap>1 || swapped==true)
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
       cout<<arr[i]<<" "<<endl;
   }
}
int interpolationsearch(int arr[],int n,int key)
{
  int high=n-1;
  int low=0;
  while(low<=high && key>-arr[low] && key<=arr[high])
  {
   if (arr[low]==arr[high])
   {
    return low;
   }
   if (arr[low]==key)
   {
     return low;
   }
   int pos=low+(key-arr[low])*(high-low)/(arr[high]-arr[low]);
   if (arr[pos]==key)
   {
    return pos;
   }
   if (arr[pos]<key)
   {
    low=pos+1;
   }
   else
   {
    high=pos-1;
   }
  }
}
int main()
{
    const int n=8;
    // int arr[n]={8, 7, 6, 5, 4, 3, 2, 1};
    // combsort(arr,8);
    int arr[n]={1,22,44,55,67,120,340,350};
    int ans=interpolationsearch(arr,n,340);
    cout<<ans<<endl;
}