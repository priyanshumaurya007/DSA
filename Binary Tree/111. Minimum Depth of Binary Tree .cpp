class Solution {
public:
    int minDepth(TreeNode* root) 
    {
        // if root doesn't exist
        if( root == NULL )
            return 0;

        
        // go to its children if exist
        int left = minDepth( root->left );
        int right = minDepth( root->right );
        
        // if left doesn't exist , so return right value
        if( left == 0)
            return 1 + right;
        
        // if right doesn't exist , so return left value
        if( right == 0)
            return 1 + left;
        
        // otherwise return min of left and right value , +1 for current value 
        return 1 + min(left, right);
        
    }
};
