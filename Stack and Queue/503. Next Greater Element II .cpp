class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        // stack to store greater element from right to left 
        
        stack<int> s;
        int n = nums.size();
        vector<int> nge(n);
        
        // since circular array , so we need to store elements from right to left 
        
        for(int i=n-1 ; i>=0 ; i--)
        {
            // pop all the element which are less or equal to the nums[i]
            
            while(!s.empty() && nums[s.top()] <= nums[i])
                s.pop();
            
            s.push(i);
        }
        
        // normal checking from right to left like we do in normal array
        
        for( int i=n-1 ; i>=0 ; i--)
        {
            // pop all the element which are less or equal to the nums[i]
            
            while(!s.empty() && nums[s.top()] <= nums[i] )
                s.pop();
           
            // if stack becomes empty so no greater element to its right
            
            if(s.empty())
                nge[i] = -1;
            
            // push max element into ans vector
            
            else
            {
                nge[i] = nums[s.top()];
            }
            s.push(i);
                
        }
        
        return nge;
        
    }
};
