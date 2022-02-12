class Solution {
public:
    
    // for res
    int count;
    
    // within grid , not visited , grid = 1
    bool issafe(vector<vector<int>> &visited, vector<vector<int>> &grid, int x, int y)
    {
        return x>=0 && x<grid.size() && y>=0 && y<grid[0].size() && visited[x][y]==0 && grid[x][y] == 1;
        
    }
    
    void dfs(vector<vector<int>> &visited, vector<vector<int>> &grid, int i, int j)
    {
        // mark the node visited
        visited[i][j] = 1;
        
        int dx[] = {-1,0,0,1};
        int dy[] = {0,-1,1,0};
    
        count++;
        
        // recursion and backtracking
        for(int k=0 ; k<4 ;k++)
        {
            int x = i + dx[k];
            int y = j + dy[k];
            
            // if safe to go next, mark this visited
            if(issafe(visited, grid, x, y))
            {
                dfs(visited,grid,x,y);
            }
        }
    }
    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        // size of row and column
        int n = grid.size();
        int m = grid[0].size();
        
        // to check visited node
        vector<vector<int>> visited(n,vector<int>(m,0));
        
        
        int res=0;
        
        for(int i=0; i<n; i++)
        {
            for(int j=0 ; j<m ;j++)
            {
                // check one by one for 1 and not visited
                if(grid[i][j]==1 && visited[i][j]==0)
                {
                    count = 0;
                    
                    // send this to mark visited
                    dfs(visited, grid, i ,j);
                    res = max(res,count);
                }
            }
        }
        
        // return result
        return res;
    }
};
