
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
void merge(Node * root1,Node * root2){
   
    if(root1==NULL && root2 == NULL){
        return ;
    }
    if(root1==NULL){
        print(root2);
        return;
    }
    if(root2==NULL){
        print(root1);
        return;
    }
    Node * temp1 = root1;
    Node * prev1 = NULL;
    Node * temp2 = root2 ;
    Node * prev2 = NULL;
    while(temp1->left){
        prev1 = temp1;
        temp1 = temp1->left;
    }
    while(temp2->left){
        prev2 = temp2;
        temp2 = temp2->left;
    }
    if(temp1->data<temp2->data){
        cout<<temp1->data<<" ";
        
        if(prev1==NULL){
            merge(root1->right,root2);
        }
        else
        {
        prev1->left = temp1->right;
        merge(root1,root2);
        }
    }
    else{
        cout<<temp2->data<<" ";
        
        if(prev2==NULL){
            merge(root1,root2->right);
        }
        else
        {
        prev2->left = temp2->right;
        merge(root1,root2);
        }
    }
    
}

int main() {
    
   Node * root1 = newnode(3);
   root1->left = newnode(1);
   root1->right = newnode(5);
  Node * root2 = newnode(7);
  root2->left = newnode(6);
  root2->right = newnode(8);
   merge(root1,root2);
    return 0;
}