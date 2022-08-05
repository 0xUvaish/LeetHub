class Solution {
public:
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    int n,m;
    const int MOD = 1e9+7;
    int dp[1010][1010];
    
    int rec(int x, int y, vector<vector<int>>&g)
    {
        if(dp[x][y]!=-1) 
            return dp[x][y];
        
        int ans = 1;
        for(int i=0; i<4; i++)
        {
            int xx = x+dx[i], yy = y+dy[i];
            if(xx<0 || yy<0 || xx>=n || yy>=m || g[xx][yy]<=g[x][y]) 
                continue;
            
            ans = ans + rec(xx,yy,g)%MOD;
            ans %= MOD;
        }
        return dp[x][y]=ans;
    }
    
    int countPaths(vector<vector<int>>& grid) 
    {
        n = grid.size(), m = grid[0].size();
        for(int i=0; i<=n; i++)
            for(int j=0; j<=m; j++)
                dp[i][j]=-1;
        
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                ans = ans + rec(i,j,grid);
                ans %= MOD;
            }
        }
        return ans;
        
    }
};