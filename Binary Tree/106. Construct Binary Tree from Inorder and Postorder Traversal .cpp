class Solution {
public:
    
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
    TreeNode* buildTree(vector<int> &postorder,vector<int> &inorder,int low ,int high,int &in)
    {
        // node aftee leaf node
        if(low > high)
            return NULL;
        
        // make new node
        TreeNode *newnode = new TreeNode(postorder[in--]);
      
        // if leaf node 
        if( low == high )
            return newnode;
        
        // find index in inorder to seperate left and right
        int index = find(inorder , low , high , newnode->val);
        
        // recursion right node
        newnode->right = buildTree(postorder, inorder, index+1, high , in);
        
        // recursion left node
        newnode->left = buildTree(postorder, inorder, low , index-1 , in);
        
        // return curr node 
        return newnode;
    }
    
    TreeNode* buildTree(vector<int>& inorder , vector<int>& postorder) 
    {
        // size of preorder / inorder
        int size = postorder.size()-1;
        // index for making root
        int in = size;
        // calling helper function
        return buildTree(postorder, inorder , 0 , size ,in);
        
    }
};
