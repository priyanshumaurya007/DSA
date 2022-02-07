class Solution {
public:
    char findTheDifference(string s, string t) 
    {
        // map to store the frequency of letter of first string
        map<char,int> mp;
        
        // stroing of first string
        for(auto ch : s)
            mp[ch]++;
        
        // check in second string
        for(auto ch : t)
        {
            // if letter doesn't found
            if(mp[ch] == 0)
                return ch;
            
            mp[ch]--;
        }
        
        return ' ';
        
    }
};
