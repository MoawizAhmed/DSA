#include <iostream>
using namespace std;
class dynamicarray
{
private:
  int *arr;
  int size;
  int capacity;
public:
  dynamicarray(int capacity=2)
  {
    this->capacity=capacity;
    this->size=0;
    this->arr=new int[capacity];
  }
  void pushback(int value)
  {
  if (size==capacity)
  {
    int *newblock;
    capacity*=2;
    newblock=new int[capacity];
    for (int i = 0; i < size; i++)
    {
     newblock[i]=arr[i];
    }
    newblock[size++]=value;
    delete[] arr;
    arr=newblock;
  }
  else
  {
  arr[size++]=value;
  }
}
int& operator[](int index)
{
   if (index<0 || index>=size)
   {
    throw out_of_range("Invalid index");
   }
   return arr[index];
}
~dynamicarray()
{
    delete[] arr;
      cout<<"destructor called"<<endl;
}
dynamicarray(const dynamicarray& d)
{
    this->size=d.size;
    this->capacity=d.capacity;
    this->arr=new int[this->capacity];
    for (int i = 0; i < this->size; i++)
    {
        this->arr[i]=d.arr[i];
    }
}
dynamicarray operator=(const dynamicarray& d)
{
    if(this==&d)
    {
        return dynamicarray(0);
    }
  this->size=d.size;
  this->capacity=d.capacity;
    this->arr=new int[this->capacity];
    for (int i = 0; i < this->size; i++)
    {
        this->arr[i]=d.arr[i];
    }
}
void print() const
{
    for (int i = 0; i < size; i++)
    {
      cout<<arr[i];
    }
}
};
int main()
{
  dynamicarray d1(2);
  d1.pushback(1);
  d1.pushback(2);
  d1.print();
  cout<<endl;
  d1.pushback(3);
  d1.pushback(4);
  d1.print();
  cout<<endl;
  d1.pushback(5);
  d1.pushback(6);
  d1.print();
  cout<<endl;
  dynamicarray d2(d1);
  d2.print();
  cout<<endl;
  dynamicarray d3(2);
  d3=d2;
  d3.print();
    return 0;
}