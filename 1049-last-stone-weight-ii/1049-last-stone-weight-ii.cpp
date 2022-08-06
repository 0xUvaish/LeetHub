class Solution {
public:
 int lastStoneWeightII(vector<int>& stones) {
        
        int sum=0;
        for(int i=0;i<stones.size();i++)
            sum+=stones[i];
        
        int n=stones.size();
        
        int dp[n+1][sum+1];
        int rs=sum;
        sum=sum/2;
     
        for(int i=0;i<=sum;i++)
            dp[0][i]=0;
     
        for(int i=0;i<=n;i++)
            dp[i][0]=1;
     
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(j>=stones[i-1])
                    dp[i][j]=dp[i-1][j] || dp[i-1][j-stones[i-1]];
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
     
        int ans=INT_MAX;     
        for(int i=0;i<=sum;i++)
            if(dp[n][i]==1)
                ans=min(ans,rs-2*i);
     
        return ans;
    }
};