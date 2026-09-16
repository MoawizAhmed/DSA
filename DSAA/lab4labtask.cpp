#include <iostream>
using namespace std;
//Task 1
class node
{
  public:
  int data;
  node* next;
  node(int val)
  {
   this->data=val;
   next=nullptr;
  }
};
class singlylinkedlist
{
  private:
  node* head;
  public:
  singlylinkedlist()
  {
    head=nullptr;
  }
   void display()
   {
    node* temp=head;
    if(temp==nullptr)
    {
     cout<<"NULL"<<endl;
     return;
    }
    while (temp!=nullptr)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
   }
   //Task 2
   void insertatstart(int val)
   {
    if(head==nullptr)
    {
     head=new node(val);
     head->next=nullptr;
     return;
    }
    node* temp=head;
    node* newnode=new node(val);
    newnode->next=head;
    head=newnode;
   }
   void insertatend(int val)
   {
    if(head==nullptr)
    {
        head=new node(val);
        head->next=nullptr;
        return;
    }
  node* temp=head;
  node* newnode=new node(val);
  while (temp->next!=nullptr)
  {
    temp=temp->next;
  }
  temp->next=newnode;
  newnode->next=nullptr;
  return;
   }
   void insertafter(int pos,int val)
   {
    int positioncounter=0;
    if (head == nullptr)
    {
        cout << "Out of bounds" << endl;
        return;
    }
      if (pos < 0)
    {
        cout << "Out of bounds" << endl;
        return;
    }
    node* curr=head->next;
    node* prev=head; 
    node* newnode=new node(val);
    if (pos==0)
    {
        newnode->next=head->next;
        head->next=newnode;
        return;
    }
 while ((positioncounter)!=pos)
     {
         if (curr == nullptr)
          {
              cout << "Out of bounds" << endl;
              delete newnode;
              return;
          }

        curr=curr->next;
        prev=prev->next;
        positioncounter++;
     }
     if (prev==nullptr)
     {
        cout<<"Out of bounds"<<endl;
        delete newnode;
        return;
     }
     
     prev->next=newnode;
     newnode->next=curr;
  return;
   }
   //Task 3:
  int search(int key)
{
    node* temp=head;
    int counter=0;

    if (temp==nullptr)
    {
        cout<<"Key not found"<<endl;
        return -1;
    }

    while (temp!=nullptr && temp->data!=key)
    {
        temp=temp->next;
        counter++;
    }

    if (temp==nullptr)
    {
        cout<<"Key not found"<<endl;
        return -1;
    }

    return counter;
}
   int countnodes()
   {
    int counter=0;
    node* temp=head;
    while (temp!=nullptr)
    {
        temp=temp->next;
        counter++;
    }
    return counter;
   }
   int sumofnodes()
   {
    int sum=0;
    node* temp=head;
    while (temp!=nullptr)
    {
         sum+=temp->data;
         temp=temp->next;
    }
    return sum;
   }
   //Task 4:
   void deletefromstart()
   {
    if (head==nullptr)
    {
        cout<<"No nodes found"<<endl;
        return;
    }
    node* temp=head->next;
    delete head;
    head=temp;
    return;
   }
   void deletefromend()
   {
        if (head==nullptr)
    {
        cout<<"No nodes found"<<endl;
        return;
    }
    if (head->next==nullptr)
    {
        delete head;
        head=nullptr;
        return;
    }
    node* temp=head;
    node* prev;
    while (temp->next!=nullptr)
    {
        
        prev=temp;
        temp=temp->next;
    }
    delete temp;
    prev->next=nullptr;
    return;
   }
   void deleteafter(int pos)
{
    if (head == nullptr)
    {
        cout << "Out of bounds" << endl;
        return;
    }

    if (pos < 0)
    {
        cout << "Out of bounds" << endl;
        return;
    }

    node* curr = head->next;
    node* prev = head;
    int positioncounter = 0;

    if (pos == 0)
    {
        if (curr == nullptr)
        {
            cout << "Out of bounds" << endl;
            return;
        }

        head->next = curr->next;
        delete curr;
        return;
    }

    while (positioncounter != pos)
    {
        if (curr == nullptr)
        {
            cout << "Out of bounds" << endl;
            return;
        }

        prev = curr;
        curr = curr->next;
        positioncounter++;
    }

    if (curr == nullptr || curr->next == nullptr)
    {
        cout << "Out of bounds" << endl;
        return;
    }

    node* temp = curr->next;
    curr->next = temp->next;
    delete temp;

    return;
}
};
int main()
{
  singlylinkedlist l;
//   l.display();
//   l.insertatend(10);
//   l.display();
//   l.insertatend(20);
//   l.display();
//   l.insertatstart(5);
//   l.display();
//   l.insertafter(1,15);
//   l.display();
//   int searched=l.search(15);
//   cout<<"searched index: "<<searched<<endl;
//   int counted=l.countnodes();
//   cout<<"Total count of nodes: "<<counted<<endl;
//   int sum=l.sumofnodes();
//   cout<<"Sum of nodes: "<<sum<<endl;
//   l.deletefromstart();
//   l.display();
//   l.deleteafter(0);
//   l.display();
//   l.deletefromend();
//   l.display();
   int choice, val, pos, key;
//Task 5:
    do
    {
        cout << "\n1. Insert at Start" << endl;
        cout << "2. Insert at End" << endl;
        cout << "3. Insert After" << endl;
        cout << "4. Delete from Start" << endl;
        cout << "5. Delete from End" << endl;
        cout << "6. Delete After" << endl;
        cout << "7. Search" << endl;
        cout << "8. Count Nodes" << endl;
        cout << "9. Sum of Nodes" << endl;
        cout << "10. Display" << endl;
        cout << "11. Exit" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            l.insertatstart(val);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> val;
            l.insertatend(val);
            break;

        case 3:
            cout << "Enter position: ";
            cin >> pos;
            cout << "Enter value: ";
            cin >> val;
            l.insertafter(pos, val);
            break;

        case 4:
            l.deletefromstart();
            break;

        case 5:
            l.deletefromend();
            break;

        case 6:
            cout << "Enter position: ";
            cin >> pos;
            l.deleteafter(pos);
            break;

        case 7:
            cout << "Enter key: ";
            cin >> key;
            cout << "Index: " << l.search(key) << endl;
            break;

        case 8:
            cout << "Total nodes: " << l.countnodes() << endl;
            break;

        case 9:
            cout << "Sum: " << l.sumofnodes() << endl;
            break;

        case 10:
            l.display();
            break;

        case 11:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice" << endl;
        }

    } while (choice != 11);

    return 0;
}