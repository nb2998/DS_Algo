/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<int> Solution::preorderTraversal(TreeNode* A) {
    
    vector<int> res;
    TreeNode* curr = A;
    stack<TreeNode* > s;
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
    
    return res;
}
