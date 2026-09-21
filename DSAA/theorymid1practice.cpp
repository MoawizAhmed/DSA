#include <iostream>
using namespace std;
class node
{
  public:
  node* next;
  int data;
  node(int val)
  {
    next=nullptr;
     this->data=val;
  }
};
class linkedlist
{
    private:
    node* head;
    public:
    linkedlist()
    {
    head=nullptr;
    }
    void insertatbeginning(int val)
    {
    node* newnode=new node(val);
    if(head==nullptr)
    {
    head=newnode;
    head->next=nullptr;
    return;
    }
     newnode->next=head;
     head=newnode;
    return;
    }
    void insertatend(int val)
    {
        node* newnode=new node(val);
          if (head==nullptr)
        {
            insertatbeginning(val);
            return;
        }
        node* temp=head;
        while (temp->next!=nullptr)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=nullptr;
        return;
    }
    void insertatpos(int pos,int val)
    {
        if (pos<0)
        {
            cout<<"invalid position!"<<endl;
            return;
        }
        if (pos==0)
        {
            insertatbeginning(val);
            return;
        }
        node* currminusone=head;
        node* newnode=new node(val);
        int positioncounter=0;
        while ((positioncounter+1)!=pos)
        {
            if (currminusone==nullptr)
            {
                cout<<"position does not exist"<<endl;
                return;
            }
            
            currminusone=currminusone->next;
            positioncounter++;
        }
        node* next=currminusone->next;
        currminusone->next=newnode;
        newnode->next=next;
        return;
    }
    void deletefrombeginning()
    {
        if (head==nullptr)
        {
            return;
        }
        
        node* newhead=head->next;
        delete head;
        head=newhead;
        return;
    }
    void deletefromend()
    {
        node* curr=head;
        node* prev=nullptr;
          if (head == nullptr)
    {
        cout << "List is empty!" << endl;
        return;
    }
    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }

        while (curr->next!=nullptr)
        {
          prev=curr;
          curr=curr->next;
        }
        prev->next=nullptr;
        delete curr;
        return;
    }
    void deletespecificval(int val)
    {
     node* curr=head;
     node* prev=nullptr;
     while (curr!=nullptr && curr->data!=val)
     {       
      prev=curr;
      curr=curr->next;
     }
     prev->next=curr->next;
     delete curr;
     return;
    }
    int traverse(int val)
    {
     node* curr=head;
     int counter=0;
     while (curr!=nullptr && curr->data!=val)
     {  
        curr=curr->next;
        counter++;
     }
     return counter;
    }
  void reverse()
  {
     node* curr=head;
     node* prev=nullptr;
     node* next=nullptr;
     while (curr!=nullptr)
     {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
     }
     head=prev;
  }
void removeDuplicates()
{
    node* current = head;

    while (current != nullptr && current->next != nullptr)
    {
        if (current->data == current->next->data)
        {
            node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
        else
        {
            current = current->next;
        }
    }
} 
bool isPalindrome()
{
    if (head == nullptr || head->next == nullptr)
        return true;

    node* slow = head;
    node* fast = head;

    // Find middle
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse second half
    node* prev = nullptr;
    node* current = slow;

    while (current != nullptr)
    {
        node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    // Compare first half and reversed second half
    node* first = head;
    node* second = prev;

    while (second != nullptr)
    {
        if (first->data != second->data)
            return false;

        first = first->next;
        second = second->next;
    }

    return true;
}
};
int main()
{
    return 0;
}