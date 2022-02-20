class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) 
    {
        // store the size
        int n = intervals.size();
        
        // if there are no pair, then return 0
        if( n == 0)
            return 0;
        
        // sort the intervals to check complete overlapping
        sort(intervals.begin(), intervals.end());
        
        int count = 1;
        vector<int> temp = intervals[0];
        
        // check for every pair
        for( auto itr : intervals)
        {
            // if there is no complete overlapping then increase the count
            if(itr[0] > temp[0] && itr[1] > temp[1])
                count++;
            
            // last element of pair is overlapping, assign itr to temp
            if(itr[1] > temp[1])
                temp = itr;
        }
        
        // return the count
        return count;
    }
};
