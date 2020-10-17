int height(TreeNode *root){
        if(!root)
            return 0;
        return 1+max(height(root->left),height(root->right));
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(!root->left&&!root->right)
            return root;
        if(root->left && root->right){
            int a=height(root->left),
            b=height(root->right);
            if(a==b)
                return root;
            else if(a>b)
                return lcaDeepestLeaves(root->left);
            else
                return lcaDeepestLeaves(root->right);
        }
        if(!root->left)
            return lcaDeepestLeaves(root->right);
        else
            return lcaDeepestLeaves(root->left);
    }