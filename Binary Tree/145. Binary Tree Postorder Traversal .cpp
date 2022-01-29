class Solution {
public:
    
    vector<int> res;
    
    void postorder( TreeNode *root)
    {
        
        if( root != NULL)
        {
            postorder( root->left);
            postorder( root->right);
            res.push_back( root->val );
            
        }
        
         
    }
    
    vector<int> postorderTraversal(TreeNode* root) 
    {
        // if tree doesn't contain any node
        if( root == NULL )
            return res;

        postorder( root );
        
        return res;
        
    }
};
