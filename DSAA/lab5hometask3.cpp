#include <iostream>
using namespace std;
class stack
{
 private:
 int top;
 char *arr;
 int size;
 public:
 stack(int val)
 {
  size=val;
  top=-1;
  arr=new char[size];
 }
 void push(char val)
 {
  if (top==size-1)
  {
    cout<<"overflow"<<endl;
    return;
  }
  arr[++top]=val;
 }
 char pop()
 {
    if (top==-1)
    {
    cout<<"underflow"<<endl;
    return -1;
    }
    return arr[top--];
 }
 void display()
 {
    for (int i =0; i <= top; i++)
    {
        cout<<arr[i];
    }
    cout<<endl;
 }
 bool isempty()
 {
    if (top==-1)
    {
        return true;
    }
    
    return false;
 }
 char peek(){return arr[top];}
};
 bool balancedparanthesis(string par)
{
    if (par == "")
    {
        return false;
    }

    int length = par.length();
    stack s(length);

    for (int i = 0; i < length; i++)
    {
        char c = par[i];

        if (c == '{' || c == '(' || c == '[')
        {
            s.push(c);
        }
        else if (c == '}' || c == ')' || c == ']')
        {
            if (s.isempty())
            {
                return false;
            }

            char nig = s.pop();

            if (nig == '{' && c != '}')
            {
                return false;
            }

            if (nig == '(' && c != ')')
            {
                return false;
            }

            if (nig == '[' && c != ']')
            {
                return false;
            }
        }
    }

    return s.isempty();
}
int main()
{
  cout<<balancedparanthesis("{A+(B*C)-[D/E]}");
  cout<<balancedparanthesis("{A+(B*C)-[D/E]");
  cout<<balancedparanthesis("(A+B]");
    return 0;
}