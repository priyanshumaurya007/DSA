class Solution {
public:
    int openLock(vector<string>& deadends, string target) 
    {
        // to track the elements
        unordered_set<string> invalid, visited;
        
        for(auto str : deadends)
            invalid.insert(str);
        
        // making to check level
        queue<pair<string,int>> q;
        
        string starting = "0000";
        
        // in start is in dead case
        if(invalid.find(starting) != invalid.end())
            return -1;
        
        q.push({starting,0});
        
        // normal bfs 
        while(!q.empty())
        {
            auto f = q.front();
            q.pop();
            
            string str = f.first;
            int level = f.second;
            
            // if we reach to the target
            if(str == target)
                return level;
            
            // change all 4 digit with all combination
            for(int i=0 ;i<4 ;i++)
            {
                string temp = str;
                
                // addition part
                if(str[i] == '9')
                    temp[i] = '0';
                else
                    temp[i] += 1;
                
                // if new combo is not visited till yet and also not a dead end
                if(visited.find(temp) == visited.end()  && invalid.find(temp) == invalid.end())
                {
                    q.push({temp,level+1});
                    visited.insert(temp);
                }
                
                temp = str;
                
                // subtraction part
                if(str[i] == '0')
                    temp[i] = '9';
                else
                    temp[i] -= 1;
                
                // if new combo is not visited till yet and also not a dead end
                if(visited.find(temp) == visited.end()  && invalid.find(temp) == invalid.end())
                {
                    q.push({temp,level+1});
                    visited.insert(temp);
                }
            }
            
        }
        
        // not able to find the combo
        return -1;
        
    }
};
