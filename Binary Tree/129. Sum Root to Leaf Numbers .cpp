class Solution {
public:
    
    // global variable to store result
    int res = 0;
    
    // helper function
    void sumNumber(TreeNode *root, int sum)
    {
        // if root is NULL
        if( !root )
            return ;
        
        // if root is leaf 
        if( !root->left && !root->right)
        {
            int temp = sum;
            temp = ( sum*10 ) + root->val;
            res += temp;
        }
        
        // otherwise add current node , recursion
        int temp = sum;
        // for backtracking, not changing the value of sum
        temp = (sum*10) + root->val;
        
        // recursion 
        sumNumber(root->left, temp);
        sumNumber(root->right, temp);
    }
    
    int sumNumbers(TreeNode* root) 
    {
        // pass to helper function
        sumNumber(root , 0);
        return res;
        
    }
};
