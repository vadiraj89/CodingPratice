

#include <bits/stdc++.h>

using namespace std;
class Node{
    public:
    int data;
    Node* next;
};

void push(Node** head,int data){
    Node* newnode = new Node();
    newnode->data= data;
    newnode->next= (*head);
    (* head)=newnode;
}

void print(Node* head){
    for(Node* i=head;i!=NULL;i=i->next){
        cout<<i->data<<" ";
    }
}
void split(Node* head,Node** l,Node** r){
    Node* first = head;
    Node* second = head->next;
    while(second!=NULL){
        second = second->next;
        if(second!=NULL){
            first=first->next;
            second=second->next;
        }
        
    }
    (*l)=head;
    (*r)=first->next;
    first->next=NULL;
}
Node* merge(Node* left,Node* right){
    Node* result = NULL;
    if(left==NULL){
        return right;
    }
    else if(right==NULL){
        return left;
    }
    if(left->data<right->data){
        result=left;
        result->next=merge(left->next,right);
    }
    else{
        result=right;
        result->next=merge(left,right->next);
    }
    return result;
}
void mergesort(Node** root){
    Node* head = (*root);
    Node* left;
    Node* right;
    if(head==NULL || head->next==NULL){
        return;
    }
    split(head,&left,&right);
    mergesort(&left);
    mergesort(&right);
    
    *root = merge(left,right);
}

int main()
{
   Node *root = NULL;
   push(&root,20);
   push(&root,15);
   push(&root,17);
   push(&root,25);
   push(&root,22);
   mergesort(&root);
   print(root);
   

    return 0;
}
