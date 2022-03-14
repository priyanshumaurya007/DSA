class Solution {
public:
    string simplifyPath(string path) 
    {
        // to store directories
        stack<string> st;
        
        // if last char is not /
        int n = path.size();
        if(path[n-1]!='/')
        {
            n++;
            path += '/';
        }
        
        // ans for result , temp for temporary result
        string temp = "";
        string ans = "";
        
        for(int i=1 ; i<n ;i++)
        {
            // if '/' comes, we basically need to ignore
            if(path[i] == '/')
            {
                // if this comes , ignore it 
                if(temp == "" || temp == ".")
                {
                    //ignore   
                }
                // go to previous directory
                else if(temp == "..")
                {
                    if(!st.empty())
                        st.pop();
                }
                // put it into stack
                else
                {
                    st.push(temp);
                }
                
                temp = "";
                
            }
            // otherwise, store into temp
            else
            {
                temp += path[i];
            }
        }
        
        
        // put all directory into ans with '/'
        while(!st.empty())
        {
            ans = '/' + st.top() + ans;
            st.pop();
        }
        
        // if ans is empty
        if(ans == "")
            ans += '/';
        
        // return the ans 
        return ans;
    }
};
