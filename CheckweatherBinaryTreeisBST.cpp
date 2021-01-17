// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
bool answer = true; 
class Node{
    public :
    int data;
    Node * left;
    Node * right;
};

Node * getNode(int data){
    Node * newnode = new Node();
    newnode->data = data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
void binarySearchCheck(Node * root,Node ** prev){
    if(root==NULL){
        return;
    }
    binarySearchCheck(root->left,prev);
    if(*prev && (*prev)->data>root->data){
        answer=false;
        return;
    }
    *prev=root;
    binarySearchCheck(root->right,prev);
}

int main() {
   Node * root = getNode(5);
   root->right = getNode(6);
   root->left = getNode(7);
   Node * prev = NULL;
   binarySearchCheck(root,&prev);
   if(answer){
       cout<<"its binary search tree";
   }
   else{
       cout<<"Its  Not Binary tree";
   }
   return 0;
}