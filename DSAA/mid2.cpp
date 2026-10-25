#include <iostream>
using namespace std;
//=============== A L G O R I T H M S =============
// //radix sort
//  void countsort(int arr[],int n,int place)
//  {
//   int *arr2=new int[n];
//   for (int i = 0; i < n; i++)
//   {
//      arr2[i]=0;
//   }
//   int count[10]={0,0,0,0,0,0,0,0,0,0};
//   for (int i = 0; i < n; i++)
//   {   int digit=(arr[i]/place)%10;
//      count[digit]++;
//   }
//   for (int i = 1; i < 10 ; i++)
//   {
//      count[i]=count[i]+count[i-1];
//   }
//   for (int i = n-1; i >= 0; i--)
//   {
//      int digit=(arr[i]/place)%10;
//      arr2[--count[digit]]=arr[i];
//   }
//   for (int i = 0; i < n; i++)
//   {
//      arr[i]=arr2[i];
//   }
//   delete[] arr2;
//  }
// int getmax(int arr[],int n)
// {
//     int max=0;
//  for (int i = 0; i < n; i++)
//  {
//     if (arr[i]>max)
//     {
//         max=arr[i];
//     }
//  }
//  return max;
// }

// void radixsortcounting(int arr[],int n)
// {
//   int max=getmax(arr,n);
//   int pos=0;
//   while(max>0)
//   {
//    max=max/10;
//    pos++;
//   }
//  int place = 1;

//     for (int i = 1; i <= pos; i++)
//     {
//         countsort(arr, n, place);
//         place *= 10;
//     }
// }

// void radixsortbucket(int arr[],int n)
// {
//   int max=getmax(arr,n);
//   int pos=0;
//  while (max>0)
//  {
//     max=max/10;
//     pos++;
//  }
//  int place=1;
//  for (int i = 1; i <= pos; i++)
//  {
//     int bucket[10][100];
//     int count[10]={0,0,0,0,0,0,0,0,0,0};
//     int *output=new int[n];
//     for (int i = 0; i < n; i++)
//     {
//         int digit=(arr[i]/place)%10;
//         bucket[digit][count[digit]]=arr[i];
//         count[digit]++;
//     }
//     int index=0;
//     for (int i = 0; i < 10; i++)
//     {
//     for (int j = 0; j < count[i]; j++)
//     {
//         output[index]=bucket[i][j];
//         index++;
//     }
//     }
//     for (int i = 0; i < n; i++)
//     {
//         arr[i]=output[i];
//     }
//     delete[] output;
//     place *= 10;
//  }
// }


// //merge sort
// void merge(int arr[],int l,int m,int r)
// {
//   int n1=m-l+1;
//   int n2=r-m;
//   int *la=new int[n1];
//   int *ra=new int[n2];

// for (int i = 0; i < n1; i++)
// {
//         la[i] = arr[l+i];
// } 
// for (int i = 0; i < n2; i++)
// {
//         ra[i] = arr[m+i+1];
// } 
// int i=0,j=0;int k=l;
// while (i<n1 && j<n2)
// {
//     if (la[i]<ra[j])
//     {
//      arr[k++]=la[i++];   
//     }
//     else
//     {
//         arr[k++]=ra[j++];
//     }
// }
// while (i<n1)
// {
//     arr[k++]=la[i++]; 
// }
// while (j<n2)
// {
//     arr[k++]=la[j++]; 
// }
// delete[] la;
// delete[] ra;
// }
// void mergesort(int arr[],int l,int r)
// {
//   if (l<r)
//   {
//     int mid=l+(r-l)/2;
//     mergesort(arr,l,mid);
//     mergesort(arr,mid+1,r);
//     merge(arr,l,mid,r);
//   }
  
// }
// //quick sort

// void quicksort(int arr[],int l,int u)
// {
//   if (l<u)
//   {
//    int start=l;
//    int end=u;
//    int pivot=arr[l];
//    while (start<end)
//    {
//      while (arr[start]<=pivot)
//      {
//         start++;
//      }
//      while (arr[end]>pivot)
//      {
//         end--;
//      }
//      if (start<end)
//      {
//         int temp=arr[start];
//         arr[start]=arr[end];
//         arr[end]=temp;
//      }
//    }
//    int temp=arr[l];
//    arr[l]=arr[end];
//    arr[end]=temp;
//    quicksort(arr,l,end-1);
//    quicksort(arr,end+1,u);
//   }
  
// }

// int partition(int arr[],int l,int u)
// {
// int pivot=arr[l];
// int start=l;
// int end=u;
// while (start<end)
// {
//     while (arr[start]<=pivot)
//     {
//         start++;
//     }
//     while (arr[end]>pivot)
//     {
//         end--;
//     }
//     if (start<end)
//     {
//         int temp=arr[start];
//         arr[start]=arr[end];
//         arr[end]=temp;
//     }
// }
// int temp=arr[l];
// arr[l]=arr[end];
// arr[end]=temp;
// return end;
// }
// void quicksort(int arr[],int l, int u)
// {
//    if (l<u)
//    {
//     int loc=partition(arr,l,u);
//      quicksort(arr,l,loc-1);
//      quicksort(arr,loc+1,u);
//    }
   
// }
// int main()
// {
//     int arr[]={3132,434,411,132,1411,1123,116,5,82,43,1111,121};
//     quicksort(arr,0,12);
//      for (int i = 0; i < 12; i++)
//      {
//         cout<<arr[i]<<" ";
//      }
//      cout<<"median"<<" "<<arr[(12-1)/2];
//   return 0;
// }


//============== T R E E S ================
// class node
// {
//  public:
//  int data;
//  node* left;
//  node* right;
//  node(int data)
//  {
//     this->data=data;
//     left=nullptr;
//     right=nullptr;
//  }
// };
// class tree
// {
//     private:
//     node* root;
//     public:
//     tree(int value)
//     {
//         root->data=value;
//         root->left=nullptr;
//         root->right=nullptr;
//     }
//     tree(){}
//  void insertion(int value)
//  {
//    node* newnode=new node(value);
//    node* parent=root;
//    node* temp=root;
//    if (root==nullptr)
//    {
//     root=newnode;
//     return;
//    }
//    while (temp!=nullptr)
//    {
//    if(temp->data>value)
//    {
//     parent=temp;
//     temp=temp->left;
//    }
//    else
//    {
//     parent=temp;
//     temp=temp->right;
//    }
//    }
//    if (value<parent->data)
//    {
//     parent->left=newnode;
//    }else
//    {
//     parent->right=newnode;
//    }
//  }
//   void preorder(node* root)
//   {
//    cout<<root->data<<" ";
//    preorder(root->left);
//    preorder(root->right);
//   }  
//   node* preorderret(node* root,int value)
//   {
//    if(root->data==value)
//    {
//     return root;
//    }
//    preorder(root->left);
//    preorder(root->right);
//   }  
//   void inorder(node* root)
//   {
//   inorder(root->left);
//   cout<<root->data<<" ";
//   inorder(root->right);
//   }
//   void postorder(node* root)
//   {
//     postorder(root->left);
//     postorder(root->right);
//     cout<<root->data<<" ";
//   }
//   node* findLargest(node* root)
// {
//     while (root->right != NULL)
//         root = root->right;

//     return root;
// }
//  bool deleteBST(node*& root, int key)
// {
//     if (root == NULL)
//         return false;

//     if (key < root->data)
//         return deleteBST(root->left, key);

//     else if (key > root->data)
//         return deleteBST(root->right, key);

//     else
//     {
//         // Case 1 and Case 2:
//         // No left child
//         if (root->left == NULL)
//         {
//             node* temp = root;
//             root = root->right;
//             delete temp;
//             return true;
//         }

//         // Case 2:
//         // No right child
//         else if (root->right == NULL)
//         {
//             node* temp = root;
//             root = root->left;
//             delete temp;
//             return true;
//         }

//         // Case 3:
//         // Both children exist
//         else
//         {
//             node* predecessor = findLargest(root->left);

//             root->data = predecessor->data;

//             return deleteBST(root->left, predecessor->data);
//         }
//     }
// }};

// #include <iostream>
// using namespace std;

// class node
// {
// public:
//     int data;
//     node* next;

//     node(int value)
//     {
//         data = value;
//         next = nullptr;
//     }
// };

// class treeNode
// {
// public:
//     int data;
//     treeNode* left;
//     treeNode* right;

//     treeNode(int value)
//     {
//         data = value;
//         left = nullptr;
//         right = nullptr;
//     }
// };

// class linkedlist
// {
// public:
//     node* head;

//     linkedlist()
//     {
//         head = nullptr;
//     }

//     void insert(int value)
//     {
//         node* n = new node(value);

//         if (head == nullptr)
//         {
//             head = n;
//             return;
//         }

//         node* temp = head;

//         while (temp->next != nullptr)
//             temp = temp->next;

//         temp->next = n;
//     }
// };

// class tree
// {
// public:
//     treeNode* root;

//     tree()
//     {
//         root = nullptr;
//     }

//     treeNode* convert(node* start, node* end)
//     {
//         if (start == end)
//             return nullptr;

//         node* slow = start;
//         node* fast = start;

//         while (fast != end && fast->next != end)
//         {
//             slow = slow->next;
//             fast = fast->next->next;
//         }

//         treeNode* newnode = new treeNode(slow->data);

//         newnode->left = convert(start, slow);
//         newnode->right = convert(slow->next, end);

//         return newnode;
//     }

//     void create(node* head)
//     {
//         root = convert(head, nullptr);
//     }

//     void inorder(treeNode* temp)
//     {
//         if (temp == nullptr)
//             return;

//         inorder(temp->left);
//         cout << temp->data << " ";
//         inorder(temp->right);
//     }
// };

// int main()
// {
//     linkedlist l;

//     l.insert(10);
//     l.insert(20);
//     l.insert(30);
//     l.insert(40);
//     l.insert(50);
//     l.insert(60);
//     l.insert(70);

//     tree t;
//     t.create(l.head);

//     cout << "Inorder Traversal: ";
//     t.inorder(t.root);

//     return 0;
// }
 class treeNode
 {
 public:
     int data;
     treeNode* left;
     treeNode* right;

     treeNode(int value)
     {
         data = value;
         left = nullptr;
         right = nullptr;
     }
 };
 class tree
 {
 public:
     treeNode* root;

     tree()
     {
         root = nullptr;
     }

     void inorder(treeNode* temp)
     {
         if (temp == nullptr)
             return;

         inorder(temp->left);
         cout << temp->data << " ";
         inorder(temp->right);
     }



bool isbst(treeNode* root)
{
    if (root == nullptr)
        return true;

    if (root->left != nullptr)
    {
        treeNode* temp = root->left;

        while (temp->right != nullptr)
            temp = temp->right;

        if (temp->data >= root->data)
            return false;
    }

    if (root->right != nullptr)
    {
        treeNode* temp = root->right;

        while (temp->left != nullptr)
            temp = temp->left;

        if (temp->data <= root->data)
            return false;
    }

    return isbst(root->left) && isbst(root->right);
}

 };
