class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) 
    {
        // store the result
        int res = 0;
        
        // if there are no people 
        if(people.size() == 0)
            return res;
        
        // sort the input
        sort(people.begin(), people.end());
        
        int n = people.size();
        
        int low = 0 , high = n-1;
        
        while(low <=  high)
        {   
            // check for light and heavy weighted person if true then send both of them 
            if(people[low] + people[high] <= limit)
            {
                res++;
                low++;
                high--;
            }
            // otherwise send heavy weighted person
            else if(people[low] + people[high] > limit)
            {
                res++;
                high--;
                
            }
        }
        
        // return total count of boats
        return res;
        
        
    }
};
