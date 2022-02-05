class Solution {
public:
    
    // 2D array for dp
    int dp[100][100];
    
    // top to bottom approach
    int rec(int m, int n)
    {
        // base case
        if( m==0 || n==0)
            return 1;
        
        // if we have already calculated the value then return that
        if(dp[m][n]!=-1)
            return dp[m][n];
        
        // recusion
        int ans = rec(m-1,n) + rec(m,n-1);
        
        // store the value before returing the value
        return dp[m][n] = ans;
        
    }
    
    int uniquePaths(int m, int n) 
    {
        // initialize the 2D array 
        for(int i=0 ;i<100 ; i++)
        {
            for(int j=0 ; j<100 ;j++)
                dp[i][j]=-1;
        }
        
        // call the function
        int ans = rec(m-1 , n-1);
        
        // return result
        return ans;
    }
};
