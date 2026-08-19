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

    cout<<"r1 after modifying r2:"<<endl;
    r1.display();

    /*
    r1 and r2 have the same width pointer because the default
    copy constructor performs a shallow copy.

    Therefore, when both objects are destroyed, both destructors
    will try to delete the same memory address.

    This causes a double deletion problem.
    */

    return 0;
}