// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node * left;
    Node * right;
    Node(int n){
        data = n;
        left = NULL;
        right = NULL;
    }
};

Node * ExactleaftoDLL(Node * root, Node ** headref){
    if(root == NULL){
        return NULL;
    }
    
    if(root->left == NULL && root->right == NULL){
        root->right = (* headref);
        if(* headref!= NULL) {
            (* headref)->left = root;
        }
        
        (* headref)=root;
        return NULL;
    }
    
    root->left = ExactleaftoDLL(root->left,headref);
    root->right = ExactleaftoDLL(root->right,headref);
    
    return root;
}
void displayTree(Node * root){
    if(root==NULL){
        return ;
    }
    
    displayTree(root->left);
    cout<<root->data<<" ";
    displayTree(root->right);
}
void displayDLL(Node * root){
    cout<<"\n";
    for(Node * i = root;i!=NULL;i=i->right){
        cout<<i->data<<" ";
    }
    cout<<"\n";
}
 
int main() {
    Node * headref = NULL;
    Node * root = new Node(6);
    root->left = new Node(4);
    root->right = new Node(9);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    displayTree(root);
    Node * DLL = ExactleaftoDLL(root,&headref);
    displayDLL(headref);
    displayTree(root);
    
}