class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        // store first element and count becomes one
        int num = nums[0];
        int count = 1;
        
        // check for next possible answer
        for(int i=1; i<nums.size() ;i++)
        {
            if(nums[i] == num)
            {
                count++;
            }
            else
            {
                count--;
            }
            
            if(count<0)
            {
                count = 1;
                num = nums[i];
            }
        }
        
        return num;
        
    }
};
