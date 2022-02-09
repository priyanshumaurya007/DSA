class Solution {
public:
    int findPairs(vector<int>& nums, int k) 
    {
        // to store all the values
        map<int,int> mp;
        
        for( auto &x : nums)
            mp[x]++;
        
        int count = 0;
        
        // loop in map
        for(auto &x : mp)
        {
            // decrement the count so that it doesn't count itself
            x.second--;
            
            if(mp.find(x.first+k) != mp.end() && mp[x.first+k]>=1)
                count++;
            
            // undo the decrement
            x.second++;
        
        }
        
        // return count
        return count;
    }
};
