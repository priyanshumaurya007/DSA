class Solution {
public:
    vector<int> rightSideView(TreeNode* root) 
    {
        // if Tree doesn't contain anything
        if( root == NULL)
            return {};
        
        // for storing result
        vector<int> res;
        
        // queue for nodes at one level
        queue<TreeNode*> q;
        
        // push first node
        q.push(root);
        
        // run the loop till queue doesn't get empty
        while( !q.empty() )
        {
            // take size to check all the nodes at one level
            int size = q.size();
            
            for(int i=0 ; i<size ; i++)
            {
                // pop front node from queue
                TreeNode *curr = q.front();
                q.pop();
                
                // push last node of every level 
                if( i == size-1 )
                    res.push_back(curr->val);
                
                // push its children 
                if( curr->left)
                    q.push(curr->left );
                if( curr->right )
                    q.push( curr->right );
                    
            }
        }
        
        return res;
        
    }
};
