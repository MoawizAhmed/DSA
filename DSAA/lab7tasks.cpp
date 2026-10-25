#include <iostream>
using namespace std;
int getmax(int arr[],int n)
{
    int max=arr[0];
  for (int i = 0; i < n; i++)
  {
   if (arr[i]>max)
   {
    max=arr[i];
   }
  }
  return max;
}
void radixsort(int arr[],int n)
{
    int max=getmax(arr,n);
    int pos=0;
    while (max>0)
    {
        max/=10;
        pos++;
    }
    int place=1;
 for (int k = 1; k <= pos; k++)
 {
 int *output=new int[n];
 int count[10]={0,0,0,0,0,0,0,0,0,0};
 for (int i = 0; i < n; i++)
 {
    int digit=(arr[i]/place)%10;
    count[digit]++;
 }
 for (int i = 1; i < 10; i++)
 {
     count[i]+=count[i-1];
 }
 
 for (int i = n-1; i >= 0; i--)
 {
    int digit=(arr[i]/place)%10;
    output[--count[digit]]=arr[i];
 }
 for (int i = 0; i < n; i++)
 {
    arr[i]=output[i];
 }
 delete[] output;
  place*=10;
 }
}

void merge(int arr[],int l,int m,int r)
{
  int n1=m-l+1;
  int n2=r-m;
  int *la=new int[n1];
  int *ra=new int[n2];
  for (int i = 0; i < n1; i++)
  {
    la[i]=arr[l+i];
  }
  for (int i = 0; i < n2; i++)
  {
    ra[i]=arr[m+i+1];
  }
  int i=0;int j=0; int k=l;
  while (i<n1 && j<n2)
  {
    if (la[i]<ra[j])
    {
        arr[k++]=la[i++];
    }
    else
    {
        arr[k++]=ra[j++];
    }
  }
  while (i<n1)
  {
    arr[k++]=la[i++];
  }
  while (j<n2)
  {
    arr[k++]=ra[j++];
  }
  delete[] la;
  delete[] ra;
}

void mergesort(int arr[], int l, int r)
{
   if (l<r)
   {
    int m=l+(r-l)/2;
    mergesort(arr,l,m);
    mergesort(arr,m+1,r);
    merge(arr,l,m,r);
   }
}

 int partition(int arr[],int l,int u)
 {
 int pivot=arr[l];
 int start=l;
 int end=u;
 while (start<end)
 {
     while (arr[start]<=pivot)
     {
         start++;
     }
     while (arr[end]>pivot)
     {
         end--;
     }
     if (start<end)
     {
         int temp=arr[start];
         arr[start]=arr[end];
         arr[end]=temp;
     }
 }
 int temp=arr[l];
 arr[l]=arr[end];
 arr[end]=temp;
 return end;
 }
 void quicksort(int arr[],int l, int u)
 {
    if (l<u)
    {
     int loc=partition(arr,l,u);
      quicksort(arr,l,loc-1);
      quicksort(arr,loc+1,u);
    }
   
}

int main()
{
    const int n=5;
    int arr[n]={111,222,334,341,245};
    // radixsort(arr,n);
    // mergesort(arr,0,4);
    quicksort(arr,0,4);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}