class Solution {
public:
    
    void find(TreeNode *root, int &min_val , long &ans)
    {
        if(!root)
            return ;
        
        if( min_val < root->val && root->val < ans)
            ans = root->val;
        
        else if ( min_val == root->val )
        {
            find(root->left, min_val , ans);
            find(root->right, min_val , ans);
        }
        
    }
    
    int findSecondMinimumValue(TreeNode* root) 
    {
        int min_val = root->val;
        long ans = LONG_MAX;
        
        find(root, min_val, ans);
        
        return ans < LONG_MAX ? ans : -1;
    }
};
