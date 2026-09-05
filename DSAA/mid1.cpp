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
class stack
{
 private:
 char* c;
 int capacity;
 int size;
 public:
 stack()
 {
    capacity=1;
    c=new char[capacity];
    size=0;
 }
 void push(char ch)
 {
  if(size==capacity)
  {
    char* temp=new char[capacity*2];
    capacity*=2;
    for (int i = 0; i < size; i++)
    {
        temp[i]=c[i];
    }
      delete[] c;
    c=temp;
    c[size++]=ch;
     return;
    }
    c[size++]=ch;
 }
 void pop()
 {
    for (int i = 0; i < size-1; i++)
    {
        c[i]=c[i+1];
    }
    size--;
 }
 void reverse()
 {
    int i = 0;
    int j = size - 1;

    while(i < j)
    {
        char temp = c[i];
        c[i] = c[j];
        c[j] = temp;

        i++;
        j--;
    }
 }
 void printt()
 {
    for(int i=0;i<size;i++)
    {
        cout<<c[i];
    }
 }
};
int main()
{
    stack s;
    s.push('n');
    s.push('i');
    s.push('g');
    s.push('g');
    s.push('a');
    s.reverse();
    s.printt();
    return 0;
}