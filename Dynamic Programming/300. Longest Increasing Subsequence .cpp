class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        // total size of nums
        int n = nums.size();
        
        // declare the vector
        vector<int> dp(n+1, 1);
        
        // to store max len
        int maxlen = 1;
        
        // for particular value
        for(int i=1 ;i<n ; i++)
        {
            // check all the values before i 
            for(int j=0 ; j<i ;j++)
            {
                // if true
                if(nums[j] < nums[i])
                {
                    dp[i] = max(dp[i] , 1 + dp[j]);
                    maxlen = max( maxlen , dp[i]);
                }
            }
        }
        
        // return the max len 
        return maxlen;
    }
};
