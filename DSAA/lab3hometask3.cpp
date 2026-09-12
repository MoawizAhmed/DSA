//int pos = low + ((key-arr[low])*(high-low)/(arr[high]-arr[low])  );
//corrected

#include <iostream>
using namespace std;
int interpolationsearch(int arr[],int n,int key)
{
    int iterations=0;
    int low=0;
    int high=n-1;
    while(low<=high && key >= arr[low] && key <= arr[high])
    {
        iterations++;
     if (arr[low]==arr[high])
     {
        if(arr[low]==key)
        {
        cout<<"iterations for interpolation search: "<<iterations<<endl;
        return low;
        }
          cout<<"iterations for interpolation search: "<<iterations<<endl;
        return -1;
     }
     if (arr[low]==key)
     {
          cout<<"iterations for interpolation search: "<<iterations<<endl;
        return low;
     }
     int pos=low+((key-arr[low])*(high-low)/(arr[high]-arr[low]));
     if (arr[pos]==key)
     {
        cout<<"iterations for interpolation search: "<<iterations<<endl;
        return pos;
     }
     else if(arr[pos]<key)
     {
        low=pos+1;
     }
     else
     {
        high=pos-1;
     }
    }
    return -1;
}

int binarysearch(int arr[],int n,int key)
{
  int iterations=0;
  int left=0;
  int right=n-1;
  while(left<=right)
  {
    iterations++;
     int mid=left+(right-left)/2;
    if (arr[mid]==key)
    {
        cout<<"iterations for binary search: "<<iterations<<endl;
        return mid;
    }
    else if(arr[mid]<key)
    {
      left=mid+1;
    }
    else
    {
        right=mid-1;
    }
  }
  return -1;
}
int main()
{
   const int n1=20;
   int arr1[n1]={5,10,15,20,25,30,35,40,45,50,55,60,65,70,75,80,85,90,95,100};
const int n2=6;
int arr2[n2]={1,2,3,4,5,1000};


  int answer1=interpolationsearch(arr1,n1,100);
  cout<<answer1<<endl;
  
  int missing = interpolationsearch(arr1, n1, 99);
  cout << "Search for 99 (missing): " << missing << endl;

    int answer2=interpolationsearch(arr2,n2,1000);
    cout<<"answer for interpolation search: "<<answer2<<endl;

    int answer3=binarysearch(arr2,n2,1000);
    cout<<"answer for binary search: "<<answer3<<endl;
return 0;
}


//task 3 part 13
/*
Interpolation Search estimates where the key should be based on the values, 
so when the data is uniformly distributed, the estimate is usually very accurate
, giving an average of O(log log n). With non-uniform data, the estimated position
 can be far from the key, causing many more searches and potentially degrading to O(n).*/