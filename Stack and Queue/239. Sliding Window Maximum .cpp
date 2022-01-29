class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        int n = nums.size();
        
        vector<int> ans;
        
        deque<int> dq;
        
        for(int i=0;i<n;i++)
        {
            
            // we remove front element if it is extra
            
            if( !dq.empty() && dq.front() == i-k )
                dq.pop_front();
            
            // we remove back element untill it is smaller than current nums value
                
            while( !dq.empty() && nums[i] > nums[dq.back()] )
            {
                dq.pop_back();
            }
            
            // push the index of current value 
            
            dq.push_back(i);
            
            if( i>=k-1)
                ans.push_back(nums[dq.front()]);
        }    
        
        
        return ans;
    }
};
