class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        // if root is null then return false
        if( !root )
            return false;
        
        // if it is a leaf node and sum == targetsum
        if( !root->left && !root->right && targetSum == root->val)
            return true;
        
        // recursion both side
        return ( hasPathSum(root->left, targetSum - root->val) ||
                 hasPathSum(root->right, targetSum - root->val) );
        
    }
};
