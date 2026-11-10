
#include <iostream>
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

class bst{
    node* root;

public:
    bst(){
        root=nullptr;
    }

    void insert(int val){
        if(root==nullptr){
            root=new node(val);
            return;
        }

        node* curr=root;

        while(true){
            if(val==curr->data)
                return;

            else if(val<curr->data){
                if(curr->left==nullptr){
                    curr->left=new node(val);
                    return;
                }
                curr=curr->left;
            }
            else{
                if(curr->right==nullptr){
                    curr->right=new node(val);
                    return;
                }
                curr=curr->right;
            }
        }
    }

    node* findMin(node* curr){
        while(curr->left!=nullptr)
            curr=curr->left;

        return curr;
    }

    node* findMax(node* curr){
        while(curr->right!=nullptr)
            curr=curr->right;

        return curr;
    }

    node* deleteNode(node* curr,int val){
        if(curr==nullptr)
            return nullptr;

        if(val<curr->data)
            curr->left=deleteNode(curr->left,val);

        else if(val>curr->data)
            curr->right=deleteNode(curr->right,val);

        else{
            if(curr->left==nullptr && curr->right==nullptr){
                cout<<"LEAF"<<endl;
                delete curr;
                return nullptr;
            }

            else if(curr->left==nullptr || curr->right==nullptr){
                cout<<"ONE CHILD"<<endl;

                node* temp;

                if(curr->left!=nullptr)
                    temp=curr->left;
                else
                    temp=curr->right;

                delete curr;
                return temp;
            }

            else{
                node* temp=findMin(curr->right);

                cout<<"TWO CHILDREN (replaced by successor "
                    <<temp->data<<")"<<endl;

                curr->data=temp->data;
                curr->right=deleteNode(curr->right,temp->data);
            }
        }

        return curr;
    }

    node* deletePredecessor(node* curr,int val){
        if(curr==nullptr)
            return nullptr;

        if(val<curr->data)
            curr->left=deletePredecessor(curr->left,val);

        else if(val>curr->data)
            curr->right=deletePredecessor(curr->right,val);

        else{
            if(curr->left==nullptr && curr->right==nullptr){
                delete curr;
                return nullptr;
            }

            else if(curr->left==nullptr || curr->right==nullptr){
                node* temp;

                if(curr->left!=nullptr)
                    temp=curr->left;
                else
                    temp=curr->right;

                delete curr;
                return temp;
            }

            else{
                node* temp=findMax(curr->left);

                curr->data=temp->data;
                curr->left=deletePredecessor(curr->left,temp->data);
            }
        }

        return curr;
    }

    bool exists(int val){
        node* curr=root;

        while(curr!=nullptr){
            if(val==curr->data)
                return true;

            else if(val<curr->data)
                curr=curr->left;

            else
                curr=curr->right;
        }

        return false;
    }

    void preorder(node* curr){
        if(curr==nullptr)
            return;

        cout<<curr->data<<" ";
        preorder(curr->left);
        preorder(curr->right);
    }

    void inorder(node* curr){
        if(curr==nullptr)
            return;

        inorder(curr->left);
        cout<<curr->data<<" ";
        inorder(curr->right);
    }

    void preorder(){
        cout<<"pre-order : ";
        preorder(root);
        cout<<endl;
    }

    void inorder(){
        cout<<"in-order : ";
        inorder(root);
        cout<<endl;
    }

    void discharge(int val){
        cout<<"Discharge "<<val<<" -> ";

        if(!exists(val)){
            cout<<"Patient not found"<<endl;
            return;
        }

        root=deleteNode(root,val);

        preorder();
        inorder();
    }

    void dischargeBonus(int val){
        cout<<"Discharge "<<val<<" using predecessor -> ";

        if(!exists(val)){
            cout<<"Patient not found"<<endl;
            return;
        }

        root=deletePredecessor(root,val);

        preorder();
        inorder();
    }
};

int main(){
    bst b;

    int arr[]={10,6,13,4,8,11,25,2,5,7,9,12,20};

    for(int i=0;i<13;i++){
        b.insert(arr[i]);
    }

    cout<<"Initial pre-order : ";
    b.preorder();

    b.discharge(2);
    b.discharge(11);
    b.discharge(6);
    b.discharge(99);

    cout<<"\n--- BONUS: IN-ORDER PREDECESSOR ---"<<endl;

    bst b2;

    for(int i=0;i<13;i++){
        b2.insert(arr[i]);
    }

    b2.preorder();

    b2.dischargeBonus(2);
    b2.dischargeBonus(11);
    b2.dischargeBonus(6);
    b2.dischargeBonus(99);

    return 0;
}
