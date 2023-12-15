#include <bits/stdc++.h>
#include <queue>
using namespace std;
class node {
  // properties
public:
  int data;
  node *left;
  node *right;

  // constructor
  node(int d) {
    this->data = d;
    this->left = NULL;
    this->right = NULL;
  }
};
void levelordertraversal(node *root) {
  queue<node *> q;
  q.push(root);
  q.push(NULL);
  while (!q.empty()) {
    node *temp = q.front();

    q.pop();
    if (temp == NULL) {
      cout << endl;
      if (!q.empty()) {
        q.push(NULL);
      }
    } else {
      cout << temp->data << " ";
      if (temp->left != NULL) {
        q.push(temp->left);
      }
      if (temp->right != NULL) {
        q.push(temp->right);
      }
    }
  }
}
node *insertion(node *root, int d) {
  // base case
  if (root == NULL) {
    root = new node(d);
    return root;
  }
  if (d > root->data) {
    root->right = insertion(root->right, d);
  } 
  else {
    root->left = insertion(root->left, d);
  }
  return root;
}
void takeinput(node *&root) {
  int data;
  cin >> data;
  while (data != -1) {
    root = insertion(root, data);
    cin >> data;
  }
}
bool search(node* root,int n ){
    //base case
    if(root==NULL){
        return false;
    }
    if(n==root->data){
        return true;
    }
    if(n>root->data){
        search(root->right,n);
    }
    else{
        search(root->left,n);
    }
}
int max_or_min(node* root,string str){
    node* temp_min=root;
    node* temp_max=root;
    if(str=="min"){
    while(temp_min->left!=NULL){
        temp_min=temp_min->left;
    }
    return(temp_min->data);
    }
    else if(str=="max"){
    while(temp_max->right){
        temp_max=temp_max->right;
    }
    return(temp_max->data);
    }
    else{
        cout<<"Invalid input";
        return(0);
    }
}
int main() {
  node *root = NULL;
  cout << "Enter data" << endl;
  takeinput(root);

  levelordertraversal(root);
}
