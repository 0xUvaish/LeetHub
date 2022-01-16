class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n < 3)
            return 0;
        int d = nums[1] - nums[0];
        int dp[n];
        dp[0] = 1;
        dp[1] = 2;
        int ret = 0;
        for(int i=2;i<n;i++)
        {
            if(nums[i] == nums[i-1] + d)
                dp[i] = dp[i-1]+1;
            else
            {
                d = nums[i] - nums[i-1];
                dp[i] = 2;
            }
            
            if(dp[i] > 2)
                ret += (dp[i]-3+1);
        }
        return ret; 
    }
};