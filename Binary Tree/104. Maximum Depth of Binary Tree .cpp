class Solution {
public:
    int maxDepth(TreeNode* root) 
    {
        // if root is NULL so return 0
        if( root == NULL)
            return 0;
        
        // go to their child if exists
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        
        // return the max height of left and right +1 of current node 
        return 1 + max(left,right);
        
    }
};
