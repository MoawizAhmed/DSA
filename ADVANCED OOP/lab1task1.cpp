#include <iostream>
#include <cstdint>
using namespace std;
int summ(int *arr,int n)
{
    int sum=0;
  for (int i = 0; i < n; i++)
  {
    sum+=arr[i];
  }
  return sum;
}
int averagee(int *arr,int n)
{
    int average=0;
    for (int i = 0; i < n; i++)
    {
        average+=arr[i];
    }
    average=(average/n);
    return average;
}
int maximumm(int *arr,int n)
{
   int maximum=INT16_MIN;
   for (int i = 0; i < n; i++)
   {
    if(arr[i]>maximum)
    {
        maximum=arr[i];
    }
   }
   return maximum;
}
int minimumm(int *arr,int n)
{
   int minimum=INT16_MAX;
   for (int i = 0; i < n; i++)
   {
    if(arr[i]<minimum)
    {
        minimum=arr[i];
    }
   }
   return minimum;
}

int main()
{
    int n;
    int *arr;
    cout<<"Enter the number of integers"<<endl;
    cin>>n;
    arr=new int[n];
    for (int i = 0; i < n; i++)
    {
        cin>>*(arr+i);
    }
    int sum=summ(arr,n);
    int avg=averagee(arr,n);
    int max=maximumm(arr,n);
    int min=minimumm(arr,n);
    cout<<sum<<endl;
    cout<<avg<<endl;
    cout<<max<<endl;
    cout<<min<<endl;
    delete[] arr;
    return 0;
}