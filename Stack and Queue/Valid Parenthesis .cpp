class Solution {
public:
    
    // isopen function
    
    bool isopen(char ch)
    {
        return ( ch == '(') || ( ch == '{') || ( ch == '['); 
        
    }
    
    // matching function
    
    bool ismatching( char open, char close)
    {
        return ( (  open == '{' ) && ( close == '}') || 
                 (  open == '(' ) && ( close == ')') || 
                 (  open == '[' ) && ( close == ']') );
    }
    
    bool isValid(string s) 
    {
        // nothing is in string
        
        if(s.size() == 0 )
            return true;
        
        // if size of string is odd
        
        if(s.size() & 1)
            return false;
        
        stack<char> st;
        
        for(int i=0;i<s.size();i++)
        {
            if(isopen(s[i]))
            {
                st.push(s[i]);
            }
            else if( !st.empty() )
            {
                if(!ismatching(st.top(),s[i]))
                    return false;
                else
                    st.pop();
                    
            }
            else
                return false;
        }
        
        return (st.empty());
    }
};
