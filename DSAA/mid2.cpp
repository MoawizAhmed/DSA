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
//  class treeNode
//  {
//  public:
//      int data;
//      treeNode* left;
//      treeNode* right;

//      treeNode(int value)
//      {
//          data = value;
//          left = nullptr;
//          right = nullptr;
//      }
//  };
//  class tree
//  {
//  public:
//      treeNode* root;

//      tree()
//      {
//          root = nullptr;
//      }

//      void inorder(treeNode* temp)
//      {
//          if (temp == nullptr)
//              return;

//          inorder(temp->left);
//          cout << temp->data << " ";
//          inorder(temp->right);
//      }



// bool isbst(treeNode* root)
// {
//     if (root == nullptr)
//         return true;

//     if (root->left != nullptr)
//     {
//         treeNode* temp = root->left;

//         while (temp->right != nullptr)
//             temp = temp->right;

//         if (temp->data >= root->data)
//             return false;
//     }

//     if (root->right != nullptr)
//     {
//         treeNode* temp = root->right;

//         while (temp->left != nullptr)
//             temp = temp->left;

//         if (temp->data <= root->data)
//             return false;
//     }

//     return isbst(root->left) && isbst(root->right);
// }
// void search(int value)
// {
//     treeNode* temp=root;
//     while (temp->data!=value && temp!=nullptr)
//     {
//         if (value<temp->data)
//         {
//             temp=temp->right;
//         }
//         else
//         {
//             temp=temp->left;
//         }
//     }
// }
// void insert(int value)
// {
//     treeNode* temp=root;
//     treeNode* newnode=new treeNode(value);
//     if (temp==nullptr)
//     {
//      root=newnode;
//      return;
//     }
//     treeNode* parent=root;
//     while (temp!=nullptr)
//     {
//       if (value<temp->data)
//       {
//         parent=temp;
//         temp=temp->left;
//       }
//       else if (value>temp->data)
//       {
//         parent=temp;
//         temp=temp->right;
//       }
//     }
//     if (parent->data>value)
//     {
//         parent->left=newnode;
//     }
//     else
//     {
//         parent->right=newnode;
//     }
// }



//         ===== Not recommended.Do the case 3 with recursion ================
// void deletee(int value)
// {
//    treeNode* temp=root;
//    treeNode* parent=root;
//    while (temp!=nullptr && temp->data!=value)
//    {
//     if (value<temp->data)
//     {
//         parent=temp;
//         temp=temp->left;
//     }
//     else
//     {
//         parent=temp;
//         temp=temp->right;
//     }
//    }
//     if (temp == nullptr)
//     return;
//    if (temp==root && temp->left==nullptr && temp->right==nullptr)
//    {
//     delete root;
//     root = nullptr;
//     return;
//    }

//     //case 1
//    if (temp->left==nullptr && temp->right==nullptr)
//    {
//      if(parent->left==temp)
//      {
//         parent->left=nullptr;
//      }
//      else if(parent->right==temp)
//      {
//         parent->right=nullptr;
//      }
//      delete temp;
//      return;
//    }
//    //case 2
//    if (parent->right==temp)
//    {
//     if (temp->left==nullptr)
//     {
//     parent->right=temp->right;
//     delete temp;
//     return;
//     }
//     else if(temp->right==nullptr)
//     {
//     parent->right=temp->left;
//     delete temp;
//     return;
//     }
//    }
//    else if (parent->left==temp)
//    {
//     if (temp->left==nullptr)
//     {
//     parent->left=temp->right;
//     delete temp;
//     return;
//     }
//     else if(temp->right==nullptr)
//     {
//     parent->left=temp->left;
//     delete temp;
//     return;
//     }
//    }
//    //case 3
//    treeNode* succparent=temp;
//    treeNode* succ=temp->right;
//    while (succ->left!=nullptr)
//    {
//     succparent=succ;
//     succ=succ->left;
//    }
//   if (succparent->left == succ)
//     succparent->left = succ->right;
// else
//     succparent->right = succ->right;

// temp->data = succ->data;
// delete succ;
// return;
// }
//  };

// =============== R E C U R S I O N ===================
// bool path(int **arr,int **visited,int n,int x,int y)
// {
//     if (x>=0 && y>=0 && x<n && y<n &&
//         arr[x][y]!=1 && visited[x][y]!=1)
//     {
//         if (x==n-1 && y==n-1)
//         {
//             visited[x][y]=1;
//             return true;
//         }
//        visited[x][y]=1;
//     if (path(arr,visited,n,x,y-1))
//     {
//         return true;
//     }
//     if (path(arr,visited,n,x,y+1))
//     {
//         return true;
//     }
//     if (path(arr,visited,n,x-1,y))
//     {
//         return true;
//     }

//     if (path(arr,visited,n,x+1,y))
//     {
//         return true;
//     }
//     visited[x][y]=0;
//     return false;
//   }
//   return false;
// }
// int main()
// {
//     int n;
//     cout<<"Enter the number of n"<<endl;
//     cin>>n;
//     int **arr=new int*[n];
//     int **visited=new int*[n];
//     for (int i = 0; i < n; i++)
//     {
//         visited[i]=new int[n];
//     }    
//     for (int i = 0; i < n; i++)
//     {
//         arr[i]=new int[n];
//     }
//      for (int i = 0; i < n; i++)
//      {
//         for (int j = 0; j < n; j++)
//         {
//             cin>>arr[i][j];
//         }
//      }
//      for (int i = 0; i < n; i++)
//      {
//         for (int j = 0; j < n; j++)
//         {
//         visited[i][j]=0;
//         }
//      }
//      for (int i = 0; i < n; i++)
//      {
//         for (int j = 0; j < n; j++)
//         {
//             cout<<arr[i][j]<<" ";
//         }
//         cout<<endl;
//      }

// }
// bool issafe(char **rows,int x,int y,int r, int c)
// {
//       if (x == 2 && y == 2)
//         return false;

//     int i=x-1;
//     while (i>=0)
//     {
//         if (rows[i][y]!='-')
//         {
//             return false;
//         }
//         i--;
//     }
//     i=x-1;
//     int j=y+1;
//     while (i<=r && j<=c && i>=0 && j>=0)
//     {
//         if (rows[i][j]!='-')
//         {
//             return false;
//         }
//         i--;
//         j++;
//     }
//     i=x-1;j=y-1;
//     while (i<=r && j<=c && i>=0 && j>=0)
//     {
//         if (rows[i][j]!='-')
//         {
//             return false;
//         }
//         i--;
//         j--;
//     }

//     return true;
// }
// bool arrangement(char **rows,int x,int y,int r, int c,char course)
// {
// if (x==r-1 || y==c-1)
// {
//     return;
// }   



// }
// int main()
// {
//     const int rows=6;
//     const int cols=8;
//     char **room=new char*[rows];
//     for (int i = 0; i < rows; i++)
//     {
//         room[i]=new char[cols];
//     }

//     for (int i = 0; i < rows; i++)
//     {
//     for (int j = 0; j < cols; j++)
//     {
//         room[i][j]='-';
//     }
//     }

//     // for (int i = 0; i < rows; i++)
//     // {
//     // for (int j = 0; j < cols; j++)
//     // {
//     //     cout<<room[i][j]<<" ";
//     // }
//     // cout<<endl;
//     // }  
//     return 0;
// }
// bool validcobination(int n,int s,int arr2[])
// {
//     int sum=0;
//     for (int i = 0; i < n-1; i++)
//     {
//         for (int j = i+1; j < n; j++)
//         {
//             if (arr2[i]==arr2[j])
//             {
//                 cout<<"first false";
//                 return false;
//             }   
//         }   
//     }
//     for (int i = 0; i < n; i++)
//     {
//         sum+=arr2[i];
//     }
//     if (sum!=s)
//     {
//         cout<<"second false";
//         return false;
//     }
//     return true;
// }

// void codes(int arr[], int n, int N, int s,
//            int arr2[], int index, int start, int &count)
// {
//     // Base case: N digits selected
//     if (index == N)
//     {
//         if (validcobination(N, s, arr2))
//         {
//             for (int i = 0; i < N; i++)
//                 cout << arr2[i] << " ";

//             cout << endl;
//             count++;
//         }

//         return;
//     }

//     // Try selecting each available digit
//     for (int i = start; i < n; i++)
//     {
//         arr2[index] = arr[i];

//         codes(arr, n, N, s, arr2, index + 1, i + 1, count);
//     }
// }

// int main()
// {
//     int N=3;
//     int n;
//     cout<<"Enter the number of elements"<<endl;
//     cin>>n;
//     int *arr=new int[n];
//     for (int i = 0; i < n; i++)
//     {
//       cin>>arr[i];
//     }
//     int *arr2=new int[N];

//     return 0;
// }
// bool validcombination(int arr[],int N,int S)
// {
//  int sum=0;
//     for (int i = 0; i < N; i++)
//     {
//     sum+=arr[i];
//     }
//       for (int i = 0; i < N-1; i++)
//      {
//          for (int j = i+1; j < N; j++)
//          {
//              if (arr[i]>arr[j])
//              {
//                  return false;
//              }   
//          }   
//      }
//     if (sum==S)
//     {
//         return true;
//     }
//         return false;
// }
// void codes(int arr[],int index,int n,int N,int S,int temp[])
// {
//     if (index==N)
//     {
//         if (validcombination(temp,N,S))
//         {
//             for (int i = 0; i < N; i++)
//             {
//                 cout<<temp[i]<<" ";
//             }
//                   cout<<endl;
//         }
//         return;
//     }


//     for (int i = 0; i < n; i++)
//     {
//         temp[index]=arr[i];
//         codes(arr,index+1,n,N,S,temp);
//     }
// }


// int main()
// {
//   int n=5;
//   int *arr=new int[n];
//   for (int i = 0; i < n; i++)
//   {
//     arr[i]=i+1;
//   }
//   int temp[3];
//   codes(arr,0,n,3,9,temp);
//     return 0;
// }
// bool validtreasures(int temp[], int k, int T)
// {
//     int sum = 0;
//     for (int i = 0; i < k; i++)
//     {
//         sum += temp[i];
//     }
//     for (int i = 0; i < k - 1; i++)
//     {
//         for (int j = i+1; j < k; j++)
//         {
//             if (temp[i] == temp[j])
//             {
//                 return false;
//             }

//         }

//     }

//     if (sum >= T)
//     {
//         return true;
//     }
//     return false;
// }
// void treasure(int arr[], int n, int index, int K, int T, int temp[], int& count)
// {
//     if (index == K)
//     {
//         return;
//     }

//     if (index == n)
//     {
//         if (validtreasures(temp, K, T))
//         {
//             count++;
//             for (int i = 0; i < K; i++)
//             {
//                 cout << temp[i] << " ";
//             }
//             cout << endl;
//         }
//         return;
//     }
//     for (int i = index; i < n; i++)
//     {
//         temp[index] = arr[i];
//         treasure(arr, n, i + 1, K, T, temp, count);
//     }

// }
// int main()
// {

//     int arr[] = { 2,3,5,7 };
//     int k = 2;
//     int T = 8;
//     int temp[2];
//     int count = 0;
//     treasure(arr, 4, 0, k, T, temp, count);
//     return 0;
// }
// bool validpassword(char temp[], int N)
// {
//     int digitcount = 0;
//     int specialsymbol = 0;
//     for (int i = 0; i < N - 1; i++)
//     {
//         for (int j = i + 1; j < N; j++)
//         {
//             if (temp[i] == temp[j])
//             {
//                 return false;
//             }
//         }
//     }
//     for (int i = 0; i < N - 1; i++)
//     {
//         if (temp[i] >= '0' && temp[i] <= '9' && temp[i + 1] >= '0' && temp[i + 1] <= '9')
//         {
//             return false;
//         }

//     }
//     for (int i = 0; i < N; i++)
//     {
//         if (temp[i] >= '0' && temp[i] <= '9')
//         {
//             digitcount++;
//         }
//     }
//     for (int i = 0; i < N; i++)
//     {
//         if (temp[i] == '!' || temp[i] == '@' || temp[i] == '#' || temp[i] == '$' || temp[i] == '%' || temp[i] == '^' || temp[i] == '&' || temp[i] == '*')
//         {
//             specialsymbol++;
//         }
//     }
//     if (digitcount < 2)
//     {
//         return false;
//     }
//     if (specialsymbol == 0)
//     {
//         return false;
//     }
//     return true;
// }

// void password(char arr[], char temp[], bool visited[],
//               int n, int N, int index)
// {
//     if (index == N)
//     {
//         if (validpassword(temp, N))
//         {
//             for (int i = 0; i < N; i++)
//                 cout << temp[i];

//             cout << endl;
//         }

//         return;
//     }

//     for (int i = 0; i < n; i++)
//     {
//         if (!visited[i])
//         {
//             temp[index] = arr[i];
//             visited[i] = true;

//             password(arr, temp, visited, n, N, index + 1);

//             visited[i] = false;
//         }
//     }
// }

// int main()
// {
//     int n = 5;
//     int N = 4;

//     char arr[] = {'0', '2', 'v', '^', 'm'};

//     char* temp = new char[N];
//     bool* visited = new bool[n];

//     for (int i = 0; i < n; i++)
//         visited[i] = false;

//     password(arr, temp, visited, n, N, 0);

//     delete[] temp;
//     delete[] visited;

//     return 0;
// }

// bool isSafe(int board[9][9], int row, int col, int num)
// {
//     // Check row and column
//     for (int i = 0; i < 9; i++)
//     {
//         if (board[row][i] == num || board[i][col] == num)
//             return false;
//     }

//     // Check 3x3 box
//     int startRow = (row / 3) * 3;
//     int startCol = (col / 3) * 3;

//     for (int i = startRow; i < startRow + 3; i++)
//     {
//         for (int j = startCol; j < startCol + 3; j++)
//         {
//             if (board[i][j] == num)
//                 return false;
//         }
//     }

//     return true;
// }

// bool solveSudoku(int board[9][9])
// {
//     for (int row = 0; row < 9; row++)
//     {
//         for (int col = 0; col < 9; col++)
//         {
//             if (board[row][col] == 0)
//             {
//                 for (int num = 1; num <= 9; num++)
//                 {
//                     if (isSafe(board, row, col, num))
//                     {
//                         board[row][col] = num;

//                         if (solveSudoku(board))
//                             return true;

//                         board[row][col] = 0;
//                     }
//                 }

//                 return false;
//             }
//         }
//     }

//     return true;
// }

// int main()
// {
//     int board[9][9] =
//     {
//         { 5,3,0,0,7,0,0,0,0 },
//         { 6,0,0,1,9,5,0,0,0 },
//         { 0,9,8,0,0,0,0,6,0 },
//         { 8,0,0,0,6,0,0,0,3 },
//         { 4,0,0,8,0,3,0,0,1 },
//         { 7,0,0,0,2,0,0,0,6 },
//         { 0,6,0,0,0,0,2,8,0 },
//         { 0,0,0,4,1,9,0,0,5 },
//         { 0,0,0,0,8,0,0,7,9 }
//     };

//     if (solveSudoku(board))
//     {
//         for (int i = 0; i < 9; i++)
//         {
//             for (int j = 0; j < 9; j++)
//                 cout << board[i][j] << " ";

//             cout << endl;
//         }
//     }
//     else
//     {
//         cout << "No solution exists";
//     }

//     return 0;
// }
// bool valid(char temp[], int N)
// {
//     for (int i = 0; i < N - 1; i++)
//     {
//         for (int j = i + 1; j < N; j++)
//         {
//             if (temp[i] == temp[j])
//             {
//                 return false;
//             }
//         }
//     }
//     for (int i = 0; i < N - 1; i++)
//     {
//         if ((temp[i] == 'a' || temp[i] == 'e' || temp[i] == 'i' || temp[i] == 'o' || temp[i] == 'u') &&
//             (temp[i + 1] == 'a' || temp[i + 1] == 'e' || temp[i + 1] == 'i' || temp[i + 1] == 'o' || temp[i + 1] == 'u'))
//         {
//             return false;
//         }
//     }
//     int vowelcount = 0;
//     for (int i = 0; i < N; i++)
//     {
//         if (temp[i] == 'a' || temp[i] == 'e' || temp[i] == 'i' || temp[i] == 'o' || temp[i] == 'u')
//         {
//             vowelcount++;
//         }
//     }
//     if (vowelcount < 2)
//     {
//         return false;
//     }
//     if (temp[0] == 'a' || temp[0] == 'e' || temp[0] == 'i' || temp[0] == 'o' || temp[0] == 'u' ||
//         temp[N - 1] == 'a' || temp[N - 1] == 'e' || temp[N - 1] == 'i' || temp[N - 1] == 'o' || temp[N - 1] == 'u')
//     {
//         return false;
//     }

//     return true;

// }
// void randomkid(char arr[], char temp[], bool visited[], int n, int N, int index)
// {
//     if (index == N)
//     {
//         if (valid(temp, N))
//         {
//             for (int i = 0; i < N; i++)
//             {
//                 cout << temp[i] << " ";
//             }
//             cout << endl;
//         }
//         return;
//     }

//     for (int i = 0; i < n; i++)
//     {
//         if (!visited[i])
//         {
//             visited[i] = true;
//             temp[index] = arr[i];
//             randomkid(arr, temp, visited, n, N, index + 1);
//             visited[i] = false;
//         }

//     }

// }
// int main()
// {
//     int n = 10;
//     int N = 6;
//     char* arr = new char[n];
//     char* temp = new char[N];
//     bool* visited = new bool[n];
//     for (int i = 0; i < n; i++)
//     {
//         visited[i] = false;
//     }
//     arr[0] = 'a';
//     arr[1] = 'b';
//     arr[2] = 'c';
//     arr[3] = 'd';
//     arr[4] = 'e';
//     arr[5] = 'f';
//     arr[6] = 'g';
//     arr[7] = 'h';
//     arr[8] = 'i';
//     arr[9] = 'j';
//     randomkid(arr, temp, visited, n, N, 0);
//     return 0;
// }
// void hamilton(int graph[][4], bool visited[],
//               int path[], int n, int count)
// {
//     if (count == n)
//     {
//         for (int i = 0; i < n; i++)
//             cout << path[i] << " ";

//         cout << endl;
//         return;
//     }

//     int last = path[count - 1];

//     for (int i = 0; i < n; i++)
//     {
//         if (graph[last][i] == 1 && !visited[i])
//         {
//             visited[i] = true;
//             path[count] = i;

//             hamilton(graph, visited, path, n, count + 1);

//             visited[i] = false;
//         }
//     }
// }

// int main()
// {
//     int graph[4][4] = {
//         {0, 1, 1, 0},
//         {1, 0, 1, 1},
//         {1, 1, 0, 1},
//         {0, 1, 1, 0}
//     };

//     bool visited[4] = {false};
//     int path[4];

//     int start = 0;

//     visited[start] = true;
//     path[0] = start;

//     hamilton(graph, visited, path, 4, 1);

//     return 0;
// }

// #include <iostream>
// using namespace std;

// int minimum = 999999;

// void cheapest(int graph[][4], bool visited[],
//               int n, int current, int count, int cost)
// {
//     if (count == n)
//     {
//         if (cost < minimum)
//             minimum = cost;

//         return;
//     }

//     for (int i = 0; i < n; i++)
//     {
//         if (graph[current][i] != 0 && !visited[i])
//         {
//             visited[i] = true;

//             cheapest(graph, visited, n, i,
//                      count + 1, cost + graph[current][i]);

//             visited[i] = false;
//         }
//     }
// }

// int main()
// {
//     int graph[4][4] = {
//         {0, 10, 15, 20},
//         {10, 0, 35, 25},
//         {15, 35, 0, 30},
//         {20, 25, 30, 0}
//     };

//     bool visited[4] = {false};

//     int start = 0;

//     visited[start] = true;

//     cheapest(graph, visited, 4, start, 1, 0);

//     if (minimum == 999999)
//         cout << "No Hamiltonian Path exists";
//     else
//         cout << "Minimum cost: " << minimum;

//     return 0;
// }
// int getmax(int arr[], int n)
// {
//     int max = arr[0];
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] > max)
//         {
//             max = arr[i];
//         }
//     }
//     return max;
// }
// int places(int arr[], int n)
// {
//     int count = 0;
//     int max = getmax(arr, n);
//     while (max > 0)
//     {
//         max = max / 10;
//         count++;
//     }
//     return count;
// }
// void countsort(int arr[], int n, int place)
// {
//     int* count = new int[10];
//     for (int i = 0; i < 10; i++)
//     {
//         count[i] = 0;
//     }

//     int* output = new int[n];

//     for (int i = 0; i < n; i++)
//     {
//         int digit = (arr[i] / place) % 10;
//         count[digit]++;
//     }
//     for (int i = 1; i < 10; i++)
//     {
//         count[i] = count[i] + count[i - 1];
//     }
//     for (int i = n - 1; i >= 0; i--)
//     {
//         int digit = (arr[i] / place) % 10;
//         output[--count[digit]] = arr[i];
//     }
//     for (int i = 0; i < n; i++)
//     {
//         arr[i] = output[i];
//     }
//     delete[] count;
//     delete[] output;

// }
// void radixsort(int arr[], int n)
// {
//     int placess = places(arr, n);
//     int place = 1;
//     for (int i = 0; i < placess; i++)
//     {
//         countsort(arr, n, place);
//         place *= 10;
//     }
// }

// int main()
// {
//     int arr[] = { 5,8,4,6,3,1,9 };
//     int n = 7;
//     radixsort(arr, n);
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }

//     return 0;
// }
// void merge(int arr[], int l, int m, int r)
// {
//     int n1 = m - l + 1;
//     int n2 = r - m;
//     int* la = new int[n1];
//     int* ra = new int[n2];

//     for (int i = 0; i < n1; i++)
//     {
//         la[i]=arr[i+l];
//     }
//     for (int i = 0; i < n2; i++)
//     {
//         ra[i]=arr[m+i+1];
//     }

//     int i = 0;int j = 0;int k = l;
//     while (i < n1 && j < n2)
//     {
//         if (la[i] < ra[j])
//         {
//             arr[k++]=la[i++];

//         }
//         else
//         {
//             arr[k++]=ra[j++];
//         }
//     }
//     while (i < n1)
//     {
//       arr[k++]=la[i++];
//     }
//     while (j < n2)
//     {
//     arr[k++]=ra[j++];
//     }

//     delete[] la;
//     delete[] ra;
// }
// void mergesort(int arr[], int l, int r)
// {
//     if (l < r)
//     {
//         int m = l + (r - l) / 2;
//         mergesort(arr, l, m);
//         mergesort(arr, m + 1, r);
//         merge(arr, l, m, r);
//     }

// }
// int main()
// {
//    int arr[]={5,4,2,9,1};
//    mergesort(arr,0,5);
//    for (int i = 0; i < 5; i++)
//    {
//     cout<<arr[i]<<" ";
//    }

//     return 0;
// }
//================== T R E E P A R T 2 ===============
class nodetree
{
public:
    int data;
    nodetree* right;
    nodetree* left;
    nodetree(int value)
    {
        this->data = value;
        right = nullptr;
        left = nullptr;
    }
};

class tree
{
public:
    nodetree* root;
    tree()
    {
        root = nullptr;
    }
    void insert(int value)
    {
        nodetree* newnode = new nodetree(value);
        if (root == nullptr)
        {
            root = newnode;
            newnode->left = nullptr;
            newnode->right = nullptr;
            return;
        }
        nodetree* temp = root;
        nodetree* parent = root;
        while (temp != nullptr)
        {
            if (value < temp->data)
            {
                parent = temp;
                temp = temp->left;
            }
            else
            {
                parent = temp;
                temp = temp->right;
            }
        }
        if (value < parent->data)
        {
            parent->left = newnode;
            newnode->left = nullptr;
            newnode->right = nullptr;
            return;
        }
        else
        {
            parent->right = newnode;
            newnode->left = nullptr;
            newnode->right = nullptr;
            return;
        }
    }
    nodetree*& getroot()
    {
        return root;
    }
    void deletee(int value, nodetree*& root)
    {
        if (root == nullptr)
        {
            return;
        }
        nodetree* temp = root;
        nodetree* parent = nullptr;
        while (temp != nullptr && temp->data != value)
        {
            if (value < temp->data)
            {
                parent = temp;
                temp = temp->left;
            }
            else
            {
                parent = temp;
                temp = temp->right;
            }
        }
        if (temp == nullptr)
        {
            cout << "no such node exists" << endl;
            return;
        }
        //case 1 and 2:
        if (temp->left == nullptr || temp->right == nullptr)
        {
            if (parent->left == temp)
            {
                if (temp->left == nullptr)
                {
                    parent->left = temp->right;
                    delete temp;
                    return;
                }
                else if (temp->right == nullptr)
                {
                    parent->left = temp->left;
                    delete temp;
                    return;
                }
                else
                {
                    delete temp;
                    parent->left = nullptr;
                    return;
                }
            }
            else if (parent->right == temp)
            {
                if (temp->left == nullptr)
                {
                    parent->right = temp->right;
                    delete temp;
                    return;
                }
                else if (temp->right == nullptr)
                {
                    parent->right = temp->left;
                    delete temp;
                    return;
                }
                else
                {
                    delete temp;
                    parent->right = nullptr;
                    return;
                }
            }

        }
        else
        {
            nodetree* inordersucc = temp->right;
            while (inordersucc->left != nullptr)
            {
                inordersucc = inordersucc->left;
            }
            temp->data = inordersucc->data;
            deletee(inordersucc->data, temp->right);

        }
    }
};
void inorder(nodetree* root)
{
    if (root == nullptr)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main()
{
    tree t;
    t.insert(50);
    t.insert(30);
    t.insert(70);
    t.insert(20);
    t.insert(40);
    t.insert(60);
    t.insert(80);
    inorder(t.getroot());
    t.deletee(50, t.getroot());
    cout<<endl;
    inorder(t.getroot());
    return 0;
}