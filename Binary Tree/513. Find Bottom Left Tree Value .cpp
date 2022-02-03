class Solution {
public:
    int findBottomLeftValue(TreeNode* root) 
    {
        // to store level value at each node
        int left_val = root->val;
        
        // store node of each level
        queue<TreeNode*> q;
        
        q.push(root);
        
        // loop runs untill queue gets empty
        while(!q.empty())
        {
            int size = q.size();
            
            // loop for each level
            for(int i=0 ;i<size ;i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                
                // left most value of a level
                if(i==0)
                    left_val = curr->val;
                
                // recursion
                if( curr->left )
                    q.push(curr->left);
                
                if( curr->right )
                    q.push(curr->right);
            }
        }
        
        // return the left bottom value
        return left_val;
    }
};
