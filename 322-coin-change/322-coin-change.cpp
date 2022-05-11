class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
         int n = coins.size();
        vector<vector<int>> dp(amount+1, vector<int>(n+1,INT_MAX-1));
        for(int i=0; i<=amount; i++)
        {
            for(int j=0; j<=n; j++)
            {
                if(i==0)
                    dp[i][j] = 0;
                
                else if(j==0)
                    dp[i][j] = INT_MAX-1;

                else if(coins[j-1] > i)
                    dp[i][j] = dp[i][j-1];
                
                else
                    dp[i][j] = min(dp[i-coins[j-1]][j]+1,dp[i][j-1]);
                
            }
        }
        return (dp[amount][n] == INT_MAX-1) ? -1 : dp[amount][n]; 
    }
};