class Solution {
public:
    int kInversePairs(int n, int k) {
        vector <vector <int>> dp(n + 1, vector <int>(k + 1, 0));
        int mod = 1e+9 + 7;
        dp[1][0] = 1; // base case and dp[1][1] = 0;
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
			// d[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - i];
                dp[i][j] = dp[i - 1][j];
                if (j > 0) dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
                if (j >= i) dp[i][j] = (dp[i][j] - dp[i - 1][j - i] + mod) % mod;
            } 
        }
		return dp[n][k];
	}
};