// 1 method 

class Solution {
public:
    int dp[205][205];
    
    int rec(vector<vector<int>> &grid, int n, int m)
    {
        // if we reach to first row and column
        if( n==0 && m==0)
            return grid[0][0];
        
        // out of range 
        if( n<0 || m<0)
            return INT_MAX;
        
        // already found
        if(dp[n][m] != INT_MAX)
            return dp[n][m];
        
        // rec
        int left = rec(grid, n, m-1);
        int top = rec(grid,n-1, m);
        
        // store and return
        return dp[n][m] = min(left, top) + grid[n][m];
    }
    
    int minPathSum(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0 ;i<205 ; i++)
            for(int j=0 ; j<205 ;j++)
                dp[i][j] = INT_MAX;
        
        
        return rec(grid, n-1 , m-1);
        
    }
};


// 2nd method

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dp(n, vector<int>(m, grid[0][0]));
        
        // first column cummulative sum
        for(int i=1; i<n ;i++)
            dp[i][0] = dp[i-1][0] + grid[i][0];
        
        // first row cummulative sum
        for(int j=1 ; j<m ; j++)
            dp[0][j] = dp[0][j-1] + grid[0][j];
        
        
        // check for minimum and make cummulative sum
        for(int i=1 ; i<n ;i++)
        {
            for(int j=1; j<m ;j++)
            {
                dp[i][j] = min(dp[i-1][j] , dp[i][j-1]) + grid[i][j];
            }
        }
        
        // return the result
        return dp[n-1][m-1];
    }
};

