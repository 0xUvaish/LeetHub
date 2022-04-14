class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target)
    {
        int sum = 0;
        for(auto it : nums)
        {
            sum += it;
        }
        if((target + sum)%2 || abs(target)>sum )
            return 0;
        
         int S = (sum + target)/2;
         int N = nums.size() ;
         int dp[N+1][S+1];
        
         for(int j = 0 ; j <=S ; j++)
           dp[0][j] = 0;
        
       for(int i = 0; i <=N ; i++)
           dp[i][0] = 1;
        
       for(int i = 1 ; i <= N ; i++)
       {
           for(int j = 0 ; j <= S ; j++)
           {
               if(nums[i-1] <= j)
                   dp[i][j] = dp[i-1][j - nums[i-1]] + dp[i-1][j];
               else
                   dp[i][j] = dp[i-1][j];
           }
       }
        
       return dp[N][S];
    }
};