/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    TreeNode *ans = NULL;
    
    bool lowest(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // If reached the end of a branch, return false.
        if(root == NULL)
            return false;
        
        // Left Recursion. If left recursion returns true, set left = 1 else 0
        int left = lowest(root->left, p , q) ? 1 : 0;
        
        // Right Recursion
        int right = lowest(root->right, p , q) ? 1 : 0;
        
        // If the current node is one of p or q
        int mid = (root == p || root == q) ? 1 : 0;
        
        // If any two of the flags left, right or mid become True
        if( mid + left + right >= 2)
            ans = root;
        
        // Return true if any one of the three bool values is True.
        return ( mid + left + right > 0);
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        lowest(root, p , q );
        
        return ans ;
    }
};
