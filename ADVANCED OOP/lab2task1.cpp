#include <iostream>
using namespace std;
class safearray
{
private:
 int **arr;
 int rows;
 int cols;
 public:
 safearray(int rows,int cols)
 {
    this->rows=rows;
    this->cols=cols;
    arr=new int*[this->rows];
    for (int i = 0; i < this->rows; i++)
    {
        arr[i]=new int[this->cols];
    }
 }
 void set(int r,int c,int val)
 {
    if (r >= rows || c >= cols || r < 0 || c < 0)
       {
           cout << "Boundary Error" << endl;
           return;
       }
    arr[r][c]=val;
 }
 int get(int r,int c)
 {
    if(r>=rows || c>=cols || r<0 || c<0)
    {
        cout<<"Boundary Error"<<endl;
        return -1;
    }
    return arr[r][c];
 }
void display()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout<<arr[i][j]<<" ";
        }
    cout<<endl;
    }
}
~safearray()
{
    for (int i = 0; i < rows; i++)
    {
    delete[] arr[i];
    }
    delete[] arr;
}
};
int main()
{
    safearray s1(4,4);
    s1.set(0,0,1);
    s1.set(0,1,2);
    s1.set(0,2,3);
    s1.set(0,3,4);
    s1.set(1,0,5);
    s1.set(1,1,6);
    s1.set(1,2,7);
    s1.set(1,3,8);
    s1.set(2,0,9);
    s1.set(2,1,10);
    s1.set(2,2,11);
    s1.set(2,3,12);
    s1.set(3,0,13);
    s1.set(3,1,14);
    s1.set(3,2,15);
    s1.set(3,3,16);
    s1.display();
    s1.get(-1,2);
    s1.get(1,10);
    s1.get(4,1);
    return 0;
}