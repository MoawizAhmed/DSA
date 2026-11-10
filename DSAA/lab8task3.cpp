
#include <iostream>
#include <queue>
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

node* createNode(int val){
    return new node(val);
}

void preorder(node* root){
    if(root==nullptr)
        return;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(node* root){
    if(root==nullptr)
        return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(node* root){
    if(root==nullptr)
        return;

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void levelorder(node* root){
    if(root==nullptr)
        return;

    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node* curr=q.front();
        q.pop();

        cout<<curr->data<<" ";

        if(curr->left!=nullptr)
            q.push(curr->left);

        if(curr->right!=nullptr)
            q.push(curr->right);
    }
}

int totalNodes(node* root){
    if(root==nullptr)
        return 0;

    return 1+totalNodes(root->left)+totalNodes(root->right);
}

int leafNodes(node* root){
    if(root==nullptr)
        return 0;

    if(root->left==nullptr && root->right==nullptr)
        return 1;

    return leafNodes(root->left)+leafNodes(root->right);
}

int height(node* root){
    if(root==nullptr)
        return -1;

    int leftheight=height(root->left);
    int rightheight=height(root->right);

    if(leftheight>rightheight)
        return leftheight+1;

    return rightheight+1;
}

bool isFull(node* root){
    if(root==nullptr)
        return true;

    if(root->left==nullptr && root->right==nullptr)
        return true;

    if(root->left!=nullptr && root->right!=nullptr)
        return isFull(root->left) && isFull(root->right);

    return false;
}

bool isComplete(node* root){
    if(root==nullptr)
        return true;

    queue<node*> q;
    q.push(root);

    bool missing=false;

    while(!q.empty()){
        node* curr=q.front();
        q.pop();

        if(curr->left!=nullptr){
            if(missing)
                return false;

            q.push(curr->left);
        }
        else{
            missing=true;
        }

        if(curr->right!=nullptr){
            if(missing)
                return false;

            q.push(curr->right);
        }
        else{
            missing=true;
        }
    }

    return true;
}

void display(node* root){
    cout<<"Pre-order : ";
    preorder(root);

    cout<<"\nIn-order : ";
    inorder(root);

    cout<<"\nPost-order : ";
    postorder(root);

    cout<<"\nLevel-order : ";
    levelorder(root);

    cout<<endl;
}

void analysis(node* root){
    cout<<"Nodes : "<<totalNodes(root)<<endl;
    cout<<"Leaves : "<<leafNodes(root)<<endl;
    cout<<"Height : "<<height(root)<<endl;

    cout<<"Full? ";
    if(isFull(root))
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

    cout<<"Complete? ";
    if(isComplete(root))
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}

int main(){

    node* A=createNode(1);

    A->left=createNode(2);
    A->right=createNode(3);

    A->left->left=createNode(4);
    A->left->right=createNode(5);

    A->right->left=createNode(6);


    node* B=createNode(1);

    B->left=createNode(2);
    B->right=createNode(3);

    B->left->left=createNode(4);
    B->left->right=createNode(5);

    B->right->right=createNode(7);


    node* C=createNode(1);

    C->left=createNode(2);
    C->right=createNode(3);

    C->left->left=createNode(4);
    C->left->right=createNode(5);

    C->right->left=createNode(6);
    C->right->right=createNode(7);


    cout<<"========== CHART A =========="<<endl;
    display(A);
    analysis(A);

    cout<<"\n========== CHART B =========="<<endl;
    display(B);
    analysis(B);

    cout<<"\n========== CHART C =========="<<endl;
    display(C);
    analysis(C);

    return 0;
}
