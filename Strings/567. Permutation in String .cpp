class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        //size of both string
        int m = s1.size();
        int n = s2.size();
        
        // if s1 size is greater than s2 size
        if(m > n)
            return false;
        
        // vector to store frequency of letter in a string
        vector <int> mp1(26,0) , mp2(26,0);
        
        // store frequncy of size s1
        for(int i=0 ;i<m ;i++)
        {
            mp1[s1[i]-'a']++;
            mp2[s2[i]-'a']++;
        }
        
        // if both vector are same
        if(mp1 == mp2)
            return true;
        
        // checking in s1 size window
        for(int i=1 ;i < n-m+1 ; i++)
        {
            // decrease the freq 
            mp2[s2[i-1]-'a']--;
            // increase the freq of current letter
            mp2[s2[i+m-1]-'a']++;
            
            // if both vector are same
            if(mp1 == mp2)
                return true;
        }
        
        // otherwise false
        return false;
    }
};
