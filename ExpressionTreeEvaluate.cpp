// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    string data;
    Node * left;
    Node * right;
    Node(string n){
        data = n;
        left = NULL;
        right = NULL;
    }
};
int evaluateExpressionTree(Node * root){
    if(root->left == NULL && root->right == NULL){
        return stoi(root->data);
    }
    int leftresult = evaluateExpressionTree(root->left);
    int rightresult = evaluateExpressionTree(root->right);
    int res = -1;

        if(root->data=="+")
          res = leftresult+rightresult;
        else if (root->data=="-")
         res = leftresult-rightresult;
        else if (root->data=="*")
         res =  leftresult*rightresult;
        else if (root->data=="/")
         res = leftresult/rightresult;
         
     return res;
}
 
int main() {
    
    Node * root = new Node("+");
    root->left = new Node("*");
    root->right = new Node ("-");
    root->left->left = new Node("5");
    root->left->right = new Node("4");
    root->right->left = new Node ("100");
    root->right->right = new Node ("20");
    
    int result = evaluateExpressionTree(root);
    cout<<result;

    
}