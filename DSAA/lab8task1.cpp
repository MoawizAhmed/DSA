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
        node* newnode=new node(val);

        if(root==nullptr){
            root=newnode;
            return;
        }

        node* curr=root;

        while(true){
            if(val==curr->data){
                cout<<"Duplicate roll number "<<val<<" ignored"<<endl;
                delete newnode;
                return;
            }
            else if(val<curr->data){
                if(curr->left==nullptr){
                    curr->left=newnode;
                    return;
                }
                curr=curr->left;
            }
            else{
                if(curr->right==nullptr){
                    curr->right=newnode;
                    return;
                }
                curr=curr->right;
            }
        }
    }

    void search(int val){
        node* curr=root;

        cout<<"Search "<<val<<" : ";

        bool first=true;

        while(curr!=nullptr){
            if(!first)
                cout<<" -> ";

            cout<<curr->data;
            first=false;

            if(val==curr->data){
                cout<<" FOUND"<<endl;
                return;
            }
            else if(val<curr->data){
                curr=curr->left;
            }
            else{
                curr=curr->right;
            }
        }

        cout<<" NOT FOUND"<<endl;
    }

    void inorder(node* curr){
        if(curr==nullptr)
            return;

        inorder(curr->left);
        cout<<curr->data<<" ";
        inorder(curr->right);
    }

    void inorder(){
        cout<<"Sorted list : ";
        inorder(root);
        cout<<endl;
    }
};

int main(){
    bst b;
    int choice,val;

    while(true){
        cout<<"\n1. Register applicant";
        cout<<"\n2. Search applicant";
        cout<<"\n3. Display sorted list";
        cout<<"\n4. Exit";
        cout<<"\nEnter choice: ";
        cin>>choice;

        if(choice==1){
            cout<<"Enter roll number: ";
            cin>>val;
            b.insert(val);
        }
        else if(choice==2){
            cout<<"Enter roll number: ";
            cin>>val;
            b.search(val);
        }
        else if(choice==3){
            b.inorder();
        }
        else if(choice==4){
            break;
        }
        else{
            cout<<"Invalid choice"<<endl;
        }
    }

    return 0;
}