#include <iostream>
using namespace std;
class rectangle
{
  private:
   int *width;
   int *height;
   int area;
  public:
  rectangle(int w,int h)
  {
   width=new int;
   height=new int;
   *(width)=w;
   *(height)=h;
  }
   const int areaa()
  {
   area =(*width)*(*height);
   return area;
  }
  void display()
  {
    cout<<area<<endl;
    cout<<*height<<endl;
    cout<<*width<<endl;
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
rectangle r(2,3);
r.areaa();
r.display();
    return 0;
}