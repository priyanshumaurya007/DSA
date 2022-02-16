/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void flatten(TreeNode* root)
    {
        if(root == NULL)
            return ;
        
        // recursion 
        flatten(root->left);
        flatten(root->right);
        
        // change the right node and mark left as NULL
        TreeNode *temp = root->right;
        root->right = root->left;
        root->left = NULL;
        
        // go to the last node of right 
        while(root->right)
            root = root->right;
        
        // join the right node with temp node
        root->right = temp;
    }
};
