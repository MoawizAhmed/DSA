#include <iostream>
using namespace std;
bool palindrome(string s,int start,int end,int endd)
{
    if(start>=end)
    {
     return true;
    }
    if (s[start]==s[end])
    {
       return palindrome(s,start+1,end-1,endd);
    }
    else
    {
    return false;
    }
}
int main()
{
    string s;
    cout<<"Enter the string:"<<endl;
    cin>>s;
    int end=s.length()-1;
    cout<<palindrome(s,0,end,end);
    return 0;
}