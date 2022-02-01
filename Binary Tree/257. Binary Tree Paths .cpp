class Solution {
public:
    
    // vector to store result
    vector<string> res;
    
    // helper function
    void preorder(TreeNode *root, string str)
    {
        // if root is NULL then return nothing
        if( root == NULL)
            return ;
        
        // push the current node value and append in the str
        string s = to_string(root->val);
        str.append(s);
        
        // if it is a leaf node 
        if( root->right==NULL && root->left==NULL )
        {
            res.push_back(str);
        }
        
        // recursion
        str.append("->");
        preorder( root->left, str);
        preorder( root->right, str);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        string str;
        preorder(root, str);
        return res;
        
    }
};
