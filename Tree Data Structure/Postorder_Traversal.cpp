#include <bits/stdc++.h>
using namespace std;
//Definition of Node
struct Node {
     int val;
     Node *left;
     Node *right;
     Node(int x) : val(x), left(NULL), right(NULL) {}
 };


void postorderTraversal(Node* A) {
    
   if(A==NULL) return;
    vector<int> res;
    Node* curr = A ;
    stack<Node* > s;
    s.push(curr);
    
    while(!s.empty())
    {
        curr = s.top();
        s.pop();
        res.push_back(curr->val);
        
        if(curr->left) s.push(curr->left);
        if(curr->right) s.push(curr->right);
        
    }
    reverse(res.begin(),res.end());
    
   for(auto i:res){
       cout << i << " ";
   }
    cout << endl;
}
int main() 
{ 
    struct Node *root = new Node(1); 
    root->left             = new Node(2); 
    root->right         = new Node(3); 
    root->left->left     = new Node(4); 
    root->left->right = new Node(5);  
  
    cout << "\nPostorder traversal of binary tree is \n"; 
    postorderTraversal(root);  
  
    return 0; 
} 
