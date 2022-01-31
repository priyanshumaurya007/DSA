class Solution {
public:
    int maxLevelSum(TreeNode* root) 
    {
        // if root is empty , return 0
        if( root == NULL )
            return 0;
        
        // to store max sum level
        int max_level = INT_MIN;
        
        // to store max sum till now on any level
        int max_sum = INT_MIN;
        
        // to check on which level we are
        int level = 1;
        
        // to store all nodes of ant level
        queue<TreeNode*> q;
        
        q.push(root);
        
        // loop will run untill queue fets empty
        while( !q.empty()) 
        {
            // to store sum of each level
            int sum = 0;
            
            int size = q.size();
            
            // loop for all nodes of a level
            for(int i=0; i<size; i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                
                sum += curr->val;
                
                if( curr->left )
                    q.push( curr->left );
                if( curr->right )
                    q.push( curr-> right );
            }
            
            // if sum of current level is max, then apply the changes
            if( sum > max_sum)
            {
                max_sum = sum;
                max_level = level;
            }
            
            // going to next level
            level++;
        }
        
        // return the result
        return max_level;
    }
};
