class Solution {
public:
    
    // 2D array for dp
    int dp[105][105];
    
    // top to down approach 
    int rec(int m , int n , vector<vector<int>> &grid)
    {
        // base call
        if(m<0 || n<0)
            return 0;
        
        // if there is a obstacles, then return 0
        if( grid[m][n]==1)
            return 0;
        
        // base case
        if(m==0 && n==0)
            return 1;
        
        // if we have already calculated the result , return that result
        if(dp[m][n]!=-1)
            return dp[m][n];
        
        // recursion
        int ans = rec(m-1, n , grid) + rec(m , n-1 , grid);
        
        // store the value before returning
        return dp[m][n] = ans;
        
    }
    
    
    int uniquePathsWithObstacles(vector<vector<int>> &grid) 
    {
        // sizes
        int m = grid.size();
        int n = grid[0].size();
        
        // initialize the 2D array with -1
        for(int i=0; i<m ; i++)
            for(int j=0; j<n; j++)
                dp[i][j] = -1;
        
        // calling
        int ans = rec(m-1, n-1, grid);
        
        // return the result
        return ans;
    }
};
