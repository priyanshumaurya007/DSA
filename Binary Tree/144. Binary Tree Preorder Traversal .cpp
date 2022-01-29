class Solution {
public:
    vector<int> res;
    
    void preorder( TreeNode *root)
    {
        // Push data
        res.push_back( root->val );
        
        // if left exist, so go to left 
        if(root->left)
        preorder( root->left);
        
        // if left exist, so go to right
        if(root->right)
        preorder( root->right);
        
        
    }
    
    vector<int> preorderTraversal(TreeNode* root) 
    {
        // if tree doesn't contain any node
        if( root == NULL )
            return res;
        
        preorder( root );
        
        return res;
        
    }
};
