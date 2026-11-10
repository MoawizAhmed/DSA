
#include <iostream>
#include <climits>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;

    node(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
};

bool isBST(node* root,long long minVal,long long maxVal){
    if(root==nullptr)
        return true;

    if(root->data<=minVal || root->data>=maxVal)
        return false;

    return isBST(root->left,minVal,root->data) &&
           isBST(root->right,root->data,maxVal);
}

node* inorderSuccessor(node* root,int key){
    node* ans=nullptr;

    while(root!=nullptr){
        if(root->data>key){
            ans=root;
            root=root->left;
        }
        else{
            root=root->right;
        }
    }

    return ans;
}

bool kthSmallest(node* root,int k,int &count,int &ans){
    if(root==nullptr)
        return false;

    if(kthSmallest(root->left,k,count,ans))
        return true;

    count++;

    if(count==k){
        ans=root->data;
        return true;
    }

    return kthSmallest(root->right,k,count,ans);
}

void findKth(node* root,int k){
    int count=0;
    int ans=-1;

    if(k<=0 || !kthSmallest(root,k,count,ans)){
        cout<<k<<"th smallest = Out of range"<<endl;
    }
    else{
        cout<<k<<"th smallest = "<<ans<<endl;
    }
}

void showSuccessor(node* root,int key){
    node* ans=inorderSuccessor(root,key);

    cout<<"Successor("<<key<<") = ";

    if(ans==nullptr)
        cout<<"None";
    else
        cout<<ans->data;

    cout<<endl;
}

int main(){

    node* A=new node(50);

    A->left=new node(30);
    A->right=new node(70);

    A->left->left=new node(20);
    A->left->right=new node(40);

    A->right->left=new node(60);
    A->right->right=new node(80);


    node* B=new node(50);

    B->left=new node(30);
    B->right=new node(70);

    B->left->left=new node(20);
    B->left->right=new node(60);

    B->right->left=new node(40);
    B->right->right=new node(80);


    if(isBST(A,LLONG_MIN,LLONG_MAX))
        cout<<"Tree A : VALID BST"<<endl;
    else
        cout<<"Tree A : CORRUPTED"<<endl;


    if(isBST(B,LLONG_MIN,LLONG_MAX))
        cout<<"Tree B : VALID BST"<<endl;
    else
        cout<<"Tree B : CORRUPTED"<<endl;


    cout<<"\nOn Tree A:"<<endl;

    showSuccessor(A,40);
    showSuccessor(A,60);
    showSuccessor(A,30);
    showSuccessor(A,80);

    findKth(A,3);
    findKth(A,7);
    findKth(A,8);

    return 0;
}
