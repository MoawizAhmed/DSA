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
bool isoperator(char ch)
{
    if (ch == '+' || ch == '-'
    ||  ch == '/' || ch == '*'
    ||   ch == '^')
    {
        return true;
    }
    else
    {
        return false;
    }
}
int presidence(char ch)
{
  if (ch == '+' || ch == '-')
  {
    return 1;
  }
  else if (ch == '*' || ch == '/')
  {
    return 2;
  }
  else if (ch == '^')
  {
    return 3;
  }
}
bool balancedparanthesis(string str)
{
  int length=str.length();
  stack s(length);
  for (int i = 0; i < length; i++)
  {
    char ch=str[i];
    if (ch=='(')
    {
        s.push('(');
    }
    else if (ch==')')
   {
       if (s.isempty())
    {
        return false;
    }
    char nigga=s.pop();
    if (nigga!='(')
    {
        return false;
    }
   }
  }
  return s.isempty();;
}
string prefix(string infix)
{
  string postfix="";
  int length=infix.length();
  stack s(100);
  if (!balancedparanthesis(infix))
  {
    return "invalid paranthesis";
  }
  
  for (int i = length-1; i >= 0 ; i--)
  {
    char ch=infix[i];
    if (ch == '(')
    { 
        ch = ')';
    }
     else if (ch == ')')
     {
        ch = '(';
     }

    if (ch>='a' && ch<='z' 
    ||  ch>='A' && ch<='Z')
    {
      postfix+=ch;
    }
    else if (ch=='(')
    {
      s.push(ch);
    }
    else if (ch==')')
    {
        while (!s.isempty() && s.peek()!='(')
        {
            char nigga=s.pop();
            postfix+=nigga;
        }
        if (!s.isempty())
        {
            s.pop();
        }
    }
    else if (isoperator(ch))
    {
       while (!s.isempty() && s.peek() != '(' &&
       (presidence(s.peek()) > presidence(ch) ||
       (presidence(s.peek()) == presidence(ch) && s.peek() == '^')))
        {
            postfix+=s.pop();
        }
        s.push(ch);
    }
    
  }
  while (!s.isempty())
  {
    postfix+=s.pop();
  }
  string prefix="";
  for (int i = length-1; i >= 0; i--)
  {
    prefix+=postfix[i];
  }
  return prefix;
}
int main()
{
  cout<<prefix("A+B*(C^D-E)")<<endl;
};