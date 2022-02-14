class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int n = height.size();
        int maxarea = 0;
        
        // 2 pointer approach
        int i = 0 , j = n - 1;
        
        // untill i is less than j
        while(i < j)
        {
            // calculate the distance between them i.e. breadth
            int distance =  j - i;
            
            // minimum height to trap the water
            int minheight = min(height[i] , height[j]);
            
            maxarea = max(maxarea, distance * minheight);
            
            // increase decrease the pointer which have short height to trap maximum water
            if(height[i] < height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        
        // return max area
        return maxarea;
    }
};
