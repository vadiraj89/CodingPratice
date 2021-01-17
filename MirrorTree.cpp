// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
int answer = INT_MAX; 
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
void mirrorTree(Node * root){
    if(root==NULL){
        return;
    }
    Node * temp =root->left;
    root->left = root->right;
    root->right = temp;
    mirrorTree(root->left);
    mirrorTree(root->right);
}
void levelordertraversal(Node * root){
    
    queue<Node *> q;
    q.push(root);
    while(!q.empty()){
        Node * u = q.front();
        q.pop();
        cout<<u->data<<" ";
        if(u->left!=NULL){
            q.push(u->left);
        }
        if(u->right!=NULL){
            q.push(u->right);
        }
    }
    cout<<"\n";
}
int main() {
   Node * root = getNode(5);
   root->right = getNode(7);
   root->left = getNode(3);
   root->left->left = getNode(2);
   root->left->right = getNode(4);
   levelordertraversal(root);
   mirrorTree(root);
   levelordertraversal(root);

}