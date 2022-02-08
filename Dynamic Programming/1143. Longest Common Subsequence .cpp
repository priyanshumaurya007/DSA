class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) 
    {
        // size to make dp
        int l1 = text1.size() , l2 = text2.size();
        
        // if any of the string is empty
        if( l1 == 0 || l2 == 0)
            return 0;
        
        // declare and initialization of dp
        vector<vector<int>> dp(l1+1, vector<int>(l2+1,0));
        
        // check for every letter combo
        for(int i=1 ;i<=l1 ;i++)
        {
            for(int j=1 ;j<=l2 ;j++)
            {
                // if letters matches take diagonal value
                if(text1[i-1] == text2[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                
                // otherwise max of left and top
                else
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        // return result
        return dp[l1][l2];
        
    }
};
