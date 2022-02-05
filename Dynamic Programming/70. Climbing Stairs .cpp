class Solution {
public:
    
    // 1D array for dp
    int dp[47];
    
    // top to bottom approach
    int climb( int n )
    {
        // base case 
        if( n<0 )
            return 0;
        
        // base case , return will be 1
        if( n==0 || n==1)
            return 1;
        
        // if we have already calculated then return that value only
        if(dp[n]!=-1)
            return dp[n];
        
        // otherwise recusion
        int ans = climb(n-1) + climb(n-2);
        
        // put the result into dp array
        return dp[n] = ans;
    }
    
    int climbStairs(int n) 
    {
        // initialize dp with -1
        for(int i=0;i<47;i++)
            dp[i]=-1;
        
        // return result
        return climb(n);
        
        
        
    }
};
