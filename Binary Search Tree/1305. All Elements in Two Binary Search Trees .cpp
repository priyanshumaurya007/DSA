class Solution {
public:
    
    // normal inorder and return vecotor of inorder element
    void inorder(TreeNode* root, vector<int> &arr)
    {
        if(root==NULL)
            return ;
        
        inorder(root->left , arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }
    
    // merge 2 sorted aaray
    void mergeTwoArray( vector<int> first, vector<int> second, vector<int> &arr)
    {
        int n = first.size();
        int m = second.size();
        
        int i = 0, j = 0;
        
        while( i<n && j<m )
        {
            if(first[i] < second[j])
            {
                arr.push_back(first[i]);
                i++;
            }
            else
            {
                arr.push_back(second[j]);
                j++;
            }
        }
        
        while( i<n )
            arr.push_back(first[i++]);
        
        while(j<m)
            arr.push_back(second[j++]);
    }
    
    //  main function
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) 
    {
        // inorder elements of first
        vector<int> first;
        
        // inorder elements of second
        vector<int> second;
        
        // storing inorder elements
        inorder(root1, first);
        inorder(root2, second);
        
        //to store merge array
        vector<int> merge;
        
        // calling function to merge two array
        mergeTwoArray(first, second, merge);
        
        // return ans
        return merge;
        
    }
};
