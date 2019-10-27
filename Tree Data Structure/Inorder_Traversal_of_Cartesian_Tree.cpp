/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
TreeNode* tree(vector<int> &A, int l, int r)
{
    if(l>r)return NULL;
    
    int mx = A[l], idx = l;
    
    
    for(int i = l;i<=r;i++)
    {
        if(A[i]>mx)
        {
            mx = A[i];
            idx = i;
        }
    }
    
    TreeNode* root = new TreeNode(mx);
    
    root->left = tree(A,l,idx-1);
    root->right = tree(A,idx+1,r);
    return root;
}
TreeNode* Solution::buildTree(vector<int> &A) {
    return tree(A,0,(int)A.size()-1);
}
