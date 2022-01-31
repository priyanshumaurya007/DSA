class Solution {
public:
    
    // global 2d array to store result
    vector< vector<int> > res;
    
    // helper function 
    void pathSum(TreeNode *root, int targetSum , vector<int> &v)
    {
        // if root is NULL 
        if( !root )
            return ;
        
        // if we reached to leaf node and get the targetsum
        if( !root->left && !root->right && targetSum == root->val)
        {
            // push the lead node
            v.push_back(root->val);
            
            // push the vector to result 
            res.push_back(v);
            
            // backtrack 
            v.pop_back();
        }
            
            
        // push the current node value to the vector
        v.push_back(root->val);
        
        // recursion to the left and right child
        pathSum(root->left, targetSum - root->val , v);
        pathSum(root->right, targetSum - root->val, v);
        
        // backtrack 
        v.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        // vector to store path
        vector<int> v;
        
        pathSum(root, targetSum , v);
        
        return res;
        
    }
};
