#include <bits/stdc++.h>
using namespace std;

struct Node {
     int val;
     Node *left;
     Node *right;
     Node(int x) : val(x), left(NULL), right(NULL) {}
 };


void inorderTraversal(Node* A) {
    
    vector<int> res;
    stack<Node* > s;
    Node* curr = A;
    
    while(curr!=NULL || !s.empty())
    {
        while(curr!=NULL)
        {   
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        res.push_back(curr-> val);
        s.pop();
        
        curr = curr->right;
    }
    
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
  
    cout << "\nInorder traversal of binary tree is \n"; 
    inorderTraversal(root);  
  
    return 0; 
} 
