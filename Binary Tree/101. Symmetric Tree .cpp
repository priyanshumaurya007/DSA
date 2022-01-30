class Solution {
public:
    
    bool isSymmetric(TreeNode *l , TreeNode *r)
    {
        // one of the node doesn't exist
        if(l==NULL || r==NULL)
            return l==r;
        
        // if value of node is same and its child value is also same
        if( l->val==r->val && 
           isSymmetric(l->left, r->right) && 
                 isSymmetric(r->left, l->right))
            return true;
        
        // otherwise return false
        return false;
    }
    
    bool isSymmetric(TreeNode* root) 
    {
        return isSymmetric( root->left , root->right );
        
    }
};
