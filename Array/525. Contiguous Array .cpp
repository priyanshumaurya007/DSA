class Solution {
public:
    
    // function
    int findMaxLength(vector<int>& nums) 
    {
        // store the seen sum with index
        unordered_map<int, int> mp{{0,-1}};
        int sum = 0, maxlen = 0;
        
        // loop 
        for(int i=0; i<nums.size(); i++)
        {
            // cal new sum
            sum += nums[i]==1 ? 1 : -1;
            
            // if key exist in mp then update
            if(mp.count(sum))
                maxlen = max(maxlen, i - mp[sum]);
            // otherwise
            else
                mp[sum]=i;
        }
        
        // return 
        return maxlen;
        
    }
};
