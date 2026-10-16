#include <iostream>
using namespace std;
bool issafe(int **board,int x,int y,int n)
{ 
    int i=x-1;
  while(i >= 0){
   if (board[i][y]==1)
   {

    return false;
   }
   i--;
}
 i=x-1;
 int j=y-1;
 while (i >= 0 && j >= 0)
 {
    if(board[i][j]==1)
    {
       
        return false;
    }
    i-=1;
    j-=1;
 }
 i=x-1;
 j=y+1;
 while ( i >= 0 && j >= 0)
 {
    if(board[i][j]==1)
    { 
        return false;
    }
    i-=1;
    j+=1;
 }
 return true;
}
bool queens(int **board,int x,int y,int n)
{
   if (x==n)
   {
    cout<<endl;
     return true;
   }
   for (int i = 0; i < n; i++)
   {
   if(issafe(board,x,i,n))
   {
    board[x][i]=1;
   if (queens(board,x+1,i,n))
   {
    cout<<"( "<<x<<" , "<<i<<" )"<<endl;
    return true;
   }
   board[x][i]=0;
   }
}
  return false;
}

int main()
{
  int **board;
  int n;
  cout<<"Enter the number of rows and columns (same):"<<endl;
  cin>>n;
  board=new int*[n];
  for (int i = 0; i < n; i++)
  {
    board[i]=new int[n];
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
        board[i][j]=0;
    }
  }
//    int **visited;
//    visited=new int*[n];
//    for (int i = 0; i < n; i++)
//    {
//     visited[i]=new int[n];
//    }
//      for (int i = 0; i < n; i++)
//   {
//     for (int j = 0; j < n; j++)
//     {
//         visited[i][j]=0;
//     }
//   }
  cout<<queens(board,0,0,n);
    return 0;
}