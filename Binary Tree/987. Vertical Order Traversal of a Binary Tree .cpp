class Solution {
public:
    
    // compare for sorting of second values
    static bool compare( pair<int, int> &a , pair<int ,int> &b)
    {
        if( a.first != b.first )
            return a.first < b.first;
        
        return a.second < b.second ;
    }
    
    // helping functions
    void verticalTraversal(TreeNode *root, int x, int y, map< int, vector<pair<int, int>>> &mp)
    {
        // if root is NULL 
        if(root == NULL)
            return ;
        
        
        // inorder traversal
        
        // go to left , column value decrease
        verticalTraversal(root->left, x+1 , y-1 , mp);
        
        // push the value              
        mp[y].push_back({x, root->val});
        
        // go to right , column value increase
        verticalTraversal(root->right, x+1 , y+1 , mp);
        
        
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        // if tree doesn't have nodes
        if(!root)
            return {};
        
        // 2d vector to store result
        vector<vector<int>> res;
        
        // map to store vertical node , pair for x and y
        map<int , vector<pair<int, int>>> mp;
        
        verticalTraversal(root , 0 , 0, mp);
        
        
        // pushing value in 2d vector
        for( auto x : mp )
        {
            sort( x.second.begin() , x.second.end() , compare);
            vector<int> v;
            
            for( auto y : x.second)
            {
                v.push_back(y.second);
            }
            
            res.push_back(v);
        }
    
        return res;
        
    }
};
