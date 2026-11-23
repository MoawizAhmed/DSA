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
 return root->height
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
int main()
{
    return 0;
}