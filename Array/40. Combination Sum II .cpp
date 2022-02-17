class Solution {
    
    // taking global variables to store data
    vector<vector<int>> res;
    vector<int> v;
    int n, T;
    
    // helper function
    void dfs(int idx, int currTotal, vector<int>& currList) 
    {
        // if we reach to the target, push into the result
        if(currTotal == T) {
            res.push_back(currList);
            return;
        }
        
        // out of range
        if(idx >= n || currTotal > T)
            return;
        
        // recursion
        currList.push_back(v[idx]);
        dfs(idx + 1, currTotal + v[idx], currList);
        
        // back tracking
        currList.pop_back();
        
        // skip duplicates element
        while(idx + 1 < n && v[idx + 1] == v[idx]) ++idx;
        
        dfs(idx + 1, currTotal, currList);
    }
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        // sort the arr
        sort(candidates.begin(), candidates.end());
        vector<int> currList;
        
        // assign values to global variables
        v = candidates, n = v.size(), T = target;
        
        // calling helper function
        dfs(0, 0, currList);
        return res;
    }
};
