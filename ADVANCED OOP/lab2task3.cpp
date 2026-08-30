#include <iostream>
using namespace std;
void allocate(int **&arr,int &rows,int &cols)
{
    int row;
    int col;
  cout<<"Enter the number of rows: "<<endl;
  cin>>row;
  cout<<"Enter the number of columns: "<<endl;
  cin>>col;
  rows=row;
  cols=col;
  arr=new int*[row];
  for (int i = 0; i < row; i++)
  {
    arr[i]=new int[col];
  }
}
void fillingarray(int **arr,int rows,int cols)
{
   for (int i = 0; i < rows; i++)
   {
    for (int j = 0; j < cols; j++)
    {
        cin>>arr[i][j];
    }
   }
}
void addition(int **arr1,int **arr2,int &row1,int &col1,int &row2,int &col2)
{
  if (row1!= row2 || col1!=col2)
  {
    cout<<"Wrong dimentions for addition!"<<endl;
    return;
  }
  int **arr=new int*[row1];
  for (int i = 0; i < row1; i++)
  {
    arr[i]=new int[col1];
  }
  for (int i = 0; i < row1; i++)
  {
    for (int j = 0; j < col1; j++)
    {
       arr[i][j]=arr1[i][j]+arr2[i][j];
    }
    
  }
  for (int i = 0; i < row1; i++)
  {
    for (int j = 0; j < col1; j++)
    {
       cout<<arr[i][j]<<" ";
    }
    cout<<endl;
  }
}
void multiply(int **arr1,int **arr2,int &row1,int &col1,int &row2,int &col2)
{
if (row2!= col1)
  {
    cout<<"Wrong dimentions for multiplication!"<<endl;
    return;
  }
  int **arr=new int*[row1];
  for (int i = 0; i < row1; i++)
  {
    arr[i]=new int[col2];
  }
  int row=row1;
  int col=col2;
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < col; j++)
    {
         int temp=0;
        for (int k = 0; k <col1 ; k++)
        {       
       temp+=arr1[i][k]*arr2[k][j];
        }
        arr[i][j]=temp;
    }
  }
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < col; j++)
    {
       cout<<arr[i][j]<<" ";
    }
    cout<<endl;
  }
}
int main()
{
 int **arr1;
 int *row1=new int;
 int *col1=new int;
 int **arr2;
 int *row2=new int;
 int *col2=new int;
 allocate(arr1,*row1,*col1);
 allocate(arr2,*row2,*col2);
 fillingarray(arr1,*row1,*col1);
 fillingarray(arr2,*row2,*col2);
 int option;
while(1){
 cout<<"Enter the option: "<<endl;
 cout<<"1.ADDITION\n2.MULTIPLICATION\n3.EXIT\n"<<endl;
 cin>>option;
 switch (option)
 {
 case 1:
    addition(arr1,arr2,*row1,*col1,*row2,*col2);
    break;
case 2:
    multiply(arr1,arr2,*row1,*col1,*row2,*col2);
    break;
case 3:
  return 0;
 default:
 return 0;
    break;
 }
}
}