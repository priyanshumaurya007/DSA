class Solution {
public:
    
    // normal linear search function
    int find(vector<int> &preorder, int start, int end, int x)
    {
        while( start<=end && preorder[start] <x )
            start++;
        
        return start;
    }
    
    TreeNode *bstFromPreorder(vector<int> &preorder, int start, int end)
    {
        // if we reach end of preoder , return NULL
        if( start > end)
            return NULL;
        
        // make new node 
        TreeNode *newnode = new TreeNode(preorder[start]);
        
        // if range is complete, return node
        if( start == end )
            return newnode;
       
        // find the index, to make left and right
        int index = find(preorder, start+1 , end , newnode->val);
        
        // recusion to left
        newnode->left = bstFromPreorder(preorder, start+1, index-1);
        
        // recursion to right
        newnode->right = bstFromPreorder(preorder, index , end);
        return newnode;
        
    
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) 
    {
        return bstFromPreorder(preorder, 0 , preorder.size()-1);
        
    }
};
