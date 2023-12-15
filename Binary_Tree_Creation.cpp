#include<bits/stdc++.h>
#include<queue>
using namespace std;
class node{
    //properties
    public:
    int data;
    node* left;
    node* right;

    //constructor
    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }

};
node* buildtree(node* root){
    cout<<"Enter data "<<endl;
    int data;
    cin>>data;
    root=new node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"Enter data of left "<<data<<endl;
    root->left=buildtree(root->left);
    cout<<"Enter data of right "<<data<<endl;
    root->right=buildtree(root->right);
    return root;    
}
void levelordertraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
    node* temp=q.front();
   
    q.pop();
    if(temp==NULL){
        cout<<endl;
        if(!q.empty()){
           q.push(NULL); 
        }
    }
    else{
        cout<<temp->data<<" ";
    if(temp->left!=NULL){
        q.push(temp->left);
    }
    if(temp->right!=NULL){
        q.push(temp->right);
    }

    }
    }
}
void inorder(node* root){
    //base case
    if(root==NULL){
        return;

    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}
void preorder(node* root){
     //base case
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(node* root){
       //base case
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}


int main(){
    node* root=NULL;

    //creating a tree
    root=buildtree(root);

    //printing the tree in level
    levelordertraversal(root);

    //inorder traversal
    inorder(root);

    cout<<endl;

    //preorder traversal
    preorder(root);

    cout<<endl;

    //postorder traversal
    postorder(root);

}