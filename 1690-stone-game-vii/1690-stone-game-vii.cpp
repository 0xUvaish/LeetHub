class Solution {
public:
    int dp[1005][1005];
    int solve(vector<int>&v,int i,int j,int sum)
    {
        if(i>j)
            return 0;

        else if(dp[i][j]!=-1)
            return dp[i][j];
        
        int ans=max(sum-v[i]-solve(v,i+1,j,sum-v[i]),sum-v[j]-solve(v,i,j-1,sum-v[j]));
        return dp[i][j]=ans;
    }
    
    int stoneGameVII(vector<int>& v) 
    {

        int n=v.size(),sum=0;
        for(int i=0;i<n;i++)
            sum+=v[i];
        
        memset(dp,-1,sizeof(dp));
        
        return solve(v,0,n-1,sum);
    }
};