class Solution {
public:
 vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> ans;
        if(n==0)
            return ans;
        
        int max=1;
        vector<int> dp(n+1,1);
        sort(nums.begin(),nums.end());
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0 and 1 + dp[j]>dp[i])
                {
                    dp[i]=dp[j]+1;
                    if(dp[i]>max)
                        max=dp[i];
                }
            }
        }
        
        //Tracing back the solution
        int prev=-1;
        for(int i=n-1;i>=0;i--)
        {
            if(dp[i]==max and (prev==-1 || prev%nums[i]==0))
            {
                ans.push_back(nums[i]);
                prev=nums[i];
                max-=1;
            }
        }
         
        return ans;
    }
};