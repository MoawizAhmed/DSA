 #include <iostream>
 using namespace std;
// class customer
// {
//  private:
//  string name;
//  int hanger;
//  int date;
//  int month;
//  public:
//  customer(string name,int date,int month)
//  {
//     this->name=name;
//     this->date=date;
//     this->month=month;
//  }
//  string getname(){return name; }
//  int gethanger(){return hanger;}
//  int getdate(){return date; }
//  int getmonth(){return month; }
//  void sethanger(int h){hanger=h;}
// };
// void display(int n,customer arr[])
// {
//   for (int i = 0; i < n; i++)
//   {
//     cout<<arr[i].getname()<<" ";
//     cout<<arr[i].getdate()<<" ";
//     cout<<arr[i].getmonth()<<" ";
//     cout<<"Hanger "<<arr[i].gethanger()<<" ";
//     cout<<endl;
//   }
  
// }
// customer& sort(int n,customer arr[])
// {
//   for (int i = 1; i < n; i++)
//   {
//     customer key=arr[i];
//     int j=i-1;
//     while (j>=0 && arr[j].getdate()>key.getdate() ||
//      arr[j].getdate()==key.getdate() && arr[j].getmonth()>key.getmonth() ||
//       arr[j].getdate()==key.getdate() && arr[j].getmonth()==key.getmonth() &&  arr[j].getname().length()>key.getname().length())
//     {
//         arr[j+1]=arr[j];
//         j--;
//     }
//     arr[j+1]=key;
//   }
//   return *arr;
// }
// int search(int n,customer arr[],string key)
// {
//     int right=n-1;
//     int low=0;
//     while (low<=right)
//     {
//      int mid=low+(right-low)/2;
//      if (arr[mid].getname()==key)
//      {
//         return mid;
//      }
//      else if(arr[mid].getname()<key)
//      {
//       low=mid+1;
//      }
//      else
//      {
//       right=mid-1;
//      }
//     }
    
// }
// void assignhanger(int n,customer arr[])
// {
//     for (int i = 0; i < n; i++)
//     {
//         arr[i].sethanger(i+1);
//     }
// }
// int main()
// {
//     const int n=5;
//     customer c1("Mubeen",9,9);
//     customer c2("Ali",1,9);
//     customer c3("Shaheer",15,9);
//     customer c4("Sadiq",8,9);
//     customer c5("Romaan",20,9);
//    customer c[n]={c1,c2,c3,c4,c5};
//     customer arr=sort(n,c);
//     *c=arr;
//     assignhanger(n,c);
//     display(n,c);
//     int ans=search(n,c,"Mubeen");
//     cout<<ans<<endl;
//     return 0;
// }
// #include <iostream>
// using namespace std;
// class node
// {
// public:
// int data;
// node* next;
// node(int val)
// {
//  data=val;
// }
// };
// class linkedlist
// {
//   private:
//   node* head;
//   public:
//   linkedlist()
//   {
//     head=nullptr;
//   }
//   void insert(int val)
//   {
//     node* newnode=new node(val);
//     node* curr=head;
//    if (head==nullptr)
//    {
//     head=newnode;
//     head->next=nullptr;
//     return;
//    }
//    while (curr->next!=nullptr)
//    {
//      curr=curr->next;
//    }
//    curr->next=newnode;
//    newnode->next=nullptr;
//   }
//   void display()
//   {
//     node* curr=head;
//     while (curr!=nullptr)
//     {
//         cout<<curr->data<<endl;
//         curr=curr->next;
//     }
//   }
// };
// int main()
// {
//    linkedlist l;
//    l.insert(1);
//    l.insert(2);
//    l.insert(3);
//    l.display();
//     return 0;
// }

//  class node
//  {
//  public:
//  int constant;
//  char variable;
//  int power;
//  char operatorr;
//  node* next;

//  node(int con,char var,int pow,char opera)
//  {
//   constant=con;
//   variable=var;
//   power=pow;
//  operatorr=opera;
//  }
//  };
// class linkedlist
// {
//     public:
//      node* head;
//     linkedlist()
//     {
//         head=nullptr;
//     }
// void insert(int con,char var,int pow,char operatorr)
//    {
//      node* newnode=new node(con,var,pow,operatorr);
//      node* curr=head;
//     if (head==nullptr)
//     {
//      head=newnode;
//      head->next=nullptr;
//      return;
//     }
//     while (curr->next!=nullptr)
//     {
//       curr=curr->next;
//     }
//     curr->next=newnode;
//     newnode->next=nullptr;
//    }
//    void display()
//    {
//      node* curr=head;
//      while (curr!=nullptr)
//      {
//         if (curr==head)
//         {
//             if (curr->operatorr=='+')
//             {
//          cout<<curr->constant;cout<<curr->variable;cout<<"^"<<curr->power<<" ";
//          curr=curr->next;   
//             }  
//             else
//             {
//               cout<<curr->operatorr<<" "<<curr->constant;cout<<curr->variable;cout<<"^"<<curr->power<<" ";
//          curr=curr->next;  
//             }
//         }
//         else
//         {
//          cout<<curr->operatorr<<" "<<curr->constant;cout<<curr->variable;cout<<"^"<<curr->power<<" ";
//          curr=curr->next;
//         }
//      }
//      cout<<"= 0";cout<<endl;
//    }
// };
// node* sorting(node* head)
// {
//      if (head == nullptr)
//      {
//         return head;
//      }
//     node* curr;
//     node* temp;

//     for (curr = head; curr->next != nullptr; curr = curr->next)
//     {
//         for (temp = curr->next; temp != nullptr; temp = temp->next)
//         {
//             if (curr->power < temp->power)
//             {
//                 int constant = curr->constant;
//                 char variable = curr->variable;
//                 int power = curr->power;
//                 char operatorr = curr->operatorr;
//                 curr->power = temp->power;
//                 curr->constant = temp->constant;
//                 curr->variable = temp->variable;
//                 curr->operatorr = temp->operatorr;
//                 temp->power = power;
//                 temp->variable = variable;
//                 temp->constant = constant;
//                 temp->operatorr = operatorr;
//             }
//         }
//     }
//     return head;
// } 
// node* add(node* head1,node* head2)
// {
//   linkedlist newone;
//   node* curr=head1;
//   while (curr!=nullptr)
//   {
//     newone.insert(curr->constant,curr->variable,curr->power,curr->operatorr);
//     curr=curr->next;
//   }
//   curr=head2;
//   while (curr!=nullptr)
//   {
//     newone.insert(curr->constant,curr->variable,curr->power,curr->operatorr);
//     curr=curr->next;
//   }
//   node* headd=sorting(newone.head);
//   return headd;
// }
// void adding(node* head1,node* head2)
// {
//     node* curr1=head1;
//     node* curr2=head2;
//     linkedlist newone;
//     node* newhead=newone.head;
//     while (curr1!=nullptr)
//     {
//         curr2=head2;
//       while (curr2 != nullptr && curr1->power!=curr2->power)
//       {
//         curr2=curr2->next;     
//       }
//      if(curr2==nullptr)
//       {
//         newone.insert(curr1->constant,curr1->variable,curr1->power,curr1->operatorr);
//         curr1 = curr1->next;
//     continue;
//       }  
//       int newconstant;
//       char newoperator;
//       if(curr2->operatorr=='+' && curr1->operatorr=='+' ||
//          curr2->operatorr=='-' && curr1->operatorr=='-')
//       {
//       newconstant=curr1->constant+curr2->constant;
//       if (curr2->operatorr=='+' && curr1->operatorr=='+')
//       {
//          newoperator='+';
//       }
//       else
//       {
//          newoperator='-';
//       }
//       }
//       else if(curr2->operatorr=='+' && curr1->operatorr=='-' ||
//               curr2->operatorr=='-' && curr1->operatorr=='+')
//       {
//        if (curr1->constant>curr2->constant)
//        {
//         newconstant=curr1->constant-curr2->constant;
//         newoperator=curr1->operatorr;
//        }
//        else if (curr2->constant>curr1->constant)
//        {
//         newconstant=curr2->constant-curr1->constant;
//         newoperator=curr2->operatorr;
//        }
//        else
//        {
//     newconstant=0;
//     newoperator='+';     
//        }
//       }
   
//       else if (newconstant==0)
//       {

//       }
//       else if (curr2!=nullptr && newconstant!=0)
//       {
//         newone.insert(newconstant,curr1->variable,curr1->power,newoperator);
//       }
      
//       curr1=curr1->next;
//     }
//     curr2=head2;
//        while(curr2!=nullptr)
//     {
//         // Start searching from the beginning of head1
//         curr1=head1;

//         // This tells us whether the current head2
//         // element already has the same power in head1
//         bool found=false;

//         while(curr1!=nullptr)
//         {
//             if(curr2->power==curr1->power)
//             {
//                 found=true;
//                 break;
//             }

//             curr1=curr1->next;
//         }

//         // If the power was NOT found in head1,
//         // this is a remaining element of head2.
//         if(found==false)
//         {
//             newone.insert(curr2->constant,
//                           curr2->variable,
//                           curr2->power,
//                           curr2->operatorr);
//         }

//         // Move to the next element of head2
//         curr2=curr2->next;
//     }
//     newone.display();
// }
// int main()
// {
//     linkedlist l1;
//     l1.insert(4,'x',2,'+');
//     l1.insert(2,'x',6,'+');
//     l1.insert(1,'x',3,'-');
//     l1.insert(4,'x',2,'+');
//     l1.insert(3,'1',1,'+');
//     linkedlist l2;
//     l2.insert(2,'x',8,'+');
//     l2.insert(3,'x',3,'+');
//     l2.insert(2,'1',1,'-');
//     linkedlist l3;
//     l3.head=add(l1.head,l2.head);
//     l3.display();
//     adding(l1.head,l2.head);
// }

  class node
  {
  public:
  node* next;
  int data;
  node(int val)
  {
    data=val;
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
  node* gethead()
  {
    return head;
  }
  void insert(int val)
  {
    node* newnode=new node(val);
    node* curr=head;
    if (head==nullptr)
    {
     head=newnode;
     head->next=nullptr;
     return;
    }
    while (curr->next!=nullptr)
    {
        curr=curr->next;
    }
    curr->next=newnode;
    newnode->next=nullptr;
  }
  void reverse()
  {
   node* prev=nullptr;
   node* curr=head;
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
  void middle()
  {
    node* fast=head;
    node* slow=head;
    while (fast!=nullptr && fast->next!=nullptr)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    cout<<slow->data<<endl;
  }
  //floyd's cycle
  bool cycle()
  {
    node* fast=head;
    node* slow=head;
    while (fast!=nullptr && fast->next!=nullptr)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    if (fast==slow)
    {
     return true;
    }
    else
    {
        return false;
    }
    
  }
  //floyd's cycle 2
  void cycle2()
  {
      node* fast=head;
    node* slow=head;
    while (fast!=nullptr && fast->next!=nullptr)
    {
        fast=fast->next->next;
        slow=slow->next;
    if (fast==slow)
    {
     break;
    }
    }
    if (fast==nullptr || fast->next==nullptr)
    {
        cout<<"no cycle"<<endl;
    }
    slow=head;
    while (slow!=fast)
    {
        slow=slow->next;
        fast=fast->next;
    }
    
  }

  void display()
  {
    node* curr=head;
    while (curr!=nullptr)
    {
        cout<<curr->data<<endl;
        curr=curr->next;
    }
  }
  void deleteanode(int val)
  {
   node* curr=head;
   if (head == nullptr) return;
   if (head->data==val)
   {
     node* temp=head->next;
     delete head;
     head=temp;
     return;
   }
   
   while (curr->next != nullptr && curr->next->data!=val)
   {
    curr=curr->next;
   }
   
   node* valtemp=curr->next;
   node* next=curr->next->next;
   curr->next=next;
   delete valtemp;
  }
  bool ispallendrome()
  {
    int counter=0;
    node* slow=head;
    node* fast=head;
    while (fast!=nullptr && fast->next!=nullptr)
    {
        fast=fast->next->next;
        slow=slow->next;
        counter++;
    }
    node* mid=slow;
    slow=head;

   node* prev=nullptr;
   node* curr=mid;
   node* next=nullptr;
   while (curr!=nullptr)
   {
     next=curr->next;
     curr->next=prev;
     prev=curr;
     curr=next;
   }
   mid=prev;
   for (int i = 0; i < counter; i++)
   {
     if (mid->data!=slow->data)
     {
        return false;
     }
      mid = mid->next;
    slow = slow->next;
   }
   return true;
  }
  void sort()
  {
    node* curr;
    node* temp;
    for (curr=head ; curr->next != nullptr; curr=curr->next)
    {
        for (temp = curr->next; temp->next != nullptr ; temp=temp->next)
        {
            if (temp->data > temp->next->data)
            {
              int hello=temp->data;
              temp->data=temp->next->data;
              temp->next->data=hello;
            }
        }
    }
  }
  void reverse2(int n1,int n2)
  {
    int counter1=0;
    int counter2=0;
    node* start=head;
    node* end=head;
    while (counter1!=n1)
    {
        start=start->next;
        counter1++;
    }
    while (counter2!=n2)
    {
        end=end->next;
        counter2++;
    }
    node* prev=nullptr;
    node* curr=start;
    node* next;
    while (curr!=end)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    start=prev;
  }
};
node* intersection(node* head1,node* head2)
{
  node* curr1=head1;
  node* curr2=head2;
  while (curr1!=curr2)
  {

    curr1=curr1->next;
    if (curr1==nullptr)
    {
        curr1=head2;
    }
    
    curr2=curr2->next;
    if (curr2==nullptr)
    {
        curr2=head1;
    }
  }
  return curr1;
}
node* merge(node* head1, node* head2)
{
    node* newhead = nullptr;
    node* currnew = nullptr;
    node* curr1 = head1;
    node* curr2 = head2;

   
    while (curr1 != nullptr && curr2 != nullptr)
    {
        if (curr1->data < curr2->data)
        {
         
            node* temp = new node(curr1->data);

            if (newhead == nullptr)
            {
                newhead = temp;
                currnew = temp;
            }
            else
            {
                currnew->next = temp;

            
                currnew = currnew->next;
            }

            curr1 = curr1->next;
        }
        else
        {
           
            node* temp = new node(curr2->data);

            if (newhead == nullptr)
            {
                newhead = temp;
                currnew = temp;
            }
            else
            {
                currnew->next = temp;

               
                currnew = currnew->next;
            }

            curr2 = curr2->next;
        }
    }

    while (curr1 != nullptr)
    {
        node* temp = new node(curr1->data);
        currnew->next = temp;
        currnew = currnew->next;
        curr1 = curr1->next;
    }

    while (curr2 != nullptr)
    {
        node* temp = new node(curr2->data);
        currnew->next = temp;
        currnew = currnew->next;
        curr2 = curr2->next;
    }
    return newhead;
}
  int main()
  {
   linkedlist l;
   l.insert(1);
   l.insert(2);
   l.insert(3);
   l.insert(2);
   l.insert(1);
   l.reverse();
   l.display();
   l.middle();
   cout<<l.ispallendrome()<<endl;
    return 0;
  }