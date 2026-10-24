#include <iostream>
using namespace std;
//=============== A L G O R I T H M S =============
//radix sort
 void countsort(int arr[],int n,int place)
 {
  int *arr2=new int[n];
  for (int i = 0; i < n; i++)
  {
     arr2[i]=0;
  }
  int count[10]={0,0,0,0,0,0,0,0,0,0};
  for (int i = 0; i < n; i++)
  {   int digit=(arr[i]/place)%10;
     count[digit]++;
  }
  for (int i = 1; i < 10 ; i++)
  {
     count[i]=count[i]+count[i-1];
  }
  for (int i = n-1; i >= 0; i--)
  {
     int digit=(arr[i]/place)%10;
     arr2[--count[digit]]=arr[i];
  }
  for (int i = 0; i < n; i++)
  {
     arr[i]=arr2[i];
  }
  delete[] arr2;
 }
int getmax(int arr[],int n)
{
    int max=0;
 for (int i = 0; i < n; i++)
 {
    if (arr[i]>max)
    {
        max=arr[i];
    }
 }
 return max;
}

void radixsortcounting(int arr[],int n)
{
  int max=getmax(arr,n);
  int pos=0;
  while(max>0)
  {
   max=max/10;
   pos++;
  }
 int place = 1;

    for (int i = 1; i <= pos; i++)
    {
        countsort(arr, n, place);
        place *= 10;
    }
}

void radixsortbucket(int arr[],int n)
{
  int max=getmax(arr,n);
  int pos=0;
 while (max>0)
 {
    max=max/10;
    pos++;
 }
 int place=1;
 for (int i = 1; i <= pos; i++)
 {
    int bucket[10][100];
    int count[10]={0,0,0,0,0,0,0,0,0,0};
    int *output=new int[n];
    for (int i = 0; i < n; i++)
    {
        int digit=(arr[i]/place)%10;
        bucket[digit][count[digit]]=arr[i];
        count[digit]++;
    }
    int index=0;
    for (int i = 0; i < 10; i++)
    {
    for (int j = 0; j < count[i]; j++)
    {
        output[index]=bucket[i][j];
        index++;
    }
    }
    for (int i = 0; i < n; i++)
    {
        arr[i]=output[i];
    }
    delete[] output;
    place *= 10;
 }
}


//merge sort
void merge(int arr[],int l,int m,int r)
{
  int n1=m-l+1;
  int n2=r-m;
  int *la=new int[n1];
  int *ra=new int[n2];

for (int i = 0; i < n1; i++)
{
        la[i] = arr[l+i];
} 
for (int i = 0; i < n2; i++)
{
        ra[i] = arr[m+i+1];
} 
int i=0,j=0;int k=l;
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
    arr[k++]=la[j++]; 
}
delete[] la;
delete[] ra;
}
void mergesort(int arr[],int l,int r)
{
  if (l<r)
  {
    int mid=l+(r-l)/2;
    mergesort(arr,l,mid);
    mergesort(arr,mid+1,r);
    merge(arr,l,mid,r);
  }
  
}
//quick sort

void quicksort(int arr[],int l,int u)
{
  if (l<u)
  {
   int start=l;
   int end=u;
   int pivot=arr[l];
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
   quicksort(arr,l,end-1);
   quicksort(arr,end+1,u);
  }
  
}
int main()
{
    int arr[]={3132,434,411,132,1411,1123,116,5,82,43,1111,121};
     quicksort(arr,0,11);
     for (int i = 0; i < 12; i++)
     {
        cout<<arr[i]<<" ";
     }
     
  return 0;
}