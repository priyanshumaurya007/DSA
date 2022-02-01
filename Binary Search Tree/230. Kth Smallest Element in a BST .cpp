class Solution {
public:
    
    //helper function
    void kthSmallest(TreeNode* root, int &k, int &ans)
    {
        // return null is root doesn't exist
        if( !root )
            return;
        
        // recursion to left
        kthSmallest(root->left, k, ans);
        
        // already find first min node , so k-1
        k--;
        
        // return the kth minimum node
        if(k == 0)
            ans = root->val;
        
        // recursion to the right after finding left node
        kthSmallest(root->right, k, ans);
    }
    
    int kthSmallest(TreeNode* root, int k) 
    {
        // result to store ans
        int ans = 0;
        
        kthSmallest(root, k ,ans);
        
        return ans;
        
    }
};
