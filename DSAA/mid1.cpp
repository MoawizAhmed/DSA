#include <iostream>
using namespace std;
class song
{   public:
    string name;
    song* next;
    song* prev;
   song(string name)
   {
    this->name=name;
    this->next=nullptr;
    this->prev=nullptr;
   }
};
class playlist
{
 private:
  song* head;
  song* current;
 public:
  playlist()
  {
    this->head=nullptr;
    current=head;
  }
   void addsong(string name)
   {
    song* soong=new song(name);
    if(head==nullptr)
    {
     head=soong;
     current=head;
     return;
    }
   song* temp=head;
   while(temp->next!=nullptr)
   {
    temp=temp->next;
   }
   soong->prev=temp;
   temp->next=soong;
   }
   void removesong(string name)
   {
    song* temp=head;
   while (temp != nullptr && temp->name!=name)
   {
     temp=temp->next;
   }
   if(temp==nullptr){ cout<<"Song Not Found"<<endl;return;}
   if(temp->prev==nullptr)
   {
   song* tempp=temp->next;
   head=tempp;
   delete temp;
   return;
   }
   if(temp->next==nullptr)
   {song* tempp=temp->prev;
    delete temp;
    tempp->next=nullptr;
    return;
   }
   song* temp2=temp->prev;
   song* temp3=temp->next;
   temp3->prev=temp2;
   temp2->next=temp3;
   delete temp;
   }
   void nextsong()
   {
    if(current->next==nullptr)
    {
        cout<<"Playlist ended"<<endl;
        return;
    }
    current=current->next;
   }
   void specificsong(string name)
   {
    song* temp=head;
    while (temp->name!=name)
    {
        temp=temp->next;
    }
    if(temp->next==nullptr)
    {
        cout<<"song not found"<<endl;
        return;
    }
    current=temp;
   }
   void printcurrent()
   {
    cout<<current->name<<endl;
   }
};
int main()
{
    playlist p;
    p.addsong("Let it happen");
    p.addsong("The less I know the better");
    p.addsong("Borderline");
    p.printcurrent();
    p.nextsong();
    p.printcurrent();
    p.nextsong();
    p.printcurrent();
    p.nextsong();
    return 0;
}