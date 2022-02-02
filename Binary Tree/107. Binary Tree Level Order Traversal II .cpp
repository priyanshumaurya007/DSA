class Solution {
public:
    
    // normal bfs
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        if(!root)
            return {};
        
        // to store result
        vector<vector<int>> res;
        
        // to store level node's data
        vector<int> v;
        
        // to store next child
        queue<TreeNode*> q;
        
        q.push(root);
        
        // loop untill queue is empty
        while(!q.empty())
        {
            int size = q.size();
            
            // for all level node 
            for(int i=0 ; i<size ; i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                
                v.push_back(curr->val);
                
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            
            // push the entire level node's value and clear it
            res.push_back(v);
            v.clear();
        }
        
        // reverse the result for desired output
        reverse( res.begin(), res.end());
        
        return res;
    }
};
