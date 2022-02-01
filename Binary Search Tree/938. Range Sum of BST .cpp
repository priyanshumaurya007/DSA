class Solution {
public:
    
    void rangeSumBST(TreeNode* root, int low, int high , int &res) 
    {
        // if root is NULL return 
        if( !root )
            return ;
        
        // if root value is between range then add in result
        if( root->val >= low && root->val <= high)
            res += root->val;
        
        // recursion
        if(root->val > low)
        rangeSumBST( root->left , low , high ,res);
        
        if(root->val < high)
        rangeSumBST( root->right, low, high ,res);
        
    }
    
    int rangeSumBST(TreeNode* root, int low, int high)
    {
        int res=0;
        
        rangeSumBST(root, low, high, res);
    
        return res;
    }
    
    
};
