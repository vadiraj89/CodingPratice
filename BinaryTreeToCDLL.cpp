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


Node * concate(Node * leftpart,Node * rightpart){
    if(leftpart==NULL){
        return rightpart;
    }
    if(rightpart==NULL){
        return leftpart;
    }
    Node * leftlast = leftpart->left;
    Node * rightlast = rightpart->left;
    
    leftlast->right = rightpart;
    rightpart->left = leftlast;
    
    leftpart->left = rightlast;
    rightlast->right = leftpart;
    
    return leftpart;
}

void display(Node * root){
    Node * top = root;
    cout<<top->data<<" ";
    for(Node * i = top->right;i!=root;i=i->right){
        cout<<i->data<<" ";
    }
}

Node * conevrtBTToCDLL(Node * root){
    if(root == NULL){
        return NULL;
    }
    
    Node * leftpart = conevrtBTToCDLL(root->left);
    Node * rightpart = conevrtBTToCDLL(root->right);
    
    root->left = root->right = root;
    
    return concate(concate(leftpart,root),rightpart);
    
}
 
int main() {
  Node * root = new Node(5);
  root->right = new Node(9);
  root->left = new Node(3);
  Node * CDLL = conevrtBTToCDLL(root);
  display(CDLL);
 
}