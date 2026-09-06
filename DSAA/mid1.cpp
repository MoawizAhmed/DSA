#include <iostream>
using namespace std;
// class song
// {   public:
//     string name;
//     song* next;
//     song* prev;
//    song(string name)
//    {
//     this->name=name;
//     this->next=nullptr;
//     this->prev=nullptr;
//    }
// };
// class playlist
// {
//  private:
//   song* head;
//   song* current;
//  public:
//   playlist()
//   {
//     this->head=nullptr;
//     current=head;
//   }
//    void addsong(string name)
//    {
//     song* soong=new song(name);
//     if(head==nullptr)
//     {
//      head=soong;
//      current=head;
//      return;
//     }
//    song* temp=head;
//    while(temp->next!=nullptr)
//    {
//     temp=temp->next;
//    }
//    soong->prev=temp;
//    temp->next=soong;
//    }
//    void removesong(string name)
//    {
//     song* temp=head;
//    while (temp != nullptr && temp->name!=name)
//    {
//      temp=temp->next;
//    }
//    if(temp==nullptr){ cout<<"Song Not Found"<<endl;return;}
//    if(temp->prev==nullptr)
//    {
//    song* tempp=temp->next;
//    head=tempp;
//    delete temp;
//    return;
//    }
//    if(temp->next==nullptr)
//    {song* tempp=temp->prev;
//     delete temp;
//     tempp->next=nullptr;
//     return;
//    }
//    song* temp2=temp->prev;
//    song* temp3=temp->next;
//    temp3->prev=temp2;
//    temp2->next=temp3;
//    delete temp;
//    }
//    void nextsong()
//    {
//     if(current->next==nullptr)
//     {
//         cout<<"Playlist ended"<<endl;
//         return;
//     }
//     current=current->next;
//    }
//    void specificsong(string name)
//    {
//     song* temp=head;
//     while (temp->name!=name)
//     {
//         temp=temp->next;
//     }
//     if(temp->next==nullptr)
//     {
//         cout<<"song not found"<<endl;
//         return;
//     }
//     current=temp;
//    }
//    void printcurrent()
//    {
//     cout<<current->name<<endl;
//    }
// };
// int main()
// {
//     playlist p;
//     p.addsong("Let it happen");
//     p.addsong("The less I know the better");
//     p.addsong("Borderline");
//     p.printcurrent();
//     p.nextsong();
//     p.printcurrent();
//     p.nextsong();
//     p.printcurrent();
//     p.nextsong();
//     return 0;
// }
// class stack
// {
//  private:
//  char* c;
//  int capacity;
//  int size;
//  public:
//  stack()
//  {
//     capacity=1;
//     c=new char[capacity];
//     size=0;
//  }
//  void push(char ch)
//  {
//   if(size==capacity)
//   {
//     char* temp=new char[capacity*2];
//     capacity*=2;
//     for (int i = 0; i < size; i++)
//     {
//         temp[i]=c[i];
//     }
//       delete[] c;
//     c=temp;
//     c[size++]=ch;
//      return;
//     }
//     c[size++]=ch;
//  }
//  void pop()
//  {
//     for (int i = 0; i < size-1; i++)
//     {
//         c[i]=c[i+1];
//     }
//     size--;
//  }
//  void reverse()
//  {
//     int i = 0;
//     int j = size - 1;

//     while(i < j)
//     {
//         char temp = c[i];
//         c[i] = c[j];
//         c[j] = temp;

//         i++;
//         j--;
//     }
//  }
//  void printt()
//  {
//     for(int i=0;i<size;i++)
//     {
//         cout<<c[i];
//     }
//  }
// };
// int main()
// {
//     stack s;
//     s.push('n');
//     s.push('i');
//     s.push('g');
//     s.push('g');
//     s.push('a');
//     s.reverse();
//     s.printt();
//     return 0;
// }
// class university
// {
//  private:
//  int iD;
//  double GPA;
//  string name;
//  int age;
//  public:
//  university(string name,int age,double gpa,int id)
//  {
//     this->age=age;
//     this->GPA=gpa;
//     this->name=name;
//     this->iD=id;
//  }
//  university(){}
//  university(university *u)
//  {
//   this->GPA=u->GPA;
//   this->age=u->age;
//   this->iD=u->iD;
//   this->name=u->name;
//  }
//  university& operator=(university *u)
//  {
//   university temp;
//   temp.age=u->age;
//   temp.name=u->name;
//   temp.iD=u->iD;
//   temp.GPA=u->GPA;
//   return temp;
//  }
//  float getgpa(){return GPA;}
// };
// int main()
// { 
//     const int n=5;
//     university s1("moawiz",18,3.1,1);
//     university s2("ali",19,2.6,2);
//     university s3("hamza",20,2.3,3);
//     university s4("arsal",20,2.9,4);
//     university s5("wajih",21,2.6,5);
//     university u[n]={s1,s2,s3,s4,s5};

//     for (int i = 0; i < n-1; i++)
//     {
//     for (int j = 0; j < n-i-1; j++)
//     {
//         if(u[j].getgpa()<u[j+1].getgpa())
//         {
//             university temp=u[j];
//             u[j]=u[j+1];
//             u[j+1]=temp;
//         }
//     }
//     }
    
//     return 0;
// }
// int main()
// {
//     const int m=5;
//     const int n=4;
//     int A[m]={1,2,3,4,5};
//     int B[n]={10,9,8,7};
//     int C[m+n];
//     for (int i = 0; i < n-1; i++)
//     {
//         for (int j = 0; j < n-i-1; j++)
//         {
//             if(B[j]>B[j+1])
//             {
//                 int temp=B[j];
//                 B[j]=B[j+1];
//                 B[j+1]=temp;
//             }
//         }
//     }
//     int j=0,k=0,i=0;

//        while (j<m)
//        {
//         C[i]=A[j];
//         j++;
//         i++;
//        }
//        i=m;
//        while (k<n)
//        {
//         C[i]=B[k];
//         k++;
//         i++;
//        }
   
    
//     return 0;
// }
// int main()
// { 
//    const int m=5;
//    const int n=4;
//    int A[m]={1,2,3,4,5};
//    int B[n]={10,9,8,7};
//    int C[m+n];
//    int i=0,k=0;
//    while (i<m )
//    {
//         C[i]=A[k];
//         i++;
//         k++;
//    }
//    k=n-1;
//    while (i<m+n)
//    {
//     C[i]=B[k];
//     k--;
//     i++;
//    }
   


   
//     return 0;
// }