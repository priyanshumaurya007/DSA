class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) 
    {
        // store preprocess data
        map<int, int > mp;
        
        // store sum of nums3 and nums4
        for( int k : nums3)
            for(int l : nums4)
                mp[k+l]++;
        
        // count to store numbers of tuples
        int count = 0;
        
        // add first two array sums , and check same in map with negative
        for(int i : nums1)
            for( int j : nums2)
                count += mp[-(i+j)];
        
        
        return count;
        
    }
};
