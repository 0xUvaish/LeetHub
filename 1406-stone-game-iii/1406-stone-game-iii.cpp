class Solution {
    vector<int> dp;
public:
    int maxdiff(vector<int> &vals, int i)
    {
        if(i >= vals.size())
            return 0;
        
        if(dp[i]!=INT_MIN) 
            return dp[i];
        
        int total=0;
        
        for (auto j = 0; j < 3; j++)
        {
            if(i+j < vals.size()) 
            {
             total += vals[i+j];   
             dp[i] = max(dp[i], total - maxdiff(vals, i + j + 1));
            }
        }
        return dp[i];
    }
    
    string stoneGameIII(vector<int>& vals)
    {
        
        dp.resize(vals.size()+1,INT_MIN);
        int ans = maxdiff(vals,0);
        
        return ans == 0 ? "Tie" : ans > 0 ? "Alice" : "Bob";
   }
};