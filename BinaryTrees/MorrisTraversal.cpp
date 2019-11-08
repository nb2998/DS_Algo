void inorder(TreeNode* root)
{
    TreeNode* curr = root;
    while(curr)
    {
        if(curr->left == NULL)
        {
            cout<<curr->val<<" ";
            curr = curr->right;
        }
        else
        {
            TreeNode* node = curr->left; //inorder predecessor
            while(node->right && node->right != curr)
                node = node->right;
            if(node->right == curr) 
            {
                cout<<curr->val<<" ";
                node->right = NULL;
                curr = curr->right; 
                
            }
            else
            {
                node->right = curr; 
                curr = curr->left;
            }
        }
    }
}
void preorder(TreeNode* root)
{
    TreeNode* curr = root;
    while(curr)
    {
        if(curr->left == NULL)
        {
            cout<<curr->val<<" ";
            curr = curr->right;
        }
        else
        {
            TreeNode* node = curr->left;
            while(node->right && node->right != curr)
                node = node->right;
            if(node->right == curr) 
            {
                node->right = NULL;
                curr = curr->right;
            }
            else
            {
                cout<<curr->val<<" ";
                node->right = curr;
                curr = curr->left;
                
            }
        }
    }
}
