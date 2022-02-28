class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) 
    {
        // size of given array
        int n = nums.size();
        // declaring to store the result
        vector<string> res;
        
        // creating temp string to store potential result
        string str = "";
        
        for(int i=0 ;i<n; i++)
        {
            // j pointer will move and track the last index of range
            int j = i;
            
            // till its reaches last or range breaks
            while( j+1<n && nums[j+1] == nums[j]+1)
                j++;
            
            
            // if there are more than 1 elements in the range
            if(j>i)
            {
                str += to_string(nums[i]); // first element
                str += "->";
                str += to_string(nums[j]); // last element
            }
            // otherwise single element
            else
            {
                str += to_string(nums[i]);
            }
            
            //push the result and make string ready for next answer
            res.push_back(str);
            str = "";
            
            // now start of next range will from j
            i = j;
        }
        
        // return the result
        return res;
        
    }
};
