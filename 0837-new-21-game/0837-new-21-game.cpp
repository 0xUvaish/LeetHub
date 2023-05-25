class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k == 0) return 1.;
        vector<double> dp (n+1, 0.);
        dp[0] = 1.;
        double winsum = 1.;
        for (int i = 1; i <= n; i+=1) {
            dp[i] = winsum / maxPts;
            if (i < k) winsum += dp[i]; // the game is over,  we can't draw any card, can not use it for dp[i+1]
            if (i >= maxPts && i - maxPts < k) winsum -= dp[i-maxPts];
        }
        double ans = 0;
        for (int i = k; i <= n; i+=1) ans += dp[i];
        return ans;
    }
};