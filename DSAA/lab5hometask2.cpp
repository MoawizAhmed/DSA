/*
In a linear queue, rear only moves forward, so after dequeuing elements,
the empty spaces at the front cannot be reused and the queue may report full.
A circular queue solves this by wrapping rear back to the beginning of the
array using modulo, allowing the queue to reuse the free spaces.
*/
#include <iostream>
using namespace std;
 class queue
 {
   private:
   int front;
   int rear;
   int size;
   int *arr;
   public:
   queue(int size)
   {
     this->size=size;
     arr=new int[size];
     rear=0;
     front=0;
   }
   int getsize()
   {
     return size;
   }
   int getfront(){return front;}
   int getrear(){return rear;}
   void enqueue(int val)
   {
     if (rear==size)
     {
       cout<<"overflow"<<endl;
       return;
     }
    arr[rear++]=val;
   }
   void dequeue()
   {
     if (rear==front)
     {
       cout<<"empty"<<endl;
       return;
     }
     front++;
   }
   bool isfull()
   {
    if (rear==size)
    {
        return true;
    }
    else
    {
        return false;
    }
   }
   bool isempty()
   {
    if (rear==front)
    {
        return true;
    }
    return false;
   }
   void display()
   {
     for (int i = front; i < rear; i++)
     {
       cout<<arr[i];
     }
     cout<<endl;
   }
};
int main()
{
  queue q(5);
  q.enqueue(10);
  q.enqueue(20);
  q.enqueue(30);
  q.enqueue(40);
  q.enqueue(50);
  q.dequeue();
  q.dequeue();
  q.dequeue();
  q.enqueue(60);
  q.enqueue(70);
  q.dequeue();
  q.dequeue();
  q.dequeue();
  q.display();
    return 0;
}
