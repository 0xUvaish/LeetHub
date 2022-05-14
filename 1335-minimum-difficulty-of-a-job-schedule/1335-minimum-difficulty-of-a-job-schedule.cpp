#define ll long long
class Solution 
{
public:
    ll dp[301][11];
    int func(vector<int> &nums, int d, int i)
    {
       int n=nums.size();
       if(d==1)
       {
           int maxe=0;
           
           for(int idx=i;idx<n;idx++)
               maxe=max(maxe , nums[idx]);
           
           return maxe;
       }
        
        if(dp[i][d]!=-1)
            return dp[i][d];
        
        int ans=INT_MAX;
        int mx=0;
        
        for(int k=i; k<(n-d+1); k++)
        {
            mx=max(mx, nums[k]);
            
            int temp=func(nums, d-1, k+1);
            ans = min(ans, mx+temp);
        }
        
        return dp[i][d]=ans;
    }
    int minDifficulty(vector<int>& nums, int d) 
    {
        memset(dp, -1,  sizeof(dp));
        if(nums.size()<d)
            return -1;
        
        return func(nums, d, 0);
    }
};