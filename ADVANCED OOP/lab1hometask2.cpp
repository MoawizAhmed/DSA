#include <iostream>
#include <cstring>
using namespace std;
class matrix
{
private:
int rows;
int cols;
int **arr;
public:
matrix(int r,int c)
{
 rows=r;
 cols=c;
 arr=new int*[r]();
 for (int i = 0; i < r; i++)
 {
    arr[i]=new int[c]();
 }
}
~matrix()
{
    for (int i = 0; i < rows; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
  cout<<"destructor called"<<endl;
}
matrix(const matrix& m)
{
   this->arr=new int*[m.rows]();
   for (int i = 0; i < m.rows; i++)
   {
    this->arr[i]=new int[m.cols]();
   }
   this->rows=m.rows;
   this->cols=m.cols;
   for (int i = 0; i < this->rows; i++)
   {
    for (int j = 0; j < this->cols; j++)
    {
        this->arr[i][j]=m.arr[i][j];
    }
   }
}
void set(int r,int c,int value)
{
    if(r<0) return;
    if(c<0) return;
    if(r>=rows) return;
    if(c>=cols) return;

   arr[r][c]=value;
}
int get(int r,int c) const
{
        if(r<0) return -1;
    if(c<0) return -1;
    if(r>=rows) return -1;
    if(c>=cols) return -1;

  return arr[r][c];
}
void display() const
{
 for (int i = 0; i < rows; i++)
 {
    for (int j = 0; j < cols; j++)
    {
        cout<<arr[i][j];
    }
    cout<<endl;
 }
}
matrix operator +(const matrix& m)
{
    if(this->rows==m.rows && this->cols==m.cols)
    {
    matrix newmatrix(m.rows,m.cols);
    for (int i = 0; i < newmatrix.rows; i++)
    {
        for (int j = 0; j < newmatrix.cols; j++)
        {
            newmatrix.arr[i][j]=this->arr[i][j]+m.arr[i][j];
        }
    }
 return newmatrix;
     }
     else
     {
        cout<<"wrong bounds"<<endl;
        return matrix(0,0);
     }
}
matrix& operator =(const matrix& m)
{
    if(this==&m) return *this;
   this->rows=m.rows;
   this->cols=m.cols;
    for (int i = 0; i < rows; i++)
    {
        delete[] arr[i];
    }
    delete[] arr; 
   this->arr=new int*[rows]();
   for (int i = 0; i < rows; i++)
   {
    this->arr[i]=new int[cols]();
   }
   for (int i = 0; i < rows; i++)
   {
    for (int j = 0; j < cols; j++)
    {
        this->arr[i][j]=m.arr[i][j];
    }
   }
   return *this;
}
};
int main()
{
   matrix m1(2,2);
   matrix m2(2,2);
   m1.set(0,1,6);
   m2.set(0,1,5);
   matrix m3(2,2);
      m1.display();
   m2.display();
   m3.display(); 
   m3=m1+m2;
   m1.display();
   m2.display();
   m3.display(); 
    return 0;
}