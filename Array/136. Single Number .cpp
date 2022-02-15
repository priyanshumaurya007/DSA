class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        // map
        map<int, int> mp;
        
        // put inside all the elements
        for(int i=0 ; i<nums.size() ; i++)
        {
            mp[nums[i]]++;
        }
        
        // check for frequency of 1
        for( auto x : mp)
        {
            if(x.second == 1)
            {
               return x.first;
                
            }
        }
        return 0;
    }
};
