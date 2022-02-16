class Solution {
public:
    
    // top to down approach
    int rec(int low, int high, vector<vector<int>> &dp)
    {
        // out of range
        if(low > high)
            return 1;
        
        // for itself the result is 1
        if(low == high)
            return dp[low][high] = 1;
        
        // already calculated
        if(dp[low][high] != 0)
            return dp[low][high];
        
        int count = 0;
        
        // checking all combination
        for(int cut = low ; cut <= high; cut++)
        {
            int left = rec(low, cut-1 ,dp);
            int right = rec(cut+1, high ,dp);
            
            count += (left * right);
        }
        
        // store and return
        return dp[low][high] = count;
    }
    
    int numTrees(int n) 
    {
        vector<vector<int>> dp(n, vector<int>(n,0));
        return rec(0 , n-1, dp);
        
    }
};
