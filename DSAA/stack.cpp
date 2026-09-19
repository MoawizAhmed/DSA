#include <iostream>
using namespace std;
class stack
{
  private:
  int* arr;
  int size;
  int capacity;
  public:
  stack(int capacity)
  {
    this->capacity=capacity;
    arr=new int[capacity];
    size=0;
  }
  stack()
  {
    capacity=1;
    arr=new int[capacity];
    size=0;
  }
  void push(int val)
  {
  if (size==capacity)
  {
    capacity*=2;
    int *newarr=new int[capacity];
       for (int i = 0; i < size; i++)
    {
        newarr[i]=arr[i];
    }
    delete[] arr;
    arr=newarr;
  }
  arr[size++]=val;
  return;
  }
  void pop()
  {
    if (size==0)
    {
        cout<<"underload"<<endl;
        return;
    }
    size--;
  }
  void peek()
  {
   cout<<arr[size]<<endl;
   return;
  }
  bool isempty()
  {
  if (size==0)
  {
    return true;
  }
  return false;
  }
  bool isfull()
  {
    if (size==capacity)
    {
        return true;
    }
    return false;
  }
  int sizee()
  {
    return size;
  }
  int capacityy()
  {
    return capacity;
  }
  void resize(int newcapacity)
  {
    capacity=newcapacity;
    int *newarr=new int[capacity];
    for (int i = 0; i < size; i++)
    {
        newarr[i]=arr[i];
    }
    delete[] arr;
    arr=newarr;
  }
  void clear()
  {
    size=0;
  }
  void printt()
  {
    for (int i = size-1; i > -1; i--)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
  }
  void reverse()
  {
    int l=size-1;
    for (int i = 0; i <l/2; i++)
    {
        int temp=arr[i];
        arr[i]=arr[l];
        arr[l]=temp;
        l--;
    }
  }
  ~stack()
  {
    delete[] arr;
  }
  stack(const stack &s)
  {
   this->size=s.size;
   this->capacity=s.capacity;
   this->arr=new int[capacity];
   for (int i = 0; i < s.size; i++)
   {
     this->arr[i]=s.arr[i];
   }
  }
  stack& operator=(const stack& s)
  {
   if (this==&s)
   {
   return *this;
   }
   this->size=s.size;
   this->capacity=s.capacity;
   for (int i = 0; i < size; i++)
   {
    this->arr[i]=s.arr[i];
   }
   return *this;
  }
};
int main()
{
    stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.printt();
    s.reverse();
    s.printt();
return 0;
}