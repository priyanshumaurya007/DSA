class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        // to find the word in O(1)time
        unordered_set<string> dict;
        for(auto str : wordList)
        {
            dict.insert(str);
        }
        
        // if end word doesn't exist
        if(dict.find(endWord) == dict.end())
            return 0;
        
        // to do bfs
        queue<pair<string,int>> q;
        
        // push befin word on level 1 
        q.push({beginWord,1});
        
        // normal bfs
        while(!q.empty())
        {
            auto f = q.front();
            
            string str = f.first;
            int level = f.second;
            
            q.pop();
            
            // change every letter of a word to make combination
            for(int i=0 ; i<str.size() ; i++)
            {
                for( char c='a' ; c<='z' ; c++)
                {
                    string temp = str;
                    temp[i] = c;
                    
                    if(temp == endWord)
                        return level+1;
                    
                    if(dict.find(temp) != dict.end() && temp!=str )
                    {
                        q.push({temp, level+1});
                        dict.erase(temp);
                    }
                }
            }
        }
        
        return 0;
        
    }
};
