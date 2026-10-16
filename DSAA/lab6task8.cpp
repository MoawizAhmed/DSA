#include <iostream>
using namespace std;
bool maze(int **arr,int x,int y,int r,int c,int **visited)
{
  if (x < 0 || x >= r || y < 0 || y >= c)
        return false;

if (arr[x][y]==1 && x==r-1 && y==c-1)
{
    return true;
}

if ( x<r && x>=0 && y<c && y>=0 && arr[x][y]==1 && visited[x][y]==0)
{
    visited[x][y]=1;
    if(maze(arr,x+1,y,r,c,visited))
    {return true;}
    if(maze(arr,x,y+1,r,c,visited))
    {return true;}
    if(maze(arr,x-1,y,r,c,visited))
    {return true;}
    if(maze(arr,x,y-1,r,c,visited))
    {return true;}
     visited[x][y]=0;
    return false;
}
return false;
}
int main()
{
  int **arr;
  int r,c;
  cout<<"Enter the number of rows:"<<endl;
  cin>>r;
  arr=new int*[r];
  cout<<"Enter the number of columns"<<endl;
  cin>>c;
  for (int i = 0; i < r; i++)
  {
   arr[i]=new int[c];
  }
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
     cout<<"Enter the ( "<<i+1<<" , "<<j+1<<" ) element"<<endl;
     cin>>arr[i][j];   
    }
  }
  int **visited;
  visited=new int*[r];
  for (int i = 0; i < r; i++)
  {
     visited[i]=new int[c];
  }
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
        visited[i][j]=0;
    }
  }
  
//   for (int i = 0; i < r; i++)
//   {
//     for (int j = 0; j < c; j++)
//     {
//      cout<<visited[i][j];
//     }
//   }
  
    return 0;
}