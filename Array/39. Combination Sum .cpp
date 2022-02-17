class Solution {
public:
    
    void solve(vector<vector<int>> &res, vector<int> &candidates, vector<int> &v, int index,                    int target)
    {
        // found the target
       if( target == 0)
       {
           res.push_back(v);
           return;
       }
        
        // out of range
        if( target < 0 || index >= candidates.size())
            return;
        
        // without including
        solve(res, candidates, v , index+1 , target);
        
        // recursion, including 
        v.push_back(candidates[index]);
        
        // to take repetition, index will be same
        solve(res, candidates, v, index, target-candidates[index]);
        
        // backtracking 
        v.pop_back();
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        // to store the result
        vector<vector<int>> res;
        
        vector<int> v;
        
        // calling helper function
        solve(res, candidates, v, 0 , target);
        
        return res;
    }
};
