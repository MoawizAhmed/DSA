#include <iostream>
using namespace std;
// int power(int x,int n)
// {
//  if(n==0)
//  {
//     return 1;
//  }
//  return x*power(x,n-1);
// }
// logarithmic approach:
int power(int x,int n)
{
 if(n==0)
 {
    return 1;
 }
 int call=power(x,n/2);
 
 if(n%2!=0)
 {
  return call*call*x;
 }
 
 return call*call;
}
int main()
{
    cout<<power(3,10);
    return 0;
}