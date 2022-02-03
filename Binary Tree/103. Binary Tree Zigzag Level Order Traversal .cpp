class Solution {
public:
    
    // normal level order traversal bfs
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        // if tree does not contain any node
        if(root==NULL)
            return {};
        
        // queue to store level nodes
        queue<TreeNode*> q;
        // vector to store level nodes value 
        vector<vector<int>> res;
        
        q.push(root);
        
        // flag to check odd or even level
        bool flag = false;
        
        while(!q.empty())
        {
            vector<int> v;
            int size = q.size();
            
            // push all the node values in vector
            for(int i = 0 ;i<size; i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                
                v.push_back(curr->val);
                
                if(curr->left)
                    q.push(curr->left);
                
                if(curr->right)
                    q.push(curr->right);
                
            }
            
            // if odf level , reverse the vector
            if(flag)
                reverse(v.begin() , v.end());
            
            // flip the value of flag
            flag = !flag;
            
            res.push_back(v);
        }
        
        // return the result
        return res;
    }
};
