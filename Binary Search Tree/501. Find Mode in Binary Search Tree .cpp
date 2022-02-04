class Solution {
public:
    vector<int> findMode(TreeNode* root) 
    {
        // if tree is empty
        if(root==NULL)
            return {};
        
        // normal bfs and push the count of value in map
        queue<TreeNode*> q;
        q.push(root);
        unordered_map<int,int> mp;
        
        while(!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();
            
            mp[curr->val]++;
            
            if(curr->left)
                q.push(curr->left);
            
            if(curr->right)
                q.push(curr->right);
        }
        
        // to store result
        vector<int> res;
        
        // value that occurs max time
        int max_val = 0;
        
        for(auto itr = mp.begin() ; itr!=mp.end() ; itr++)
            max_val = max( max_val , itr->second);
        
        // push the max occur element
        for(auto itr=mp.begin(); itr!=mp.end() ; itr++)
        {
            if( max_val == itr->second)
                res.push_back(itr->first);
        }
        
        // return result
        return res;
    }
};
