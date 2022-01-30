class Solution {
public:
    
    // to store the max diameter
    int max_res = 0;
    
    int diameter(TreeNode *root)
    {
        // if root is NULL return 0
        if( root == NULL)
        {
            return 0;
        }
        
        // check the height of left sub tree
        int left = diameter(root->left);
        
        // check the height of right sub tree
        int right = diameter(root->right);
        
        // check max left+right 
        max_res = max(max_res, left+right);
        
        // return the height of sub tree
        return 1 + max(left,right);
    }
    
    int diameterOfBinaryTree(TreeNode* root) 
    {
        diameter( root );
        
        return max_res;
        
    }
};
