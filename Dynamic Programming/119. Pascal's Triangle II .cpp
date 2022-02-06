class Solution {
public:
    vector<int> getRow(int rowIndex) 
    {
        // total number of pattern we need to make
        int n = rowIndex+1;
        
        // to store the pattern
        int dp[n][n];
        
        // make first column element value 1
        for(int i=0; i<n ;i++)
            dp[i][0] = 1;
        
        // all diagonal value is 1
        for(int i=0 ;i<n; i++)
            for(int j=0 ; j<n ; j++)
                if(i==j)
                    dp[i][j] = 1;
        
        // process to make the pattern
        for(int i=2 ; i<n ;i++)
            for(int j=1 ;j<i ;j++)
                dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
        
        // store the result
        vector<int> res;
      
        // push the element of that row only
        for(int j=0 ; j<rowIndex+1 ; j++ )
            res.push_back(dp[rowIndex][j]);
        
        // return the result
        return res;
        
    }
};
