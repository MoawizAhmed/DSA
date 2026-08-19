#include <iostream>
using namespace std;

class rectangle
{
  public:
   int *width;
   int *height;
   int area;

   rectangle(int w,int h)
   {
    width=new int;
    height=new int;

    *(width)=w;
    *(height)=h;
   }

   rectangle(const rectangle &other)
   {
    width=new int(*other.width);
    height=new int(*other.height);
   }

   int areaa()
   {
    area=(*width)*(*height);
    return area;
   }

   void display()
   {
    cout<<"Width: "<<*width<<endl;
    cout<<"Height: "<<*height<<endl;
    cout<<"Area: "<<areaa()<<endl;
   }

   ~rectangle()
   {
    delete height;
    delete width;

    cout<<"RECTANGLE DESTROYED"<<endl;
   }
};

int main()
{
    rectangle r1(4,5);

    rectangle r2=r1;

    cout<<"Address stored in r1 width: "<<r1.width<<endl;
    cout<<"Address stored in r2 width: "<<r2.width<<endl;

    *(r2.width)=10;

    cout<<"r1:"<<endl;
    r1.display();

    cout<<"r2:"<<endl;
    r2.display();

    return 0;
}

/*
In Task 3, the default copy constructor made a shallow copy. This means r1 and r2 had the same addresses in their width and height pointers. So when we changed r2, r1 was also changed.

In this task, we made our own copy constructor. It creates new memory for r2 and copies the values from r1 into that new memory.
*/
