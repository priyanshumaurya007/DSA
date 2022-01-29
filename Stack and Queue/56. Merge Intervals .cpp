class Solution {
public:
    
    // comparator to sort the values according to first value ( optional )
    
    static bool comparator( vector<int> &a, vector<int> &b)
    {
        if( a[0] < b[0] )
            return true;
        else if ( a[0] == b[0] )
            return a[1] < b[1];
        else
            return false;
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        int n = intervals.size();
        
        sort( intervals.begin() , intervals.end() , comparator);
        
        // 2D vector for result
        
        vector<vector<int>> ans;
        
        // insert first range in temp
        
        vector<int> temp = intervals[0];
        
        for( auto itr : intervals)
        {
            // if overlap happens this update the second value of last 
            
            if(temp[1] >= itr[0])
                temp[1] = max( temp[1] , itr[1]);
            
            // otherwise, push the result in ans , update temp with next range
            
            else
            {
                ans.push_back(temp);
                temp = itr;
            }
        }
        
        
        ans.push_back(temp);
        
        return ans;
    }
};
