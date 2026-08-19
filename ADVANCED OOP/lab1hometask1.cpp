#include <iostream>
#include <cstring>
using namespace std;
class dynamicstring
{
private:
char *data;
public:
dynamicstring(const char* str)
{
  data=new char[strlen(str)+1];
  for (int i = 0; i < strlen(str); i++)
  {
    data[i]=str[i];
  }
  data[strlen(str)]+='\0';
}
dynamicstring(){}
~dynamicstring()
{
    delete[] data;
    cout<<"destructor called"<<endl;
}
dynamicstring(const dynamicstring& obj)
{
  this->data=new char[strlen(obj.data)+1];
  for (int i = 0; i <strlen(obj.data) ; i++)
  {
    this->data[i]=obj.data[i];
  }
  data[strlen(obj.data)]+='\0';
}
dynamicstring& operator =(const dynamicstring &d)
{
    if(this==&d)
    {
        return *this;
    }
  delete[] this->data;
  this->data=new char[strlen(d.data)+1];
  for (int i = 0; i < strlen(d.data); i++)
  {
    this->data[i]=d.data[i];
  }
  data[strlen(d.data)]+='\0';
  return *this;
}
int length() const
{
    return strlen(data);
}
void display() const 
{
    for(int i=0;i<strlen(data);i++)
    {
     cout<<data[i];
    }
    cout<<endl;
}
void setchar(int index,char c)
{
  data[index]=c;
}
};

int main()
{
  dynamicstring d1("hellonigga");
  dynamicstring d2(d1);
  dynamicstring d3;
  d3=d2;
  d3.setchar(4,' ');
  d1.display();
  d3.display();
    return 0;
}