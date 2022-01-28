class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        stack<int> s;
        int n = nums2.size();
        unordered_map<int,int> mp;
        
        for(int i=n-1 ;i>=0 ;i--)
        {
            while( !s.empty() && s.top() < nums2[i] )
                s.pop();
            
            if(!s.empty())
            {
                mp[nums2[i]] = s.top();
                s.push(nums2[i]);
            }
            else
            {
                mp[nums2[i]]=-1;
                s.push(nums2[i]);
            }
        }
        
        vector<int> res;
        for( auto itr : nums1)
        {
            res.push_back(mp[itr]);
        }
        
        return res;
        
    }
};
