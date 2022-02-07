class Solution {
public:
    
    int mod = 1000000007;
    int dp[55][55][55];
    
    
    // top to bottom approach
    int rec(int m ,int n , int maxMove , int i , int j)
    {
        //base case
        if(i<0 || j<0 || i>=m || j>=n)
            return 1;
        
        // base case
        if(maxMove == 0)
            return 0;
        
        // if we have already calculated the value
        if(dp[i][j][maxMove] != -1)
            return dp[i][j][maxMove] % mod;
        
        // direction in all 4 direction
        int dx[] = {-1,0,0,1};
        int dy[] = {0,1,-1,0};
        
        int ans = 0;
        
        // recursion and backtrack
        for(int k=0 ;k<4 ;k++)
        {
            int x = i + dx[k];
            int y = j + dy[k];
            
            ans = ( ans % mod + rec(m , n , maxMove-1 , x , y) % mod ) % mod;
        }
        
        // store than return 
        return dp[i][j][maxMove] = ans % mod;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) 
    {
        // initializing the dp
        for(int i=0 ;i<55 ;i++)
            for(int j=0 ;j<55 ;j++)
                for(int k=0 ;k<55 ; k++)
                    dp[i][j][k] = -1;
        
        // call the rec function
        return rec( m , n , maxMove , startRow, startColumn);
        
    }
};
