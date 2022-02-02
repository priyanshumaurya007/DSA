class Solution {
public:
    
    // helper function
    TreeNode *sortedArrayToBST(vector<int> &nums, int start, int end)
    {
        // if end of range is reached
        if(start > end)
            return NULL;
        
        // cal middle element
        int mid = start + (end-start)/2;
        
        // make node of middle value
        TreeNode *newnode = new TreeNode(nums[mid]);
        
        // if it is only one node
        if(start==end)
            return newnode;
        
        // recusrion 
        newnode->left = sortedArrayToBST(nums, start , mid-1);
        newnode->right = sortedArrayToBST(nums, mid+1 ,end);
        
        // return node
        return newnode;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        // cal to helper function
        return sortedArrayToBST(nums, 0 ,nums.size()-1);
        
    }
};
