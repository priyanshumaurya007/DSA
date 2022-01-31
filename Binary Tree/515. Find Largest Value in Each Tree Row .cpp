class Solution {
public:
    vector<int> largestValues(TreeNode* root) 
    {
        // if root is empty return NULL
        if( root == NULL )
            return {};
        
        // vector to store the result
        vector<int> res;
        
        // queue to store nodes of same level
        queue<TreeNode*> q;
        
        q.push(root);
        
        // loop will run unitll queue gets empty
        while(!q.empty())
        {
            // max_val to track maximum value in each row
            int max_val = INT_MIN;
            int size = q.size();
            
            // loop for each level
            for(int i=0 ;i<size; i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                
                max_val = max( max_val, curr->val );
                
                if( curr->left )
                    q.push( curr->left);
                if( curr->right )
                    q.push( curr->right );
                
            }
            
            // after checking all the node of a level, push the max value in the vector
            res.push_back(max_val);
        }
        
        // return result 
        return res;
        
    }
};
