// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    Node * left;
    Node * right;
};
Node * getNode(int data){
    Node * newnode = new Node();
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    
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
int getHeight(Node * root){
    if(root==NULL){
        return 0;
    }
    
    return 1+max(getHeight(root->left),getHeight(root->right));
}
int main() {
   Node * root = getNode(5);
   root->left = getNode(6);
   root->right = getNode(7);
   root->right->left = getNode(8);
   root->right->left->right = getNode(9);
   int height = getHeight(root);
   cout<<height;

}