#include <iostream>
using namespace std;
class dynamicsafearray
{
private:
int capacity;
int count;
int *arr;
public:
  dynamicsafearray(int initialcapacity)
  {
    arr=new int[initialcapacity];
    capacity=initialcapacity;
    count=0;
  }
  void pushback(int val)
  {
    if(capacity==count)
    {
        if(capacity==0)
        {
     int *newarr=new int[2];
     capacity=2;
     newarr[count++]=val;
     delete[] arr;
     arr=newarr;
        }
        else
        {
     int *newarr=new int[capacity*2];
     capacity=capacity*2;
     for (int i = 0; i < count; i++)
     {
       newarr[i]=arr[i];
     }
     newarr[count++]=val;
     delete[] arr;
     arr=newarr;
    }
    }
    else
    {
        arr[count++]=val;
    }
  }
  void set(int pos,int val)
  {
    if(pos>=count || pos<0)
    {
        cout<<"wrong position requested!"<<endl;
        return;
    }
    else
    {
        arr[pos]=val;
    }
  }
int get(int pos)
{
    if(pos>=count || pos<0)
    {
        cout<<"wrong position requested!"<<endl;
        return -1;
    }
    else
    {
        return arr[pos];
    }
}
bool removeAt(int pos)
{
    if(pos>=count || pos<0)
    {
        cout<<"wrong position requested!"<<endl;
        return false;
    }
    for (int i = pos; i <count-1 ; i++)
    {
      arr[i]=arr[i+1];
    }
    count--;
    return true;
}
void display()
{
    for (int i = 0; i < count; i++)
    {
      cout<<arr[i]<<endl;
    }
}
};
int main()
{
   dynamicsafearray d1(2);
   d1.pushback(1);
   d1.pushback(2);
   d1.pushback(3);
   d1.pushback(4);
   d1.pushback(5);
   d1.pushback(6);
   d1.removeAt(3);
   d1.set(-1,10);
   cout<<d1.get(10)<<endl;
   d1.display();
    return 0;
}