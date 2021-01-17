// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
 
class Node{
    public :
    int coeff;
    int power;
    Node * next;
};
void push(Node ** head,int coeff,int power){
    Node * newnode = new Node();
    newnode->coeff = coeff;
    newnode->power = power;
    newnode->next = (* head);
    (* head)=newnode;
    return;
}

void display(Node * root){
    cout<<"\n";
    for(Node * i = root;i!=NULL;i=i->next){
        cout<<i->coeff<<" x^"<<i->power<<" +";
    }
}
Node * PolynomialAdd(Node * head1,Node * head2){
    Node * newnode = NULL;
    if(head1==NULL && head2==NULL){
        return NULL;
    }
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    if(head1->power>head2->power){
        newnode = head1;
        newnode->next = PolynomialAdd(head1->next,head2);
    }
    else if(head2->power>head1->power){
        newnode = head2;
        newnode->next = PolynomialAdd(head1,head2->next);
     }
     else{
         newnode=head1;
         newnode->coeff=newnode->coeff+head2->coeff;
         newnode->next = PolynomialAdd(head1->next,head2->next);
     }
     return newnode;
}
int main() {
    Node * head1 =NULL;
    push(&head1,1,1);
    push(&head1,2,2);
    push(&head1,3,3);
    push(&head1,4,4);
    display(head1);
    Node * head2 =NULL;
    push(&head2,5,1);
    push(&head2,6,2);
    push(&head2,7,3);
    push(&head2,8,4);
    display(head2);
    Node * addedSum = PolynomialAdd(head1,head2);
    display(addedSum);
    return 0;
}