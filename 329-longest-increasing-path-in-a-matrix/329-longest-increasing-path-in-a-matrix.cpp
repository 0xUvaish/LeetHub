class Solution {
public:
    vector<vector<int>> dp;
    int n,m;
    vector<vector<int>> directions={{0,1},{0,-1},{1,0},{-1,0}};
    
    int dfs(vector<vector<int>>& matrix,int i,int j)
    {
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int ans=0;
        for(auto x:directions)
        {
            int ii=i+x[0];
            int jj=j+x[1];
            if(ii<0 or ii>=n or jj<0 or jj>=m) 
                continue;
            
            if(matrix[ii][jj]>matrix[i][j])
                ans=max(ans,dfs(matrix,ii,jj));
        }
        
        return dp[i][j]=ans+1;
        
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {
        n=matrix.size();
        m=matrix[0].size();
        
        dp.resize(n,vector<int>(m,-1));
        int ans=0;
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(dp[i][j]==-1)
                    ans=max(ans,dfs(matrix,i,j));
        
        return ans;
        
    }
};