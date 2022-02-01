class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(!root)
            return NULL;
        
        // if both the nodes is on the left  keep going left
        if(root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p , q);
        
        // if both the nodes are on the right keep going right
        if(root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p , q);
        
        // if above cases doesnot satisfy it means the nodes are going to split after this particular node so this is our answer, hence we return it
        return root;
        
    }
};
