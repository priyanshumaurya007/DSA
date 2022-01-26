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
            // if open brackets comes
            
            if(isopen(s[i]))
            {
                st.push(s[i]);
            }
            
            // if closed brackets comes and stack is not empty
            
            else if( !st.empty() )
            {
                
                if(!ismatching(st.top(),s[i]))
                    return false;
                else
                    st.pop();
                    
            }
            
            // when closed bracket comes and stack is empty
            
            else
                return false;
        }
        
        // is stack is empty then return true otherwise return false
        
        return (st.empty());
    }
};
