class Solution {
public:
    
    //helper function
    void findGoodNodes(TreeNode *root, int max_val , int &count)
    {
        // base, if root is null
        if(root==NULL)
            return ;
        
        // root is greater than max till now
        if( root->val >= max_val)
        {
            count++;
        }
        
        // recursion and bactrack
        findGoodNodes(root->left , max(max_val, root->val) , count);
        findGoodNodes(root->right, max(max_val, root->val) , count);
    }
    
    
    int goodNodes(TreeNode* root) 
    {
        if( root == NULL)
            return -1;
        
        // to store the total paths 
        int count = 0;
        int min_val = INT_MIN;
        
        findGoodNodes( root , min_val, count);
        
        return count;
        
    }
};
