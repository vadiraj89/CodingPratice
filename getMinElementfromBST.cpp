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
void getMinFromBst(Node * root){
    
    if(root==NULL){
        return;
    }
    getMinFromBst(root->left);
    answer = min(answer,root->data);
    
}

int main() {
   Node * root = getNode(5);
   root->right = getNode(7);
   root->left = getNode(3);
   root->left->left = getNode(2);
   root->left->right = getNode(4);
   getMinFromBst(root);
   cout<<answer;

}