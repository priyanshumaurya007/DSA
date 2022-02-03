class Solution {
public:
    // global variable for index of newnode
    int in=0;
    
    // function to return index of node value in inorder
    int find(vector<int> &inorder, int start , int end , int val)
    {
        // linear search 
        for( int i=start ; i<=end ;i++)
        {
            if(inorder[i]==val)
                return i;
        }
        
        return 0;
    }
    
    // helper function 
    TreeNode* buildTree(vector<int> &preorder,vector<int> &inorder, int low , int high )
    {
        // node aftee leaf node
        if(low > high)
            return NULL;
        
        // make new node
        TreeNode *newnode = new TreeNode(preorder[in++]);
      
        // if leaf node 
        if( low == high )
            return newnode;
        
        // find index in inorder to seperate left and right
        int index = find(inorder , low , high , newnode->val);
        
        // recursion left node
        newnode->left = buildTree(preorder, inorder, low , index-1);
        
        // recursion right node
        newnode->right = buildTree(preorder, inorder, index+1, high );
        
        // return curr node
        return newnode;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        // size of preorder / inorder
        int size = preorder.size()-1;
        // calling helper function
        return buildTree(preorder, inorder , 0 , size);
        
    }
};
