class Solution {
public:
    int minDistance(string word1, string word2) 
    {
        // size for creating DP
        int m = word1.size() , n = word2.size();
        
        // declare and initialize the dp
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));
        
        // check for each combination
        for(int i=0 ;i<=m ;i++)
        {
            for(int j=0 ; j<=n ; j++)
            {
                // if it's a first row
                if(i==0)
                    dp[i][j] = j;
                
                // if it's a first column
                else if(j==0)
                    dp[i][j] = i;
                
                // if letter matches , take inside value
                else if(word1[i-1] == word2[j-1])
                {
                    dp[i][j] =  dp[i-1][j-1];
                    
                }
                // else min value + 1 operation
                else
                {
                    dp[i][j] = 1 + min(dp[i-1][j-1] , min(dp[i-1][j], dp[i][j-1]));
                }
            }
        }
        
        // return the result
        return dp[m][n];
        
    }
};
