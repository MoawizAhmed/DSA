//circular queue using dma array
#include <iostream>
using namespace std;
class queue
{
 private:
int *arr;
int size;
int capacity;
int rear;
int front;
 public:
 queue(int capacity)
 {
  this->capacity=capacity;
  arr=new int[capacity];
  rear=0;
  front=0;
  size=0;
 }
 bool isfull()
 {
    return size==capacity;
 }
 bool isempty()
 {
    return size==0;
 }
 void enqueue(int val)
 {
    if (isfull())
    {
        int oldcapacity=capacity;
        capacity*=2;
        int *newarr=new int[capacity];
        for (int i = 0; i < size; i++)
        {
            newarr[i]=arr[(front+i)%oldcapacity];
        }
        delete[] arr;
        arr=newarr;
        front=0;
        rear=size;
    }
     arr[rear]=val;
    rear=(rear+1)%capacity;
     size++;
 }
 void dequeue()
 {
    if (isempty())
    {
        cout<<"already empty"<<endl;
        return;
    }
    size--;
    front=(front+1)%capacity;
    
 }
};
int main()
{

    return 0;
}