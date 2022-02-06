class Solution {
public:
    // to store previous calculated data
    int dp[40];
    
    int rec(int n)
    {
        // base case
        if( n== 0)
            return 0;
        
        if( n==1 || n==2)
            return 1;
        
        // if we have already calculated the value , return that value
        if(dp[n]!=-1)
            return dp[n];
        
        // recursion
        int ans = rec(n-1) + rec(n-2) + rec(n-3);
        
        // return the recursion result 
        return dp[n] = ans;
    }
        
    int tribonacci(int n) 
    {
        // initialize the dp 
        for(int i=0 ;i<40 ;i++)
            dp[i] = -1;
        
        int ans = rec(n);
        
        return ans;
        
    }
};
