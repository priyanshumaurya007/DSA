class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        // we neglect first 2 digit , whether same or different
        if( nums.size() < 3)
            return nums.size();
        
        // value will change in position i 
        int i = 2;
        
        // start checking from position i 
        for(int j = i; j<nums.size() ; j++)
        {
            // if values are different , substitute the value 
            if( nums[j] != nums[i-2])
                nums[i++] = nums[j];
            
        }
        
        // return the last position of i
        return i;
    }
};
