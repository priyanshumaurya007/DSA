class Solution {
public:
    
    // direction in all 8 direction
    int dx[8] = {-1,-1,1,1,-2,-2,2,2};
    int dy[8] = {-2,2,2,-2,-1,1,-1,1};
    
    double dp[55][55][105];
    
    // top to bottom approach
    double rec(int n, int move ,int i, int j)
    {
        
        //base case
        if(i<0 || j<0 || i>=n || j>=n)
            return 0.0;
        
        // base case
        if(move == 0)
            return 1.0;
        
        // if we have already calculated the value then return that result
        if(dp[i][j][move] != -1)
            return dp[i][j][move];
        
        double ans = 0.0;
        
        // recusion and backtrack
        for(int k=0 ;k<8 ;k++)
        {
            int x = i + dx[k];
            int y = j + dy[k];
            
            ans = ans + rec(n , move-1 , x , y)/8.0;
        }
        
        // store and return 
        return dp[i][j][move] = ans;
    }
    
    double knightProbability(int n, int k, int row, int column) 
    {
        // initializing the dp
        for(int i=0 ;i<55 ;i++)
            for(int j=0 ;j<55 ;j++)
                for(int k=0 ;k<105; k++)
                    dp[i][j][k] = -1.0;
        
        double ans = rec(n, k ,row, column);
        
        return ans;
    }
};
