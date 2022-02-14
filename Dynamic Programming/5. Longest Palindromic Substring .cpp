class Solution {
public:
    string longestPalindrome(string s) 
    {
        // take the size
        int n = s.size();
        
        // if string have one or less character
        if( n<=1)
            return s;
        
        // to store max len and string that is palindromic
        int maxlen = 0;
        string str = "";
        
        // dp
        int dp[n][n];
        
        // mark all diagonals as character to itself is palindrome
        for(int i=0 ;i<n ;i++)
            for(int j=0 ; j<n ;j++)
            {
                if(i==j)
                {
                    dp[i][j] = 1;
                    str = s[i];
                }
                else
                    dp[i][j] = 0;
            }
        
        // check window wise
        for(int window = 2 ; window <= n ; window++)
        {
            for(int i=0 ; i< n-window+1 ;i++)
            {
                int j = i + window - 1;
                
                // if window is of 2 size then maxlen will become the window size
                if(window == 2)
                {
                    if(s[i] == s[j])
                    {
                        dp[i][j] = window;
                        if( maxlen < window)
                        {
                            maxlen = window;
                            str = s.substr(i, window);
                        }
                        
                    }
                }
                // otherwise check for in between substring 
                else
                {
                    if(s[i] == s[j] && dp[i+1][j-1] > 0 )
                    {
                        dp[i][j] = window;
                        if( maxlen < window)
                        {
                            maxlen = window;
                            str = s.substr(i, window);
                        }
                        
                    }
                    
                }
            }
        }
         
        // return the string
        return str;
        
    }
};
