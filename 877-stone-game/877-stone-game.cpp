class Solution {
public:
    //Method 1: Even Size -> Therefore always be a winner as Alice > Bob stones in total
    // bool stoneGame(vector<int>& piles) {
    //    return true; 
    // }
    
    //Method 2: Implementation: DP Memoization
    int help(vector<int> &piles, int start, int end, vector<vector<int>> &dp)
    {
        if(start>end)
            return 0;
        if(dp[start][end]!=-1)
            return dp[start][end];
        
        int l1 = piles[start] + min(help(piles, start+2, end, dp), help(piles, start+1, end-1, dp));
        int r1 = piles[end] + min(help(piles, start+1, end-1, dp), help(piles, start, end-2, dp));
        
        return dp[start][end]=max(l1,r1);
    }
    bool stoneGame(vector<int>& piles) {
       int total=0,Alice=0, Bob=0;
        int n = piles.size();
        for(auto x: piles)
            total += x;
    
     vector<vector<int>> dp(n, vector<int> (n,-1));
     Alice = help(piles, 0, n-1, dp);
     Bob = total - Alice;
     return Alice>Bob;
    }
};