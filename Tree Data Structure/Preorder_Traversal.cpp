#include <bits/stdc++.h>
using namespace std;

struct Node {
     int val;
     Node *left;
     Node *right;
     Node(int x) : val(x), left(NULL), right(NULL) {}
 };


void preorderTraversal(Node* A) {
    
    vector<int> res;
    Node* curr = A;
    stack<Node* > s;
    s.push(curr);
    
    while(!s.empty())
    {
        curr = s.top();
        res.push_back(curr->val);
        s.pop();
        
        if(curr->right)
            s.push(curr->right);
            
        if(curr->left)
            s.push(curr->left);
    }
    
    for(auto i:res){
       cout << i << " ";
   }
    cout << endl;
}

int main() 
{ 
    Node *root = new Node(1); 
    root->left             = new Node(2); 
    root->right         = new Node(3); 
    root->left->left     = new Node(4); 
    root->left->right = new Node(5);  
  
    cout << "\nPreorder traversal of binary tree is \n"; 
    preorderTraversal(root);  
  
    return 0; 
} 
