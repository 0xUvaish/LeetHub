class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        int dp[n+1][k+1];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k;j++){
                int ans=0, sum=0;
                dp[i][j] = dp[i-1][j];
                for(int p=1;p <= min(j,(int)piles[i-1].size());p++){
                    sum += piles[i-1][p-1];
                    dp[i][j] = max(dp[i][j], sum + dp[i-1][j-p]);
                }

            }
        }
        return dp[n][k];
    }
};