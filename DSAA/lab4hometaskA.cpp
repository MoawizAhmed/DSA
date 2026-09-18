// part A
#include <iostream>
using namespace std;
class node
{
 public:
 node* next;
 node* prev;
 int data;
 node(int data)
 {
   this->next=nullptr;
   this->prev=nullptr;
   this->data=data;
 }
};
class doublylinkedlist
{
 private:
  node* head;
  node* tail;
 public:
  doublylinkedlist(){head=nullptr;tail=nullptr;}
  void displayforward()
  {
    node* temp=head;
  while (temp!=nullptr)
  {
    cout<<temp->data;
    temp=temp->next;
  }
  cout<<endl;
  }
  node* gettail()
{
    if(head==nullptr)
        return nullptr;
    node* temp=head;
    while (temp->next!=nullptr)
    {
        temp=temp->next;
    }
    return temp;
}
void displaybackword()
{
    tail=gettail();
    node* temp=tail;
    while (temp!=nullptr)
    {
        cout<<temp->data;
        temp=temp->prev;
    }
    cout<<endl;
}
void insertatstart(int val)
{
   node* newnode=new node(val);
   if(head==nullptr)
   {
    head=newnode;
    head->next=nullptr;
    head->prev=nullptr;
    return;
   }
   newnode->prev=nullptr;
   newnode->next=head;
   head->prev=newnode;
   head=newnode;
}
void insertatend(int val)
{
  node* newnode=new node(val);
  node* temp=head;
  if(head==nullptr)
  {
    head=newnode;
    head->prev=nullptr;
    head->next=nullptr;
    return;
  }
  while (temp->next!=nullptr)
  {
    temp=temp->next;
  }
  temp->next=newnode;
  newnode->prev=temp;
  newnode->next=nullptr;
  return;
}
void insertatposition(int pos,int val)
{
   if(pos<0)
   {
    cout<<"invalid position"<<endl;
    return;
   }
   node* newnode=new node(val);
   node* temp=head;
   int positioncounter=0;
   do
   {
    temp=temp->next;
    positioncounter++;
   }
   while (positioncounter!=pos);
   if(pos==0)
   {
    head=newnode;
    head->next=nullptr;
    head->prev=nullptr;
    return;
   }
   node* prev=temp->prev;
   prev->next=newnode;
   temp->prev=newnode;
   newnode->next=temp;
   newnode->prev=prev;
   return;
}
void deletefromstart()
{
 node* temp=head;
 node* next=temp->next;
 next->prev=nullptr;
 delete temp;
 head=next;
 return;
}
void deletefromend()
{
  node* tail=gettail();
  node* prev=tail->prev;
  prev->next=nullptr;
  delete tail;
  tail=prev;
  return;
}
void deletevalue(int val)
{
    node* temp=head;

    while(temp!=nullptr && temp->data!=val)
    {
        temp=temp->next;
    }

    if(temp==nullptr)
    {
        cout<<"Value not found"<<endl;
        return;
    }

    if(temp->prev!=nullptr)
    {
        temp->prev->next=temp->next;
    }
    else
    {
        head=temp->next;
    }

    if(temp->next!=nullptr)
    {
        temp->next->prev=temp->prev;
    }

    delete temp;
}
void reverse()
{
    tail=gettail();

    node* current=head;

    while(current!=nullptr)
    {
        node* temp=current->next;

        current->next=current->prev;
        current->prev=temp;

        current=temp;
    }

    node* temp=head;
    head=tail;
    tail=temp;
}
};
int main()
{
   doublylinkedlist d;
   d.insertatend(10);
   d.insertatend(30);
   d.insertatposition(1,20);
   d.displayforward();
   d.displaybackword();
   d.deletefromend();
   d.displayforward();
   d.deletefromstart();
   d.displayforward();
    return 0;
}