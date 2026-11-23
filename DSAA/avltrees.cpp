#include <iostream>
#include <algorithm>
using namespace std;
class node
{
public:
 int value;
 node* right;
 node* left;
 int height;
 node(){}
 node(int value)
 {
    this->value=value;
    this->right=nullptr;
    this->left=nullptr;
    height=1;
 }
};
node* createnode(int value)
{
    node* newnode=new node(value);
    return newnode;
}
int getheight(node* root)
{
    if(root==nullptr)
    {
        return 0;
    }
 return root->height;
}
void updateheight(node* root)
{
 1+max(getheight(root->left),getheight(root->right));
}
int getbalance(node* root)
{
    if(root==nullptr)
    {
        return 0;
    }
    return getheight(root->left)-getheight(root->right);
}
node* rotateright(node* y)
{
    node* x=y->left;
    node* T2=x->right;

    x->right=y;
    y->left=T2;

    updateheight(y);
    updateheight(x);

    return x;
}

node* rotateleft(node* x)
{
    node* y=x->right;
    node* T2=y->left;
    
    y->left=x;
    x->right=T2;

    updateheight(x);
    updateheight(y);

    return y;
}

node* insert(node* root,int value)
{
    if(root=nullptr)
    {
        return createnode(value);
    }
    else if(value<root->value)
    {
    root->left=insert(root->left,value);
    }
    else if(value>root->value)
    {
        root->right=insert(root->right,value);
    }
    else
    {
        return root;
    }

    updateheight(root);
    int balance=getbalance(root);

    //ll
    if(balance > 1 && value < root->left->value)
    {
        return rotateright(root);
    }
    //rr
    if(balance < -1 && value > root->right->value)
    {
        return rotateleft(root);
    }
    //lr
    if(balance > 1 && value > root->left->value)
    {
        root->left=rotateleft(root->left);
        return rotateright(root);
    }
    //rl
    if(balance < -1 && value < root->right->value)
    {
        root->right=rotateright(root->right);
        return rotateleft(root);
    }
    return root;
}
node* findMin(node* root) {

    while (root->left != NULL)
        root = root->left;

    return root;
}

node* deletee(node* root,int value)
{
 if(root==nullptr)
 {
    return root;
 }
 else if(value < root->value)
 {
    root->left=deletee(root->left,value);
 }
 else if(value > root->value)
 {
    root->right=deletee(root->right,value);
 }
 else
 {
    if(root->right==nullptr || root->left==nullptr)
    {
        node* temp= root->left? root->left:root->right;
        delete root;
        return temp;
    }

    node* temp=findMin(root->right);
    root->value=temp->value;

    root->right=deletee(root->right,temp->value);
     
 }
 if(root=nullptr)
 {
    return nullptr;
 }
 updateheight(root);
 //ll
 if(getbalance(root) > 1 && getbalance(root->left) >=0 )
 {
    return rotateright(root);
 }
 //rr
 if(getbalance(root) < -1 &&  getbalance(root->right)<=0)
 {
    return rotateleft(root);
 }
 //lr
 if(getbalance(root) > 1 && getbalance(root->left) < 0)
 {
    root->left=rotateleft(root->right);
    return rotateright(root);
 }
 //rl
 if(getbalance(root) < -1 && getbalance(root->right) > 0)
 {
    root->right=rotateright(root->right);
    return rotateleft(root);
 }
 return root;
}
int main()
{
    return 0;
}