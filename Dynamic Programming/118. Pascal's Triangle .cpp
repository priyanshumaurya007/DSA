class Solution {
public:
    
    vector<vector<int>> generate(int numRows) 
    {
        // to store the result
        int arr[numRows][numRows];
        
        // column 1
        for(int i=0;i<numRows;i++)
            arr[i][0] = 1;
        
        // diagnonal element
        for(int i=0; i<numRows; i++)
        {
            for(int j=0 ; j<numRows ;j++)
            {
                if(i==j)
                    arr[i][j] = 1;
            }
        }
        
        // calculate 
        for(int i=2; i<numRows ;i++)
        {
            for(int j=1 ; j<i ;j++)
            {
                arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
            }
        }
        
        // storing to result
        vector<vector<int>> res;
        
        for(int i=0 ;i<numRows ;i++)
        {
            vector<int> v;
            for(int j=0 ; j<=i ;j++)
            {
                v.push_back(arr[i][j]);
            }
            res.push_back(v);
        }
        
        return res;
    }
};
