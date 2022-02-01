class Solution {
public:
    
    // inorder traversal
    void inorder(TreeNode *root,vector<int> &v )
    {
        if( !root )
            return ;
        
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
        
    }
    
    bool isValidBST(TreeNode* root) 
    {
        // to store inorder values
        vector<int> v;
     
        inorder(root, v);
        
        // to check the increasing order 
        for(int i=1 ;i<v.size() ;i++)
        {
            if(v[i]<=v[i-1])
                return false;
        }
        
        return true;
    }
};
