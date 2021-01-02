
#include <bits/stdc++.h> 
using namespace std; 
class Node{
    public:
    int data;
    Node* left;
    Node* right;
};
Node * newnode(int data){
    Node * newnode = new Node();
    newnode->data = data;
    newnode->left=NULL;
    newnode->right=NULL;
    
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

int getMaxWidth(Node* root){
    if(root==NULL){
        return 0;
    }
    int ans = INT_MIN;
    unordered_map<int,int> heightCount;
    unordered_map<Node *,int> height;
    queue<Node *>  q;
    q.push(root);
    height[root]=1;
    heightCount[1]=1;
    while(!q.empty()){
        Node * u = q.front();
        q.pop();
        int h = height[u];
        if(u->left!=NULL){
            height[u->left]=h+1;
            if(heightCount.find(h+1)==heightCount.end()){
                heightCount[h+1]=1;
            }
            else{
                heightCount[h+1]++;
            }
            
            q.push(u->left);
        }
         if(u->right!=NULL){
            height[u->right]=h+1;
            if(heightCount.find(h+1)==heightCount.end()){
                heightCount[h+1]=1;
            }
            else{
                heightCount[h+1]++;
            }
            
            q.push(u->right);
        }
        
    }
    
    for(auto i:heightCount){
        if(ans<i.second){
            ans = i.second;
        }
    }
    
    return ans;
    
}

int main() {
    
   Node * root = newnode(5);
   root->left = newnode(6);
   root->right = newnode(7);
   root->left->left = newnode(8);
   root->left->right = newnode(10);
   root->right->left = newnode(8);
   root->right->right = newnode(10);
   cout<<getMaxWidth(root);

    return 0;
}