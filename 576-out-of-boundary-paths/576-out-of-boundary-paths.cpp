class Solution {
public:
    int dp[55][55][55];
    int mod = 1e9 + 7;
    int solve(int n, int m,int maxMove,int sr,int sc)
    {
        if(sr<0 or sc<0 or sr>=n or sc>=m)
            return 1;
        
        if(maxMove==0)
            return 0;
        
        if(dp[sr][sc][maxMove]!=-1)
            return dp[sr][sc][maxMove];
        
        int ans = 0;
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1}; 
        for(int k = 0;k<4;k++)
        {
            int nx = sr + dx[k];
            int ny = sc + dy[k];
            ans = (ans%mod + solve(n,m,maxMove-1,nx,ny)%mod)%mod;
        }
        
        return dp[sr][sc][maxMove] = (ans%mod);
    }
    
    int findPaths(int n, int m, int maxMove, int sr, int sc) {
        memset(dp,-1,sizeof(dp));
        return solve(n,m,maxMove,sr,sc);
    }
};