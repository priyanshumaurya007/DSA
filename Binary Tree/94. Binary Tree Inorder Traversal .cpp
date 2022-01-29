class Solution {
public:
    
    vector<int> res;
    
    void inorder( TreeNode *root)
    {
        
        // if left exist, so go to left 
        if(root->left)
        inorder( root->left);
        
        // Push data
        res.push_back( root->val );
        
        // if left exist, so go to right
        if(root->right)
        inorder( root->right);
         
    }
    
    vector<int> inorderTraversal(TreeNode* root) 
    {
        // if root doesn't contain any node
        
        if ( root == NULL )
            return {};
        
        inorder( root );
        
        return res;
        
    }
};
