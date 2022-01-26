class Solution {
public:
    
    vector<vector<int>> vi;
    
    
    void rec( vector<int> v, int i, int k, int n)
    {
        if(v.size()==k)
        {
            vi.push_back(v);
            return ;
            
        }
        
        for(int j = i;j<=n ; j++)
        {
            v.push_back(j);
            rec(v, j+1, k, n);
            v.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) 
    {
        vector<int> v;
        rec( v, 1 , k, n);
        return vi;
        
    }
};
