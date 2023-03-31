class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        const int mod = 1e9+7;
        int dp[60][60]; std::fill(&dp[0][0], &dp[0][0] + 60*60, 0);
        int presum[60][60]; std::fill(&presum[0][0], &presum[0][0] + 60*60, 0);
        int m = pizza.size(), n = pizza[0].size();

        for (int i = m; i; --i) {
            for (int j = n; j; --j) {
                presum[i][j] = (pizza[i-1][j-1] == 'A') + presum[i+1][j] + presum[i][j+1] - presum[i+1][j+1];

                dp[i][j] = (presum[i][j] != 0);
            }
        }

        for (int p = 2; p <= k; ++p) {
            for (int i = 1; i <= m; ++i) {
                for (int j = 1; j <= n; ++j) {
                    dp[i][j] = 0;
                    for (int c = i+1; c <= m; ++c) {
                        if (presum[i][j] - presum[c][j] > 0) {
                            dp[i][j] = (dp[i][j] + dp[c][j]) % mod; dp[i][j] = (dp[i][j] + mod) % mod; 
                        }
                    }
                    
                    for (int c = j+1; c <= n; ++c) { 
                        if (presum[i][j] - presum[i][c] > 0) {
                            dp[i][j] = (dp[i][j] + dp[i][c]) % mod; dp[i][j] = (dp[i][j] + mod) % mod; 
                        }
                    }
                }
            }
        }

        return dp[1][1];
    }
};