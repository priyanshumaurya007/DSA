class Solution {
public:
    int minSwaps(string s) 
    {
        // stack to store brackets for comparing 
        stack<char> st;
        
        for(int i=0 ; i<s.size() ; i++)
        {
            // if open brackets come
            
            if( s[i] == '[')
                st.push(s[i]);
            
            // if close bracket comes and stack is not empty
            
            else if( !st.empty() && st.top() == '[')
                st.pop();
            
            // if close bracket comes and stack is empty
            
            else
                st.push(']');
        }
        
        // every two brackets needs 1 swap , so checking half value
        
        int x = st.size()/2;
        
        return ( x+1 ) / 2;
    }
};
