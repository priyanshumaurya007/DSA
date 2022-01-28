class Solution {
public:
    
    // to find small elements to the next left
    
    vector<int> nextSmallerElementToLeft(vector<int> &heights)
    {
        int len = heights.size();
        stack<int> s;
        vector<int> nsl(len);
        
        for(int i=0 ; i<len ; i++)
        {
            while( !s.empty() && heights[s.top()] >= heights[i] )
                s.pop();
            
            nsl[i] = (s.empty()? -1 : s.top());
            s.push(i);
        }
        
        return nsl;
        
    }
    
    // to find the smaller element to the right
    
    vector<int> nextSmallerElementToRight(vector<int> &heights)
    {
        int len = heights.size();
        stack<int> s;
        vector<int> nsr(len);
        
        for(int i=len-1 ; i>=0 ; i--)
        {
            while( !s.empty() && heights[s.top()] >= heights[i] )
                s.pop();
            
            nsr[i] = (s.empty()? len : s.top());
            s.push(i);
        }
        
        return nsr;
        
    }
    
    // main function to calculate the max area
    
    int largestRectangleArea(vector<int>& heights) 
    {
        vector<int> left = nextSmallerElementToLeft(heights);
        vector<int> right = nextSmallerElementToRight(heights);
        int maxarea = 0;
        
        for(int i=0 ;i<heights.size(); i++)
        {
            int j = left[i];
            int k = right[i];
            int width = k-j-1;
            
            maxarea = max( maxarea, width*heights[i]);
        }
        
        return maxarea;
        
    }
};
