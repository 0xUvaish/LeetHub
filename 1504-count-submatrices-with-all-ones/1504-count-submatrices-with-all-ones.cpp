class Solution {
public:
    //Method 1: n^4 Brute Force
    //Method 2 : n^3 Sol Optimised
    int numSubmat(vector<vector<int>>& matrix) 
    {
        
        if(matrix.empty())  
            return 0;
        
        int m = matrix.size();
        int n = matrix[0].size(); 
        int ans = 0;
       
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; i++) 
        {            
            for (int j = 0; j < n; j++) 
            {
                if(!j || !matrix[i][j])
                    dp[i][j] = matrix[i][j];
                else 
                    dp[i][j] =  1 + dp[i][j - 1];
                          
                int width = dp[i][j];
                for(int k = i; k >= 0; k--)
                {
                    width = min(dp[k][j], width);
                    ans += width;
                }
            }
        }
        return ans;
    }
    
};