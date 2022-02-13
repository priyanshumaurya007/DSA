class Solution {
public:
    
    // to store the result
    vector<vector<int>> res;
    
    // helper function
    void makeSubsets(vector<int> &nums, vector<int> &v , int index, const int &size)
    {
        // if we reach to the size
        if(index >= size)
        {
            res.push_back(v);
            return ;
        }
        
        // add that element
        v.push_back(nums[index]);
        
        // recursion
        makeSubsets(nums, v, index + 1 , size);
        
        // backtrack , remove that element
        v.pop_back();
        
        makeSubsets(nums, v, index + 1, size);
    }
    
    
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<int> v;
        
        makeSubsets(nums, v , 0 , nums.size());
        
        return res;
        
    }
};
