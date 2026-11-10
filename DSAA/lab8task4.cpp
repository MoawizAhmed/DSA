
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

    node* findMin(){
        if(root==nullptr)
            return nullptr;

        node* curr=root;

        while(curr->left!=nullptr)
            curr=curr->left;

        return curr;
    }

    node* findMax(){
        if(root==nullptr)
            return nullptr;

        node* curr=root;

        while(curr->right!=nullptr)
            curr=curr->right;

        return curr;
    }

    void rangeSearch(node* curr,int low,int high,int &count){
        if(curr==nullptr)
            return;

        count++;

        if(curr->data>low)
            rangeSearch(curr->left,low,high,count);

        if(curr->data>=low && curr->data<=high)
            cout<<curr->data<<" ";

        if(curr->data<high)
            rangeSearch(curr->right,low,high,count);
    }

    void rangeSearch(int low,int high){
        int count=0;

        cout<<"Range ["<<low<<", "<<high<<"] : ";

        rangeSearch(root,low,high,count);

        cout<<"\nVisited nodes : "<<count<<endl;
        cout<<"Total nodes : "<<totalNodes(root)<<endl;
    }

    void floorPrice(int val){
        node* curr=root;
        node* ans=nullptr;

        while(curr!=nullptr){
            if(curr->data==val){
                ans=curr;
                break;
            }

            else if(curr->data<val){
                ans=curr;
                curr=curr->right;
            }

            else{
                curr=curr->left;
            }
        }

        cout<<"Floor("<<val<<") : ";

        if(ans==nullptr)
            cout<<"None";
        else
            cout<<ans->data;
    }

    void ceilPrice(int val){
        node* curr=root;
        node* ans=nullptr;

        while(curr!=nullptr){
            if(curr->data==val){
                ans=curr;
                break;
            }

            else if(curr->data>val){
                ans=curr;
                curr=curr->left;
            }

            else{
                curr=curr->right;
            }
        }

        cout<<" Ceil("<<val<<") : ";

        if(ans==nullptr)
            cout<<"None";
        else
            cout<<ans->data;

        cout<<endl;
    }

    int totalNodes(node* curr){
        if(curr==nullptr)
            return 0;

        return 1+totalNodes(curr->left)+totalNodes(curr->right);
    }
};

int main(){
    bst b;

    int arr[]={1500,800,2500,500,1000,2000,3500,750,1200,3000};

    for(int i=0;i<10;i++){
        b.insert(arr[i]);
    }

    b.rangeSearch(1000,2500);

    node* min=b.findMin();
    node* max=b.findMax();

    if(min!=nullptr)
        cout<<"Cheapest : "<<min->data<<endl;

    if(max!=nullptr)
        cout<<"Most expensive : "<<max->data<<endl;

    b.floorPrice(1800);
    b.ceilPrice(3600);

    b.floorPrice(400);
    b.ceilPrice(3600);

    return 0;
}
