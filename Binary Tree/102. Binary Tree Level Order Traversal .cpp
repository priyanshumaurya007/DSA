class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        if( root == NULL)
            return {};
        
        vector<vector<int>> res;
        vector<int> v;
        
        // to store level nodes
        queue<TreeNode*> q;
        
        q.push( root );
        q.push( NULL );
        
        // loop runs till queue gets empty
        
        while( !q.empty() )
        {
            // pop front and check for its child
            root = q.front();
            q.pop();
            
            
            // if root is NULL so we need to insert NULL in queue
            
            if( root == NULL)
            {
                res.push_back(v);
                v.clear();
                
                if( !q.empty() )
                {
                    q.push(NULL);
                    
                }
                
            }
            
            // otherwise, push its left and right child if exist
            
            else
            {
                v.push_back( root->val );
                if( root->left )
                    q.push( root->left );
                
                if( root->right )
                    q.push( root->right );
            }
            
        }
        
        // return the result
        
        return res;
    }
};
