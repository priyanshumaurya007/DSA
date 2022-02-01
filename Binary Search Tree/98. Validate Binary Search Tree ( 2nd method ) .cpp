class Solution {
public:
    bool isValidBST(TreeNode* root , long low = LONG_MIN , long high = LONG_MAX)
    {
        // if root==NULL , return true
        if(!root)
            return true;
        
        // if root->val comes in range , recursion
        if(low < root->val && root->val < high)
            return ( isValidBST(root->left,low,root->val) && 
                               isValidBST(root->right,root->val, high) );
        
        // otherwise invalid
        else
            return false;
        
    }
};
