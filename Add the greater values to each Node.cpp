
#include <bits/stdc++.h> 
using namespace std; 
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

void modify(Node * root,int *sum){
    if(root==NULL){
        return;
    }
    
    modify(root->right,sum);
    
    (*sum)=(*sum)+root->data;
    root->data=(*sum);
    modify(root->left,sum);
}

int main() {
    
   Node * root = newnode(50);
   root->left = newnode(30);
   root->right = newnode(70);
   root->left->left = newnode(20);
   root->left->right = newnode(40);
   root->right->left = newnode(60);
   root->right->right = newnode(80);
   int sum=0;
   modify(root,&sum);
   print(root);

    return 0;
}