#include <iostream>
using namespace std;
void shellsort(int arr[],int n)
{
  for (int i = n/2; i > 0; i/=2)
  {
    for (int j = i; j < n ; j++)
    {
        int temp=arr[j];
        int res=j;
        while(res>=i && arr[res-i]>temp)
        {
            arr[res]=arr[res-i];
            res-=i;
        }
        arr[res]=temp;
    }
            for (int k = 0; k < n; k++)
        {
            cout<<arr[k]<<" ";
        }
        cout<<endl;
  }
  
}
int main()
{
    const int n=5;
    int arr[n]={12,34,54,2,3};
    shellsort(arr,n);
    return 0;
}

/*because it compares and moves elements that are far apart using gaps, reducing large 
disorder early. By the time the gap becomes 1, the array is already mostly sorted, so 
the final insertion-sort pass is much faster.*/