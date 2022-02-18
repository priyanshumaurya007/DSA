class Solution {
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        //so that I need not to go backward to check
        sort(nums.begin() , nums.end());
        
        int n = nums.size();
        
        // check the values in range
        for(int i=0 ; i<n ; i++)
        {
            if(nums[i]>0 && nums[i]<=n)
            {
                nums[nums[i]-1] = nums[i];
            }
        }
        
        // check which is not in place
        for(int i=0 ; i<n ; i++)
        {
            // not in place return 
            if(nums[i] != i+1)
                return i+1;
        }
        
        // otherwise return last value
        return n+1;
        
    }
};
