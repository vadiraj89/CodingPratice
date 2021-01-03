
#include <bits/stdc++.h> 
using namespace std; 
vector<int> inorder;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
};
Node * newnode(int data){
    Node * newnode = new Node();
    newnode->data = data;
    newnode->left=NULL;
    newnode->right=NULL;
    
    return newnode;
}
void print(Node * root){
    if(root==NULL){
        return ;
    }
    
    print(root->left);
    cout<<root->data<<" ";
    
    print(root->right);
    
}
void getInorder(Node * root){
    if(root==NULL){
        return ;
    }
    
    getInorder(root->left);
    inorder.push_back(root->data);
    getInorder(root->right);
    
}
void placeinorder(Node *root,int *index){
      if(root==NULL){
        return ;
    }
    
    placeinorder(root->left,index);
    root->data = inorder[(* index)];
    (*index)++;
    placeinorder(root->right,index);
}
void BinaryToBst(Node * root){
    int index = 0;
    getInorder(root);
    sort(inorder.begin(),inorder.end());
    placeinorder(root,&index);
    
}

int main() {
    
   Node * root = newnode(50);
   root->left = newnode(30);
   root->right = newnode(100);
   root->left->left = newnode(80);
   root->left->right = newnode(90);
   root->right->left = newnode(70);
   root->right->right = newnode(60);
   int sum=0;
   print(root);
   BinaryToBst(root);
   cout<<"\n";
   print(root);

    return 0;
}