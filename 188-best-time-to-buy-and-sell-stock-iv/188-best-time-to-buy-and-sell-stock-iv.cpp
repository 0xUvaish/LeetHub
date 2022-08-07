class Solution {
public:
    int dp[1001][101][2];
    int solve(int k, vector<int>& prices, int pos, bool hold){
        if(pos>=prices.size()) return 0;
        if(dp[pos][k][hold]!=-1) return dp[pos][k][hold];
        int sell=0, notsell=0, buy=0, notbuy=0;
        if(!hold and k) buy = solve(k-1,prices,pos+1,!hold) - prices[pos];
        notbuy = solve(k,prices,pos+1,hold);
        if(hold) sell = solve(k,prices,pos+1,!hold) + prices[pos];
        notsell = solve(k,prices,pos+1,hold);
        return dp[pos][k][hold] = max({buy,sell,notbuy,notsell});
    }
    
    int maxProfit(int k, vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return solve(k,prices,0,false);
    }
};