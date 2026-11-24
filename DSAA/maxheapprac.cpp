#include <iostream>
using namespace std;
class heap
{
 private:
 int *arr;
 int size;
 int capacity;
 public:
 heap(int capacity)
 {
  size=0;
  this->capacity=capacity;
  arr=new int[this->capacity];
 }
 int getparent(int i)
 {
  return i/2;
 }
 int getleftchild(int i)
 {
    return i*2+1;
 }
 int getrightchile(int i)
 {
    return i*2+2;
 }
 void swap(int &a,int &b)
 {
  int temp=a;
  a=b;
  b=temp;
 }
 void heapifyup(int i)
 {
  while(i>0 && getparent(i) < arr[i])
  {
    swap(arr[getparent(i)],arr[i]);
    i=getparent(i);
  }
}
void heapifydown(int i)
{
  int l=getleftchild(i);
  int r=getrightchile(i);

  int largest=i;

  while(true)
  {
    if(l<size && arr[l] > arr[largest])
    {
     largest=l;
    }
    if(r<size && arr[r] > arr[largest])
    {
     largest=r;
    }
   if(largest==i)
   {
    return;
   }
   swap(arr[i],arr[largest]);
   i=largest;
  }
}
bool isempty(){return size==0;}
bool isfull(){return size==capacity;}
void insert(int value)
{
    if(size==capacity){cout<<"Heap is full"<<endl;return;}
    arr[size++]=value;
    heapifyup(size-1);
}
int peek()
{
    if(isempty())
    {
      cout<<"Heap is empty"<<endl;
      return -1;  
    }
 return arr[0];
}
int deletemax()
{
  if(isempty()){ cout<<"Heap is empty"<<endl;}
  int top=arr[0];
  arr[0]=arr[size-1];
  size--;
if(size>0)
{
  heapifydown(0);
}

return top;
}
    void buildHeap(int a[], int n) {

        if (n > capacity) {
            cout << "Array too large!" << endl;
            return;
        }

        for (int i = 0; i < n; i++) {
            arr[i] = a[i];
        }

        size = n;

        for (int i = n / 2 - 1; i >= 0; i--) {
            heapifydown(i);
        }
    }
};
int main()
{

    return 0;
}