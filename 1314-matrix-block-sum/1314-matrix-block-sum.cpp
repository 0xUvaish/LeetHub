class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {

        int m=mat.size();
        int n=mat[0].size();
        
        vector<vector<int>> dp(m+1,vector<int> (n+1,0));
        
        for (int i = 1; i < dp.size(); i++)
            for (int j = 1; j < dp[0].size(); j++)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + mat[i - 1][j - 1] - dp[i - 1][j - 1];
        
        
        //the result vector we are going to return
        vector<vector<int>> ans(m,vector<int>(n,0));
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {

                int r1=max(0,i-k)+1; //starting row coordinate of the block
                int c1=max(0,j-k)+1; //starting column coordinate of the block
                int r2= min(i+k+1,m); //ending row coordinate of the block
                int c2= min(j+k+1,n); // ending column coordinate of the block
                
                ans[i][j]=dp[r2][c2]+dp[r1-1][c1-1]-dp[r1-1][c2]-dp[r2][c1-1]; //value of the block calculated with the dp vector built
                
            }
        }
      return ans;  
    }
};