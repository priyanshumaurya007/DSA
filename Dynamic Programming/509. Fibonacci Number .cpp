class Solution {
public:
    
    int dp[35];
    
    int calFib( int n )
    {
        // base
        if( n==0 || n==1 )
            return n;
        
        // if we have already calculated the result , return that result
        if(dp[n]!=-1)
            return dp[n];
        
        //recursion
        int res = calFib(n-2) + calFib(n-1);
        
        // return the result
        return dp[n] = res;
    }
    
    int fib(int n) 
    {
        for(int i=0 ;i<35;i++)
            dp[i] = -1;
        
        int ans = calFib(n);
        
        return ans;
    }
};
