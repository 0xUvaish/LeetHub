class Solution {
public:
    int dp[502][502];
    int solve(vector<int>& arr, int i, int j)
    {
        if(i+1 == j)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int res = 0; 
        for(int k = i+1; k<=j-1; k++)
        {
            int temp = solve(arr, i, k) + solve(arr, k, j) + arr[i]*arr[k]*arr[j];
            res = max(res, temp);
        }
        return dp[i][j] = res;
    }
    
    int maxCoins(vector<int>& nums) 
    {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, n-1);
    }
};