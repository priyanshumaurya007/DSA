class Solution {
public:
    
    int orangesRotting(vector<vector<int>>& grid) 
    {
        // to store the sequence
        queue<pair<pair<int,int>, int >> q;
        
        int fresh0 = 0 , ans = 0 ,count = 0;
        
        // check for fresh and insert all rotten in queue
        for(int i=0 ; i<grid.size() ; i++)
        {
            for(int j=0 ;j<grid[0].size() ; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({{i,j},0});
                }
                else if(grid[i][j] == 1)
                    fresh0++;
            }
        }
        
        // all 4 direction
        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};
        
        // normal bfs
        while(!q.empty())
        {
            int size = q.size();
            
            auto f = q.front();
            q.pop();
                
            int i = f.first.first;
            int j = f.first.second;
            int level = f.second;
            
            ans = max(ans,level);
            
            for( int k=0 ;k<4 ;k++)
            {
                int x = i + dx[k];
                int y = j + dy[k];
                
                // if safe, make it rotten in next level
                if(x>=0 && y>=0 && x<grid.size() && y<grid[0].size() && grid[x][y] == 1)
                {
                    count++;
                    grid[x][y] = 2;
                    q.push({{x,y},level+1});
                }
            }
            
        }
        
        // if all the fresh become rotten
        return fresh0 == count ? ans:-1;
    }
};
