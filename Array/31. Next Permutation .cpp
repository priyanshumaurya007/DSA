class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        // check from last
        int i = nums.size() - 2;
        
        // check from right and find first pair ( less, greater)
        while(i>=0 && nums[i] >= nums[i+1] )
            i--;
        
        // find first element from right which is greater than nums[i]
        if(i>=0)
        {
            int j = nums.size() - 1;
            
            while(nums[j] <= nums[i])
                j--;
            
            // swap with that place
            swap(nums[i],nums[j]);
        }
        
        // reverse the remaining last array
        reverse(nums.begin()+i+1 , nums.end());
    }
};
