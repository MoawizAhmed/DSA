#include <iostream>
using namespace std;
void newmarksentry(int row,int cols,int **arr,int val,int *size)
{
  int *newarr=new int[cols];
  for (int i = 0; i < cols; i++)
  {
    newarr[i]=arr[row][i];
  }
  delete[] arr[row];
  arr[row]=new int[cols+1];
  for (int i = 0; i < cols; i++)
  {
    arr[row][i]=newarr[i];
  }
  arr[row][cols]=val;
  size[row]+=1;
  delete[] newarr;
}
int main()
{
    int **arr;
    int rows;
    cout<<"Enter the number of rows:"<<endl;
    cin>>rows;
  int *size = new int[rows];
    arr=new int*[rows];
    for (int i = 0; i <rows; i++)
    {
        cout<<"Enter the size of row "<<i+1<<endl; 
        cin>>size[i];
        arr[i]=new int[size[i]];
    }
    for (int i = 0; i < rows; i++)
    {
       for (int j = 0; j < size[i]; j++)
       {
        cout<<"Enter "<<i+1<<" row's elements"<<endl;
        cin>>arr[i][j];
       }
    }
     int highest=0;
     int lowest=0;
    for (int i = 0; i < rows; i++)
    {
        int average=0;
        cout<<"Marks of student " <<i+1<<" are :"<<endl;
    for (int j = 0; j < size[i]; j++)
    {
        cout<<arr[i][j]<<endl;
        average+=arr[i][j];
    }
    average=average/size[i];
    cout<<endl;
    cout<<"Average of " <<i+1 <<" student is: "<<endl;
    cout<<average<<endl;
    if(i==0)
    {
    highest=average;
    lowest=average;
    }
    if (average>highest)
    {
    highest=average;
    }
    if (average<lowest)
    {
    lowest=average;
    }
    }
    cout<<"HIGHEST AVERAGE: "<<highest<<endl;
    cout<<"LOWEST AVERAGE: "<<lowest<<endl;
    int change;
    cin>>change;
    newmarksentry(change-1,size[change-1],arr,100,size);
cout << "FINAL DISPLAY START" << endl;
       for (int i = 0; i < rows; i++)
    {
        cout<<"Marks of student " <<i+1<<" are :"<<endl;
    for (int j = 0; j < size[i]; j++)
    {
        cout<<arr[i][j]<<endl;
    }
}
      for (int i = 0; i < rows; i++)
      {
        delete[] arr[i];
      }
      delete[] arr;
     delete[] size;
    return 0;
}