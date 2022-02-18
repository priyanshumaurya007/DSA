//Logic Is Pretty Simple I have to Just Find the digit which are greater than from next one or we can say that previous digit which are greater than from next one and make it as smaller as a possible


class Solution {
public:
    string removeKdigits(string nums, int k) 
    {
        string res ="";
        
        // if operation are equal or greater
        if( k >= nums.size())
            return "0";
        
        for(int i=0 ; i < nums.size() ;i++)
        {
             //removig all those which digit which are greater than next one
            while( k && !res.empty() && res.back() > nums[i])
            {
                 k--;
                 res.pop_back();
            }
            
            // pushing all digit one by one and we should not add any zeros if res length is                  zero because, it may lead to add zeros at the front that doesn't make sense
            if( res.size() > 0 || nums[i] != '0')
                res.push_back(nums[i]);
        }
        //maybe there is no digit such that which satify the condition but we have to remove             some digt than we are removing last k digit
        
        while( !res.empty() && k)
        {
            k--;
            res.pop_back();
        }
        
        // if there is nothing in the string
        if(res.size() == 0)
            return "0";
        
        return res;
    }
};
