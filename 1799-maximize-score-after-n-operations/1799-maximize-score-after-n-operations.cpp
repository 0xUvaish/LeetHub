class Solution {
public:
    
    vector<int> nums;
    int sz;
    int dp[(int)1e5 + 1][8];
    int solve(int mask, int count) {
        if(mask == ((1 << sz) - 1)) {
            return 0;
        }
        if(dp[mask][count] != -1) {
            return dp[mask][count];
        }
        int ans = 0;
        for(int i = 0; i < sz; i++) {
            for(int j = i + 1; j < sz && ((mask & (1 << i)) == 0); j++) {
                if((mask & (1 << j)) == 0) {
                    int newMask = (mask | (1 << i)) | (1 << j);
                    ans = max(ans, count * (__gcd(nums[i], nums[j])) + solve(newMask, count + 1));
                }
            }
        }
        return dp[mask][count] = ans;
    }

    int maxScore(vector<int>& nums) {
        this->nums = nums;
        this->sz = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 1);
    }
};