class Solution {
public:
    
    // normal dfs
    void dfs(vector<vector<int>> &isConnected, vector<int> &visited, int i)
    {
        // mark visited
        visited[i] = 1;
        
        // check for its connected node
        for(int j=0 ; j < isConnected.size() ; j++)
        {
            // if not visited and connected also
            if( visited[j] == 0 && isConnected[i][j] == 1)
            {
                dfs(isConnected, visited, j);
            }
        }
    } 
    
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int n = isConnected.size();
        int count = 0;
        
        // to mark visited
        vector<int> visited(n,0);
        
        //  mark all the node as visited if not
        for(int i=0 ; i<n; i++)
        {
            if(visited[i] == 0)
            {
                dfs(isConnected, visited, i);
                count++;
            }
        }
        
        // return total number of times we went to mark visited
        return count;
    }
};
