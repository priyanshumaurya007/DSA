class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        // store the result
        vector<vector<int>> res;
        
        // if size of nums is less than 3, it means we can't create the triplets
        if( nums.size() < 3)
        {
            return res;
        }
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0 ; i < nums.size()-2 ; i++)
        {
             // skip all continous same element, doing bcz to avoid duplicate triplets
            if(i == 0 || nums[i-1] != nums[i])
            {
                // two pointer's approach
                // a + b + c = 0, so we can make the equation like
                // b + c = -a;
                // low + high = -sum;
                
                int low = i + 1;
                int high = nums.size() - 1;
                int sum = -nums[i];
                
                while(low < high)
                {
                    if(nums[low] + nums[high] == sum)
                    {
                        // add triplet into the result
                        res.push_back({nums[i], nums[low], nums[high]});
                        
                        // skip all continous same element, doing bcz to avoid duplicate triplets
                        while(low<high && nums[low] == nums[low+1])
                            low++;
                        
                        // skip all continous same element, doing bcz to avoid duplicate triplets
                        while(low<high && nums[high-1] == nums[high])
                            high--;
                        
                        low++;
                        high--;
                    }
                    // if total is less than sum, move left pointer forward
                    else if(nums[low] + nums[high] < sum)
                        low++;
                    // if total is greater than sum, move right pointer backward
                    else
                        high--;
                }
            }
        }
        // return the result
        return res;
    }
};
