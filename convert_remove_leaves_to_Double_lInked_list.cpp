#include <bits/stdc++.h>

using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
};
Node* newnode(int data){
    Node* newnode = new Node();
    newnode->data=data;
    newnode->right=newnode->left=NULL;
    newnode;
}
void print(Node* root){
    
    if(root==NULL){
        return;
    }
    
    print(root->left);
    
    cout<<root->data<<" ";
    
    print(root->right);
}

Node* convertDLL(Node* head,Node** DLLhead){
    
    if(head==NULL){
        return NULL;
    }
    
     if(head->right==NULL && head->left==NULL){
        
        head->right=*DLLhead;
        if(*DLLhead!=NULL) {
            (*DLLhead)->left=head;
        }
        
        (*DLLhead)=head;
        
        return NULL;
    }
    
    head->right= convertDLL(head->right,DLLhead);
    head->left= convertDLL(head->left,DLLhead);
    
    return head;
    
}

void printll(Node* root){
    cout<<"Linked List Printing  ";
    Node* i;
    for(i=root;i!=NULL;i=i->right){
        cout<<i->data<<" ";
    }
}
int main()
{
    Node* root = newnode(5);
    root->right=newnode(6);
    root->left=newnode(7);
    root->right->right=newnode(9);
    root->right->left=newnode(10);
    root->left->right=newnode(11);
    root->left->left=newnode(12);
    Node *DLLhead = NULL;
    Node* m = convertDLL(root,&DLLhead);
    cout<<"Tree Printing ";
    print(m);
    printll(DLLhead);
    return 0;
}
