class Solution {
public:
 int lastStoneWeightII(vector<int>& stones) {
        
        int sum=0;
        for(int i=0;i<stones.size();i++)
            sum+=stones[i];
     
        vector<int> check(sum+1,0);
        vector<int> pr;
        
        int n=stones.size();
        
        int dp[n+1][sum+1];
        int rs=sum;
        sum=sum/2;
     
        for(int i=0;i<sum+1;i++)
            dp[0][i]=0;
     
        for(int i=0;i<n+1;i++)
            dp[i][0]=1;
     
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<sum+1;j++)
            {
                if(j>=stones[i-1])
                    dp[i][j]=dp[i-1][j] || dp[i-1][j-stones[i-1]];
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
     
        for(int i=0;i<=sum;i++)
            if(dp[n][i]==1)
                pr.push_back(i);
     
        int ans=INT_MAX;
        for(int i=0;i<pr.size();i++)
            ans=min(ans,rs-2*pr[i]);
     
        return ans;
    }
};