class Solution {
public:
  int dp[1001];
    
    int solve(vector<int>& nums, int target)
    {
        if(target==0)
            return 1;
        else if(target < 0)
            return 0;
        
        if(dp[target] != -1)
            return dp[target];
        
        int ans = 0;
        for(int it : nums)
            ans += solve(nums, target-it);
        
        return dp[target] = ans;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        
        memset(dp, -1, sizeof(dp));
        return solve(nums, target);
    }
};