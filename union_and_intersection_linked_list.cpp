

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

void push_back(Node** head,int data){
    Node* newnode = new Node();
    newnode->data= data;
    newnode->next= NULL;
    if(*head==NULL){
        (*head)=newnode;
        return;
    }
    Node* i;
    for(i=*head;i->next!=NULL;i=i->next);
    i->next=newnode;
}

void print(Node* head){
    for(Node* i=head;i!=NULL;i=i->next){
        cout<<i->data<<" ";
    }
    cout<<"\n";
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
Node* uni(Node* l1,Node* l2){
    //cout<<l1->data<<" "<<l2->data<<"\n";
    Node* res=NULL;
    
    if(l1==NULL){
        return l2;
    }
    else if(l2==NULL){
        return l1;
    }
    
    if(l1->data<l2->data){
        res=l1;
        res->next=uni(l1->next,l2);
    }
    else if(l2->data<l1->data){
        res=l2;
        res->next=uni(l1,l2->next);
    }
    else{
        res=l1;
        res->next=uni(l1->next,l2->next);
    }
    return res;
}
Node* inter(Node* l1,Node* l2){
    Node* res = NULL;
    while(l1!=NULL && l2!=NULL){
        //cout<<l1->data<<" "<<l2->data<<"\n";
        if(l1->data<l2->data){
            l1=l1->next;
        }
        else if(l2->data<l1->data){
            l2=l2->next;
        }
        else{
           push_back(&res,l1->data);
           l1=l1->next;
           l2=l2->next;
        }
        
    }
    
    return res;
}
int main()
{
   Node *root1 = NULL;
   push(&root1,1);
   push(&root1,10);
   push(&root1,9);
   push(&root1,12);
   push(&root1,15);
   Node *root2 = NULL;
   push(&root2,9);
   push(&root2,1);
   push(&root2,10);
   push(&root2,15);
   push(&root2,22);
   mergesort(&root1);
   mergesort(&root2);
   Node* result = inter(root1,root2);
   print(result);
   

    return 0;
}
