class Solution {
public:
    
    // bottom up approach 
    int numTrees(int n) 
    {
        // dp
        vector<int> dp(n+1, 0);
        
        dp[0] = dp[1] = 1;
        
        // dp[2] = c0*c2 + c1*c1 + c2*c0
        for(int i=2; i<=n ; i++)
        {
            for(int j=0 ; j<i ; j++)
            {
                dp[i] += dp[j] * dp[i-j-1];
            }
        }
        
        return dp[n];
        
    }
};
