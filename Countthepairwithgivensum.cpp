// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node * next;
    Node(int n){
        data = n;
        next = NULL;
    }
};
void addNode(Node * node,Node ** head){
    node->next = *head;
    *head = node;
 }
 
 void display(Node * root){
     
     for(Node * i = root;i!=NULL;i=i->next){
         cout<<i->data<<" ";
     }
     cout<<"\n";
 }
 int returnPairs(Node * root1, Node * root2 , int x){
     int count =0;
     unordered_map<int,Node *> map;
     for(Node * i=root1;i!=NULL;i=i->next){
         map[i->data]=i;
     }
     for(Node * i = root2;i!=NULL;i=i->next){
         if(map.find(x-i->data)!=map.end()){
             count++;
         }
     }
     
     return count;
 }
 
int main() {
    Node * head1 = NULL;
    addNode(new Node(1),&head1);
    addNode(new Node(2),&head1);
    addNode(new Node(3),&head1);
    display(head1);
    Node * head2 = NULL;
    addNode(new Node(1),&head2);
    addNode(new Node(2),&head2);
    addNode(new Node(3),&head2);
    display(head2);
    int count = returnPairs(head1,head2,4);
    cout<<count;
 
}